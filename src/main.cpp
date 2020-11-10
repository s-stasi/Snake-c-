#include <thread>
#include <fstream>
#include <iostream>
#include <SFML/OpenGL.hpp>
#include <loguru.hpp>

#include <SfmlAPI.hpp>

#include "jsonParser/SavedData.h"
#include "net/Connection.h"
#include "user.h"
#include "strings.h"
#include "gameThread.h"


int main()
{
	if (SavedData::initData())
		LOG_F(INFO, "Initialized data");
	else
		LOG_F(ERROR, "Failed to initialize data");

	net::Connection* connect = new net::Connection;

	std::thread main_window_thread(main_window, connect);

	if (isFirstLaunch())
	{
		std::thread user_thread(setUser);
		user_thread.join();
	}

	main_window_thread.join();
	return 0;
}
