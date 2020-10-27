#pragma once
#include <experimental/filesystem>
#include <filesystem>
#include "jsonParser/SavedData.h"

bool isFirstLaunch()
{
	if (SavedData::Data::firstLaunch)
	{
		SavedData::setFirstLaunch(false);
		return true;
	}
	else
		return false;
}

void createDirs()
{
	std::experimental::filesystem::create_directories(head_dir);
}