#include "Connection.h"



Connection::Connection()
{
}


Connection::~Connection()
{
}


void Connection::sendScore(int score, const std::string& name)
{
	sf::Http::Request request("/index.php", sf::Http::Request::Post);

	std::ostringstream stream;
	stream << "action=update&" << "uname=" << name << "&score=" << score;
	request.setBody(stream.str());

	sf::Http http("http://snake.esamistasi.altervista.org/snake/");
	sf::Http::Response response = http.sendRequest(request);

	if (response.getStatus() == sf::Http::Response::Ok)
	{
		std::cout << response.getBody() << std::endl;
	}
	else
	{
		std::cout << "request failed" << std::endl;
	}
}

void Connection::newUser(std::string & name)
{
	sf::Http::Request request("/snake/index.php", sf::Http::Request::Post);

	std::ostringstream stream;
	stream << "action=create_new&" << "uname=" << name << "&points='0'";
	request.setBody(stream.str());

	sf::Http http("snake.esamistasi.altervista.org");
	sf::Http::Response response = http.sendRequest(request);

	if (response.getStatus() == sf::Http::Response::Ok)
	{
		std::cout << response.getBody() << std::endl;
		std::cout << response.getStatus() << std::endl;
	}
	else
	{
		std::cout << "request failed" << std::endl;
	}
}

void Connection::getList(std::string & name)
{
	sf::Http::Request request("/index.php", sf::Http::Request::Post);

	std::ostringstream stream;
	stream << "action=get_list&" << "uname=" << name << "&score=0";
	request.setBody(stream.str());

	sf::Http http("http://snake.esamistasi.altervista.org/snake/");
	sf::Http::Response response = http.sendRequest(request);

	if (response.getStatus() == sf::Http::Response::Ok)
	{
		std::cout << response.getBody() << std::endl;
	}
	else
	{
		std::cout << "request failed" << std::endl;
	}
}

void Connection::checkExixt(std::string & name)
{
	sf::Http::Request request("/index.php", sf::Http::Request::Post);

	std::ostringstream stream;
	stream << "action=check_exixt&" << "uname=" << name << "&score=0";
	request.setBody(stream.str());

	sf::Http http("http://snake.esamistasi.altervista.org/snake/");
	sf::Http::Response response = http.sendRequest(request);

	if (response.getStatus() == sf::Http::Response::Ok)
	{
		std::cout << response.getBody() << std::endl;
	}
	else
	{
		std::cout << "request failed" << std::endl;
	}
}
