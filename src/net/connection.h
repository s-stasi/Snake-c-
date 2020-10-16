#pragma once
#include "../Points.h"
#include <SFML/Network.hpp>
#include <iostream>
#include <sstream>

namespace net
{
	class Connection
	{
	public:
		Connection();
		~Connection();

		void sendScore(Points &points, const std::string& name);
		void newUser(std::string& name);
		void getList(std::string & name);
		void checkExixt(std::string& name);

	private:
		bool sendRequest();

	private:
		std::ostringstream m_reqParameters;
		sf::Http::Request m_request;
		sf::Http m_http;
		sf::Http::Response m_response;
	};
}