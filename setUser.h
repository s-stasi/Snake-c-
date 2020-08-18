#pragma once
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <filesystem>

bool isFirstLaunch()
{
	std::cout << "non va niente" << std::endl;
	std::experimental::filesystem::path firstAccess("src\\firstAccess.confirm");
	if (!std::experimental::filesystem::exists(firstAccess))
	{
		std::cout << "vero" << std::endl;
		std::ofstream out(firstAccess);
		out << "not first access";
		out.close();
		return true;
	}
	else
	{
		std::cout << "falso" << std::endl;
		return false;
	}
}

bool setUser()
{

}