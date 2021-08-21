#pragma once
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
	std::filesystem::create_directories(head_dir);
}