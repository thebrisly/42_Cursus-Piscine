#ifndef SERVERS_MANAGER_HPP
#define SERVERS_MANAGER_HPP

#include <vector>
#include "ServerInitializer.hpp"

class ServersManager
{
	private:
		const std::vector<ServerConfig>		_configs;
		std::vector<ServerInitializer>		_servers;

	public:
		ServersManager(const std::vector<ServerConfig> configs);
		~ServersManager();

		ServerInitializer & get_server_init(int i);

		std::vector<ServerInitializer> & get_servers();

		ServerInitializer & operator[](int i);

		int get_socket_max() const;

		bool is_server_active(const int i) const;

		ServerInitializer & get_server_by_sock(const int sock);


};


#endif