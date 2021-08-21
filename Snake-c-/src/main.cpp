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
	while(!SavedData::initData()) {
		LOG_F(WARNING, "Initializing app data");
		std::thread initThread(initializeGame);
		initThread.join();
	}

	net::Connection* connect = new net::Connection;

	std::thread main_window_thread(main_window, connect);
	LOG_F(INFO, "Hehehehehehehehehehehehehe");

	main_window_thread.join();
	return 0;
}
