#include <thread>
#include "net/Connection.h"
#include "xmlParser/XmlParser.h"
#include "SfmlAPI.hpp"
#include "snake.h"
#include "strings.h"
#include <die-xml\SaxParser.h>


int main()
{
	XmlParser as;
	XmlParser az;
	XmlParser ar;
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