#include <iostream>
#include "XmlParser.h"



XmlParser::XmlParser()
{
	instances++;
	std::cout << instances << std::endl;
}


XmlParser::~XmlParser()
{
}


int XmlParser::instances = 0;