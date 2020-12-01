#include "SavedData.h"


bool SavedData::initData()
{
	if (m_instances == 0 || m_parse == false)
	{
		m_instances++;
		std::ifstream ifs("C:/Users/" + SfmlAPI::getSystemUser() + "/AppData/Local/Snake/config.json");
		m_builder["collectComments"] = true;
		JSONCPP_STRING errs;

		if (!parseFromStream(m_builder, ifs, &m_obj, &errs)) {
			std::cout << errs << std::endl;
			ifs.close();
			m_parse = false;
			return m_parse;
		}
		else
		{
			ifs.close();
			fillStruct();
			m_parse = true;
			return m_parse;
		}
	}
	else
	{
		m_instances++;
		return m_parse;
	}
}

void SavedData::setBestScore(unsigned int bestScore)
{
	Data::bestScore = bestScore;
	writeData();
}

void SavedData::setUsername(const char * userName)
{
	SavedData::setUsername(std::string(userName));
}

void SavedData::setUsername(std::string userName)
{
	Data::userName = userName;
	writeData();
}

void SavedData::setLastMod(int lastMod)
{
	Data::lastMod = lastMod;
	writeData();
}

void SavedData::setFirstLaunch(bool firstLaunch)
{
	Data::firstLaunch = firstLaunch;
	writeData();
}

void SavedData::writeData()
{
	std::ofstream of("C:/Users/" + SfmlAPI::getSystemUser() + "/AppData/Local/Snake/config.json");
	m_obj["score"] = Data::bestScore;
	m_obj["userName"] = Data::userName;
	m_obj["lastMod"] = Data::lastMod;
	m_obj["firstLaunch"] = Data::firstLaunch;
	Json::StreamWriterBuilder builder;
	builder["commentStyle"] = "None";
	builder["indentation"] = "	";
	std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	writer->write(m_obj, &of);
	initData();
}

void SavedData::fillStruct()
{
	Data::bestScore = m_obj["score"].asUInt();
	Data::lastMod = m_obj["lastMod"].asInt();
	Data::userName = m_obj["userName"].asCString();
	Data::firstLaunch = m_obj["firstLaunch"].asBool();
	loadFont(m_obj["font-Arial"].asString());
}

void SavedData::loadFont(std::string path)
{
	Data::Arial.loadFromFile(path);
}

unsigned int SavedData::Data::bestScore;
std::string SavedData::Data::userName = "\0";
int SavedData::Data::lastMod;
bool SavedData::Data::firstLaunch;
sf::Font SavedData::Data::Arial;

bool SavedData::m_parse;
Json::Value SavedData::m_obj;
Json::CharReaderBuilder SavedData::m_builder;
int SavedData::m_instances = 0;
