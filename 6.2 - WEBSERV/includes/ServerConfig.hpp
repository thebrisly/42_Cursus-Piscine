#ifndef SERVER_CONFIG_HPP
#define SERVER_CONFIG_HPP

#include "RouteConfig.hpp"

class ServerConfig
{
	private:
		unsigned long port;
		std::string ip_address;
		unsigned long max_body_size;
		std::string server_name;
		std::map<int, std::string> error_pages;
		std::string root;
    	std::vector<RouteConfig> routes;
		std::string default_file;

	public:
		ServerConfig();
		~ServerConfig();

		ServerConfig(const ServerConfig& other);
		ServerConfig& operator=(const ServerConfig& other);

		// Setters
		void setPort(unsigned long port);
		void setIPAddress(const std::string& ip_address);
		void setMaxBodySize(unsigned long max_body_size);
		void setServerName(const std::string& server_name);
		void setErrorPage(int errorCode, const std::string& pagePath);
		void setRoot(const std::string& root);
		void addRoute(const RouteConfig& route);
		void setDefaultFile(const std::string& path);

		// Getters
		unsigned long getPort() const;
		std::string getIPAddress() const;
		unsigned long getMaxBodySize() const;
		const std::string& getServerName() const;
		const std::map<int, std::string>& getErrorPages() const;
		const std::string& getRoot() const;
		const std::vector<RouteConfig>& getRoutes() const;
		const std::string& getDefaultFile() const;

		RouteConfig getRoute(const std::string& path) const;



		
};

std::ostream& operator<<(std::ostream& os, const ServerConfig &config);

#endif