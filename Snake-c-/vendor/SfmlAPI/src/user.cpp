#include "../include/user.hpp"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <windows.h>
#include <Lmcons.h>

namespace SfmlAPI {

	std::string getSystemUser()
	{
		TCHAR name[UNLEN];
		DWORD size = UNLEN + 1;
		GetUserName((TCHAR*)name, &size);
		std::string uname = name;
		for (size_t i = 0; i < uname.length(); i++)
		{
			if (uname[i] == '\n' && uname[i + 1] == '\n' && uname[i + 1] <= (int)uname.length())
			{
				uname.erase(i, 1);
			}
		}
		return std::string(name);
	}
}

#elif defined(unix) || (__unix) || (__unix__)
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

std::string getSystemUser()
{
	register struct passwd *pw;
	register uid_t uid;
	int c;

	uid = geteuid();
	pw = getpwuid(uid);
	if (pw)
	{
		return std::string(pw->pw_name);
	}
	return std::string("");
}

#else
#   error "Unsupported Plattform"
#endif

