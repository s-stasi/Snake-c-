#include <thread>
#include "net/Connection.h"
#include "SfmlAPI.hpp"
#include "snake.h"

int main()
{
	net::Connection* connect = new net::Connection;
	connect->getList(std::string("miiinghia"));

	std::thread snake_thread(snake, connect);


	if (isFirstLaunch())
	{
		std::thread user_thread(setUser);
		user_thread.join();
	}

	snake_thread.join();

	return 0;
}