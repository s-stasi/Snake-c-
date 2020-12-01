#include "../include/utils.hpp"

namespace SfmlAPI {

	float fpsAsMills(unsigned int fps)
	{
		return 1000.f / fps;
	}

	float fpsAsSecs(unsigned int fps)
	{
		return 1.f / fps;
	}
}