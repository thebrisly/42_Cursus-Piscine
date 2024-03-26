#ifndef RUN_SERVER_HPP
#define RUN_SERVER_HPP

#include "ServerInitializer.hpp"
#include "ServersManager.hpp"
#include "Client.hpp"
#include "Color.hpp"

#define SIZE_WAITING_LIST 100
#define MAX_CLIENT 1024
#define READ_M 0
#define WRITE_M 1

#include <map>
#include <fstream>


class RunServer
{
	private :
		ServersManager & _servers_manager;
		std::map<int, Client> _map_clients;

		fd_set			_readfds;
		fd_set			_writefds;
		fd_set			_cpy_readfds;
		fd_set			_cpy_writefds;
		struct timeval	_timeout;

		std::ofstream	_out;

		const time_t _time_start;


	public :
		RunServer(ServersManager & server_manager, std::string log_filename);
		~RunServer();

		void accept_new_connection(int i);
		void recvs_request(int i);
		void send_response(int i);
		void process(int loop_count);
};

#endif