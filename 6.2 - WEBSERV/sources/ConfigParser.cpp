#include "../includes/ConfigParser.hpp"
#include <algorithm>

void print_stack(std::stack<std::string> stack)
{
    // std::cout << "Stack: ";
    while (!stack.empty())
    {
        // std::cout << stack.top() << " ";
        stack.pop();
    }
    // std::cout << std::endl;
}



void ConfigParser::checkForDuplicateServers()
{
    for (size_t i = 0; i < configs.size(); i++)
    {
        for (size_t j = 0; j < configs.size(); j++)
        {
            if (i == j)
                continue;
            if (configs[i].getIPAddress() == configs[j].getIPAddress() && configs[i].getPort() == configs[j].getPort())
                throw std::runtime_error("Duplicate server configuration");
        }
    }
}

void ConfigParser::CheckForMinimumConfig(ServerConfig &server_config)
{
    bool hasIP = !server_config.getIPAddress().empty();
    bool hasPort = server_config.getPort();
    bool hasRoot = !server_config.getRoot().empty();
    bool hasDefaultFile = !server_config.getDefaultFile().empty();
    bool hasHostName = !server_config.getServerName().empty();
    bool hasMaxBodySize = server_config.getMaxBodySize();

    if (!hasIP)
        throw std::runtime_error("Server configuration is missing IP address");
    if (!hasPort)
        throw std::runtime_error("Server configuration is missing port");
    if (!hasRoot)
        throw std::runtime_error("Server configuration is missing root");
    if (!hasDefaultFile)
        throw std::runtime_error("Server configuration is missing default file");
    if (!hasHostName)
        throw std::runtime_error("Server configuration is missing server name");
    if (!hasMaxBodySize)
        throw std::runtime_error("Server configuration is missing max body size");
}

void ConfigParser::processErrorPages(const std::string& key, const std::string& value, ServerConfig& config)
{
    try {
        int errorCode = std::stoi(key);
        config.setErrorPage(errorCode, value);
    } catch (const std::invalid_argument& e) {
        //std::cerr << "Invalid error code in configuration: " << key << std::endl;
    }
}

void ConfigParser::processLocation(const std::string& key, const std::string& value, RouteConfig& route)
{
    std::string str = value;
    if (key == "methods") {
        std::istringstream iss(str);
        std::string method;
        while (std::getline(iss, method, ',')) {
            method.erase(method.find_last_not_of(" \n\r\t")+1);
            method.erase(0, method.find_first_not_of(" \n\r\t"));

            // Check if the method is valid
            if (method != "GET" && method != "POST" && method != "DELETE" && method != "PUT") {
                throw std::runtime_error("Unknown method: " + method);
            }
            route.methods.push_back(method);
        }
    }
    else if (key == "directory_listing") {
        if (value == "on")
            route.directory_listing = true;
        else if (value == "off")
            route.directory_listing = false;
        // else
            // std::cout << "Unknown value for listing: " << key << std::endl;
    } else if (key == "path") {
        route.path = value;
    } else if (key == "root"){
        route.root = value;
    } else if (key == "redirect"){
        route.redirection = value;
    } else {
        throw std::runtime_error("Unknown key or wrong context: " + key);
    }
}

void ConfigParser::processServer(const std::string& key, const std::string& value, ServerConfig& config)
{
    if (value.empty()) {
        throw std::runtime_error("Unknown key or wrong context: " + key);
    }
    if (key == "server_name") {
        config.setServerName(value);
    } else if (key == "port") {
        config.setPort(std::stoi(value));
    } else if (key == "ip") {
        config.setIPAddress(value);
    } else if (key == "max_body_size") {
        config.setMaxBodySize(std::stoi(value));
    } else if (key == "root") {
        config.setRoot(value);
    } else if (key == "default_file") {
        config.setDefaultFile(value);
    } else {
        //// std::cout << key << "Unkown key or wrong context" << std::endl;
        throw std::runtime_error("Unknown key or wrong context: " + key);
    }
}


