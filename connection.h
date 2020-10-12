#pragma once
#include "Points.h"
#include <SFML/Network.hpp>
#include <iostream>
#include <sstream>

class Connection
{
public:
	Connection();
	~Connection();

	void sendScore(Points &points, const std::string& name);
	void newUser(std::string& name);
	void getList(std::string & name);
	void checkExixt(std::string& name);
};