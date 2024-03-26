#include "../includes/ServerConfig.hpp"
#include "../includes/Color.hpp"
#include "../includes/Utils.hpp"
// Constructor
ServerConfig::ServerConfig() : port(0), ip_address(""), max_body_size(0), server_name(""), root(""), default_file("") {}

// Destructor
ServerConfig::~ServerConfig() {}

// Copy Constructor
ServerConfig::ServerConfig(const ServerConfig &other) : port(other.port),
	ip_address(other.ip_address),
	max_body_size(other.max_body_size),
	server_name(other.server_name),
	error_pages(other.error_pages),
	root(other.root),
	routes(other.routes),
    default_file(other.default_file)
    {}

// Copy Assignment Operator
ServerConfig &ServerConfig::operator=(const ServerConfig &other) {
    if (this != &other) {
        port = other.port;
        ip_address = other.ip_address;
        max_body_size = other.max_body_size;
        server_name = other.server_name;
        error_pages = other.error_pages;
        default_file = other.default_file;
        root = other.root;
        routes = other.routes;
    }
    return *this;
}

// Setters
void ServerConfig::setPort(unsigned long p) { port = p; }
void ServerConfig::setIPAddress(const std::string& ip) { ip_address = ip; }
void ServerConfig::setMaxBodySize(unsigned long size)
{
    if (size > BUFFER_SIZE)
        throw std::runtime_error("SIZE_ERROR : MAX_BODY_SIZE > BUFFER_SIZE");
     max_body_size = size;

}
void ServerConfig::setServerName(const std::string& name) { server_name = name; }
void ServerConfig::setDefaultFile(const std::string& path) { default_file = path; }
void ServerConfig::setErrorPage(int errorCode, const std::string& pagePath) { error_pages[errorCode] = pagePath; }
void ServerConfig::setRoot(const std::string& r) { root = r; }
void ServerConfig::addRoute(const RouteConfig& route) { routes.push_back(route); }

// Getters
unsigned long ServerConfig::getPort() const { return port; }
std::string ServerConfig::getIPAddress() const { return ip_address; }
unsigned long ServerConfig::getMaxBodySize() const { return max_body_size; }
const std::string& ServerConfig::getServerName() const { return server_name; }
const std::string& ServerConfig::getDefaultFile() const { return default_file; }
const std::map<int, std::string>& ServerConfig::getErrorPages() const { return error_pages; }
const std::string& ServerConfig::getRoot() const { return root; }
const std::vector<RouteConfig>& ServerConfig::getRoutes() const { return routes; }


bool findByPath(const RouteConfig& route, const std::string& path)
{
    return route.path == path;
}


RouteConfig ServerConfig::getRoute(const std::string& path) const
{
    std::vector<RouteConfig> routes = getRoutes();

    for (std::vector<RouteConfig>::const_iterator it = routes.begin(); it != routes.end(); ++it)
    {
        if (it->path == path)
        {
            return *it;
        }
    }
    throw std::runtime_error("");
    //throw std::runtime_error("Route not found for path: " + path); // or handle the case as appropriate
}

std::ostream& operator<<(std::ostream& os, const ServerConfig &config)
{
	os << CYAN << "\n    server name : " << RESET << config.getServerName() << std::endl;
	os << CYAN << "     ip address : " << RESET << config.getIPAddress() << std::endl;
    os << CYAN << "   default file : " << RESET << config.getDefaultFile() << std::endl;
	os << CYAN << "           port : " << RESET << config.getPort() << std::endl;
	os << CYAN << "  max body size : " << RESET << config.getMaxBodySize() << std::endl;
	os << CYAN << "           root : " << RESET << config.getRoot() << std::endl;
    for (std::map<int, std::string>::const_iterator it = config.getErrorPages().begin(); it!= config.getErrorPages().end(); ++it)
    {
        os << CYAN << "     error code : " << RESET << it->first << YELLOW << "   error page : " << RESET << it->second << std::endl;
    }

    for (std::vector<RouteConfig>::const_iterator  it = config.getRoutes().begin(); it!= config.getRoutes().end(); ++it)
    {
        os << GREEN << "      -  route path : " << RESET << it->path << std::endl;
        os << CYAN << "       route method : " << RESET;
        for (std::vector<std::string>::const_iterator it2 = it->methods.begin(); it2!= it->methods.end(); ++it2)
        {
            os << *it2 << " ";
        }
        os << std::endl;
        os << CYAN << "  directory listing : " << RESET << it->directory_listing << std::endl;
        os << BLUE << "        redirections: " << RED << it->redirection << RESET << std::endl;
    }
	return os;
}

