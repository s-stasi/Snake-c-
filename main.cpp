#include "dependencies.h"

int main()
{
	std::future<int> snake_result = std::async(std::launch::async, snake);
	while (!isGameWindowOpen)
	{ }
	std::future<bool> user = std::async(std::launch::async, setUser);
	return 0;
}