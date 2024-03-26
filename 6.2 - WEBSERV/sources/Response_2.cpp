#include "../includes/Request.hpp"
#include "../includes/Color.hpp"
#include <unistd.h>

int Request::getLocation() const
{
	std::string path_to_test = this->_path;
	std::vector<RouteConfig> routes = this->_server_config.getRoutes();

	unsigned long i;
	while (path_to_test != "/")
	{
		for (i = 0; i < routes.size(); i++)
		{
			if (routes[i].path == path_to_test)
			{
				// std::cout <<  "[Response_2.cpp]" << GREEN <<" getLocation : OK " << RESET << path_to_test << std::endl;
				return i;
			}
		}

		path_to_test = path_to_test.substr(0, path_to_test.find_last_of('/'));

		if (path_to_test.length() == 0)
		{
			path_to_test = "/";
		}
	}

	for (i = 0; i < routes.size(); i++)
	{
		if (routes[i].path == path_to_test)
		{
			// std::cout << "[Response_2.cpp] " << GREEN << "getLocation : OK " << RESET << path_to_test <<std::endl;
			return i;
		}
	}
	// std::cout << "[Response_2.cpp] " << RED << "getLocation : KO (no route found)" << RESET << std::endl;
	return -1;
}
