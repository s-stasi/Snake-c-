#include "Connection.h"

namespace net
{
	Connection::Connection()
	{
		m_request.setUri("/snake/index.php");
		m_request.setMethod(sf::Http::Request::Method::Post);
		m_http.setHost("snake.esamistasi.altervista.org");
	}


	Connection::~Connection()
	{
	}

	void Connection::sendScore(int points, const std::string& name)
	{
		m_reqParameters.clear();
		m_reqParameters << "action=update" << "&uname=" << name << "&points=" << points;
		m_request.setBody(m_reqParameters.str());
		this->sendRequest();

	}

	void Connection::newUser(std::string & name)
	{
		m_reqParameters.clear();
		m_reqParameters << "action=create_new&" << "uname=" << name << "&points='0'";
		m_request.setBody(m_reqParameters.str());
		this->sendRequest();
	}

	void Connection::getList()
	{
		m_reqParameters.clear();
		m_reqParameters << "action=get_list&" << "uname=''"<< "&points=0";
		m_request.setBody(m_reqParameters.str());
		this->sendRequest();
	}

	void Connection::checkExixt(std::string & name)
	{
		m_reqParameters.clear();
		m_reqParameters << "action=check_exixt&" << "uname=" << name << "&score=0";
		m_request.setBody(m_reqParameters.str());
		this->sendRequest();
	}

	bool Connection::sendRequest()
	{
		m_response = m_http.sendRequest(m_request);

		if (m_response.getStatus() == sf::Http::Response::Ok)
		{
			std::cout << "[CONNECTION STATUS]: " << m_response.getStatus() << std::endl;
			std::cout << "[CONNECTION BODY]: " << m_response.getBody() << std::endl;
			m_response = sf::Http::Response();
			return true;
		}
		else
		{
			std::cout << "[CONNECTION ERROR]: " << m_response.getBody() << std::endl;
			std::cout << "[CONNECTION ERROR]: " << m_response.getStatus() << std::endl;
			m_response = sf::Http::Response();
			return false;
		}
	}

}