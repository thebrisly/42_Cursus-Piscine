#ifndef ROUTE_CONFIG_HPP
#define ROUTE_CONFIG_HPP

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <list>

struct RouteConfig
{
    std::string path;
    std::vector<std::string> methods;
    bool directory_listing;
    std::string root;
    std::string redirection;
};

#endif