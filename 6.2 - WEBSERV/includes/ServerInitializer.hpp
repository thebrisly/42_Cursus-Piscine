#ifndef SERVER_INITIALIZER_HPP
#define SERVER_INITIALIZER_HPP

#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <fcntl.h>
#include "ServerConfig.hpp"
#include <cstring>


class ServerInitializer
{
	private :
		int					_sock_server;
		int					_addrlen;
		struct sockaddr_in	_server_addr;
		int					_opt;

		const ServerConfig	_config;
		const int			_size_waiting_list;


	public :
		ServerInitializer(const ServerConfig config, int size_waiting_list);
		~ServerInitializer();

		int						get_sock_server() const;
		struct sockaddr_in		get_server_addr();
		struct sockaddr_in &	get_ref_server_addr();
		int & 					get_ref_addrlen();
		const ServerConfig		get_config() const;

		void					bind_listen_socket_serv();
};


#endif