#pragma once
#include <experimental/filesystem>
#include <filesystem>

bool firstLaunch = false;

bool isFirstLaunch()
{
	std::experimental::filesystem::path firstAccess("C:/Users/" + SfmlAPI::getSystemUser() + "/AppData/Local/Snake/src/firstAccess.confirm");
	if (!std::experimental::filesystem::exists(firstAccess))
	{
		std::ofstream out(firstAccess);
		out << "not first access";
		out.close();
		firstLaunch = true;
	}
	return firstLaunch;
}

void createDirs()
{
	std::experimental::filesystem::create_directories("C:/Users/" + SfmlAPI::getSystemUser() + "/AppData/Local/Snake/img/heads");
}