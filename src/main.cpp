#include <thread>
#include <fstream>
#include <iostream>

#include <SfmlAPI.hpp>

#include "jsonParser/SavedData.h"
#include "net/Connection.h"
#include "strings.h"
#include "snake.h"


int main()
{
	if (!SavedData::initData())
		std::cout << "Failed to initialize some settings" << std::endl;

	std::cout << "maxScore: " << SavedData::Data::bestScore << std::endl;
	net::Connection* connect = new net::Connection;
	std::thread snake_thread(snake, connect);
	if (isFirstLaunch())
	{
		std::thread user_thread(setUser);
		user_thread.join();
	}
	snake_thread.join();
	return 0;
}
