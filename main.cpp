#include "dependencies.h"


int main()
{
	std::thread snake_thread(snake);

	while (!isGameWindowOpen)
	{ }

	Connection* connect = new Connection;
	connect->newUser((std::string)"bellalui");

	if (isFirstLaunch())
	{
		std::thread user_thread(setUser);
		user_thread.join();
	}

	snake_thread.join();

	return 0;
}