#include "dependencies.h"


int main()
{
	Connection* connect = new Connection;

	std::thread snake_thread(snake, connect);

	std::cout << __cplusplus << std::endl;


	if (isFirstLaunch())
	{
		std::thread user_thread(setUser);
		user_thread.join();
	}

	snake_thread.join();

	return 0;
}