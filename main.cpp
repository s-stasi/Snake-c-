#include "dependencies.h"

#define _(STRING) gettext(STRING)


int main()
{
	std::future<int> snake_result = std::async(std::launch::async, snake);
	std::future<bool> user = std::async(std::launch::async, setUser);
	return 0;
}