std::vector<ServerConfig> ConfigParser::parseConfigs(const std::string& filename) {
    std::stack<std::string> contexts;
    // std::cout << "Parsing config file: " << filename << std::endl;
    ServerConfig serverConfig;
    std::ifstream file(filename.c_str());
    std::string line, currentContext;
    int lineNumber = 0, currentIndentation = 0;
    bool in_server = false;

    if (!file.is_open()) {
        std::cerr << "Could not open config file: " << filename << std::endl;
        throw std::runtime_error("Failed to open config file.");
    }

    while (std::getline(file, line)) {
        lineNumber++;
        size_t firstNonSpace = line.find_first_not_of("\t");
        currentIndentation = firstNonSpace;
        if (firstNonSpace == std::string::npos) firstNonSpace = line.length();
        line.erase(0, firstNonSpace);

        if (line.empty() || line[0] == '#') continue;

        // if (firstNonSpace % 4 != 0) {
        //     std::cerr << "Incorrect indentation at line " << lineNumber << std::endl;
        //     continue; // or handle the error
        // }

        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, ':')) {
            key.erase(key.find_last_not_of(" \t") + 1);
            std::getline(iss, value);
            value.erase(0, value.find_first_not_of(" \t"));

            // if (key.empty() || value.empty()) {
            //     std::cerr << "Invalid key-value pair at line " << lineNumber << std::endl;
            //     continue; // or handle the error
            // }


            int stacksize = static_cast<int>(contexts.size());
            for (int i = 0; i <  stacksize - (currentIndentation); i++)
            {
                if (!contexts.empty())
                    contexts.pop();
            }

            // // std::cout << "***************************************" << std::endl;
            // print_stack(contexts);
            // // std::cout << key + ":" + value << " Contexte size " <<  static_cast<int>(contexts.size()) << " Indentation " << currentIndentation <<  std::endl;
            // // std::cout << "****************************************\n" << std::endl;

            if (!contexts.empty())
                currentContext = contexts.top();
            else
                currentContext = "";

            if (currentContext.empty() && key != "server") {
                std::cerr << "Found configuration outside of server block at line " << lineNumber << std::endl;
                throw std::runtime_error("Found configuration outside of server block at line.");

                //continue; // or handle the error
            }

            if (key == "server") {
                if (in_server == true)
                {
                    configs.push_back(serverConfig);
                    serverConfig = ServerConfig();
                }
                in_server = true;
                if (!contexts.empty()) {
                    std::cerr << "Nested server blocks are not allowed. Error at line " << lineNumber << std::endl;
                    throw std::runtime_error("Found configuration outside of server block at line.");

                    //continue;
                } else {
                    currentContext = "server";
                    contexts.push(currentContext);
                }
                continue;
            } else if (key == "location") {
                if (currentContext != "server") {
                    std::cerr << "Location outside of server block at line " << lineNumber << std::endl;
                    throw std::runtime_error("Location outside of server block.");
                    //continue;
                }
                RouteConfig newRoute;
                serverConfig.addRoute(newRoute);
                currentContext = "location";
                contexts.push(currentContext);
                continue ;
            } else if (key == "error_page") {
                if (currentContext != "server") {
                    std::cerr << "Error page outside of server block at line " << lineNumber << std::endl;
                    throw std::runtime_error("Location outside of server block.");

                    //continue;
                }
                currentContext = "error_pages";
                contexts.push(currentContext);
                continue ;
            } 

            if (currentContext.empty())
                continue;
            if (currentContext == "server"){
                processServer(key, value, serverConfig);
            } else if (currentContext == "location"){
                processLocation(key, value, const_cast<RouteConfig&>(serverConfig.getRoutes().back()));
            } else if (currentContext == "error_pages"){
                processErrorPages(key, value, serverConfig);
            } 
        }
    }
    CheckForMinimumConfig(serverConfig);
    configs.push_back(serverConfig);
    checkForDuplicateServers();
    return configs;
}

std::ostream& operator<<(std::ostream& os, const std::vector<ServerConfig> &configs)
{
    for (std::vector<ServerConfig>::const_iterator it = configs.begin(); it!= configs.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    return os;
}