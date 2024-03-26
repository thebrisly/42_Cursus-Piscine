#include "../includes/RunServer.hpp"
#include "../includes/Request.hpp"
#include "../includes/Utils.hpp"



RunServer::RunServer(ServersManager & servers_manager, std::string log_filename) : _servers_manager(servers_manager), _out(log_filename, std::ofstream::out), _time_start(time(NULL))
{

	FD_ZERO(&this->_writefds);
	FD_ZERO(&this->_readfds);

	FD_ZERO(&this->_cpy_readfds);
	FD_ZERO(&this->_cpy_writefds);

	std::cout << BLUE << "[INFO] RunServer : " << RESET << "Avaible ports : " <<std::endl;

	for (unsigned long i = 0; i < this->_servers_manager.get_servers().size(); i++)
	{
		std::cout << "* " << this->_servers_manager[i].get_config().getPort() <<std::endl;

		FD_SET(this->_servers_manager[i].get_sock_server(), &this->_cpy_readfds);
	}

	this->_timeout.tv_sec = 0;
	this->_timeout.tv_usec = 100000;
}

RunServer::~RunServer(){}

void RunServer::accept_new_connection(int i)
{
	int new_socket;

	ServerInitializer & server_init = this->_servers_manager.get_server_by_sock(i);

	if (i != server_init.get_sock_server())
	{
		std::cerr << BLUE << "[ERROR] accept_new_connection : " << RESET << i << " " << server_init.get_sock_server() << std::endl;
	}

	if ((new_socket = accept(i, (struct sockaddr *)&(server_init.get_ref_server_addr()), (socklen_t*)&server_init.get_ref_addrlen()))<0)
	{
		std::cerr << BLUE << "[ERROR] accept_new_connection : " << RESET << std::endl;
		perror("accept");
	}

	std::cout << BLUE << time(0) - this->_time_start << " [INFO] accept new connection : " << RESET << "Socket = " << new_socket << std::endl;
	FD_SET(new_socket, &this->_cpy_readfds);
	this->_map_clients.insert(std::pair<int, Client>(new_socket, Client(new_socket, server_init.get_config())));
}

void RunServer::recvs_request (int i)
{
	char buffer[BUFFER_SIZE];
	int size_read;


	ft_memset(buffer, 0, BUFFER_SIZE);

	size_read = recv(i, buffer, BUFFER_SIZE, 0);

	if (size_read == -1)
	{
		if (close(i) < 0)
		{
			std::cerr << BLUE << time(0) - this->_time_start << " [ERROR] recvs_request : " << RESET << std::endl;
			perror("close");
		}
		FD_CLR(i, &this->_cpy_readfds);
		FD_CLR(i, &this->_cpy_writefds);
		this->_map_clients.erase(i);

		std::cout << BLUE << time(0) - this->_time_start << " [ERROR] recvs_request : " << RESET << "error reading from socket" << RESET <<std::endl;
	}
	else if (size_read == 0 /*&& clock() - this->_map_clients[i].get_session_time() > CLOCKS_PER_SEC*/)
	{
		if (close(i) < 0)
		{
			std::cerr << BLUE << time(0) - this->_time_start << " [ERROR] recvs_request : " << RESET << std::endl;
			perror("close");
		}
		FD_CLR(i, &this->_cpy_readfds);
		FD_CLR(i, &this->_cpy_writefds);
		this->_map_clients.erase(i);
		std::cout << BLUE << time(0) - this->_time_start << " [INFO] recvs_request : " << RESET << "Socket " << i << " disconected (empty socket)" << std::endl;
	}
	else if (size_read > 0)
	{
		std::cout << BLUE << time(0) - this->_time_start << " [INFO] recvs_request : " << RESET << "Received request of " << size_read << " bytes from socket " << i << std::endl;
		FD_CLR(i, &this->_cpy_readfds);
		FD_SET(i, &this->_cpy_writefds);

		// set string request to client
		this->_map_clients[i].set_request(std::string(buffer, size_read));
		this->_map_clients[i].set_size_request(size_read);

		this->_map_clients[i].set_socket_mod(WRITE_M);
		this->_map_clients[i].set_session_time(clock());

		// creation request object
		Request current_request(this->_map_clients[i].get_request(), this->_map_clients[i].get_server_config());
		bool parsing_result = current_request.parseRequest(current_request.getCurrentRequest());

		// request object added to the client
		if (parsing_result == true)
		{

			current_request.prepareResponse();

			this->_map_clients[i].set_request_object(current_request);
			this->_map_clients[i].set_response(current_request.getResponse());
			this->_map_clients[i].set_size_response(current_request.getResponse().length());
		}
		else
		{
			std::cout << BLUE << time(0) - this->_time_start << " [WARNING] recvs_request : " << RESET << "Bad Request (parsing info)" << std::endl;

			const std::string response_rescue = prepareRescueResponse();

			this->_map_clients[i].set_response(response_rescue);
			this->_map_clients[i].set_size_response(response_rescue.length());
		}
	}

}


void RunServer::send_response (int i)
{
	std::string response = this->_map_clients[i].get_response();

	ssize_t send_result = send(i , response.c_str(), response.length() , 0);

	if (send_result > 0)
	{
		if (send_result != static_cast<long>(response.length()))
		{
			std::cerr << BLUE << time(0) - this->_time_start << " [ERROR] send_response : " << RESET << std::endl;
			perror("send");
		}
		else
		{
			std::cout << BLUE << time(0) - this->_time_start << " [INFO] send_response : " << RESET << "Sent response of " << response.length() << " bytes to client "<< i <<std::endl;
		}

		if (this->_map_clients[i].get_request_object().getConnection() == "close")
		{
			if (close (i) < 0)
			{
				std::cerr << BLUE << time(0) - this->_time_start << " [ERROR] send_response " << RESET << std::endl;
				perror("close");
			}
			FD_CLR(i, &this->_cpy_readfds);
			FD_CLR(i, &this->_cpy_writefds);
			this->_map_clients.erase(i);

			std::cout << BLUE << time(0) - this->_time_start << " [INFO] send_response : " << RESET << "Socket " << i << " disconected" <<std::endl;
		}
		else
		{
			FD_CLR(i, &this->_cpy_writefds);
			FD_SET(i, &this->_cpy_readfds);
			this->_map_clients[i].set_socket_mod(READ_M);
		}
	}
	else if (send_result == -1)
	{
		if (close(i) < 0)
		{
			std::cerr << BLUE << time(0) - this->_time_start << " [ERROR] send_response : " << RESET << std::endl;
			perror("close");
		}
		FD_CLR(i, &this->_cpy_readfds);
		FD_CLR(i, &this->_cpy_writefds);
		this->_map_clients.erase(i);

		std::cout << BLUE << time(0) - this->_time_start << " [ERROR] send_response : " << RESET << "error sending on socket" << RESET <<std::endl;

	}
	else if (send_result == 0)
	{
		if (close(i) < 0)
		{
			std::cerr << BLUE << time(0) - this->_time_start << " [ERROR] send_response : " << RESET << std::endl;
			perror("close");
		}
		FD_CLR(i, &this->_cpy_readfds);
		FD_CLR(i, &this->_cpy_writefds);
		this->_map_clients.erase(i);
		std::cout << BLUE << time(0) - this->_time_start << " [INFO] send_response : " << RESET << "Socket " << i << " disconected (empty socket)" << std::endl;
	}
}

void RunServer::process (int loop_count)
{
	int i;
	int max_sd;
	int max_key;

	this->_readfds = this->_cpy_readfds;
	this->_writefds = this->_cpy_writefds;

	max_key = this->_servers_manager.get_socket_max();
	max_sd = this->_servers_manager.get_socket_max();

	for (std::map<int, Client>::iterator it = this->_map_clients.begin(); it != this->_map_clients.end(); ++it)
	{
		if (it->first > max_key)
		{
			max_key = it->first;
		}
	}

	for ( i = 0 ; i < MAX_CLIENT ; i++)
	{
		if (FD_ISSET(i, &this->_readfds) && i > max_sd)
		{
			max_sd = i;
		}
		else if (FD_ISSET(i, &this->_writefds) && i > max_sd)
		{
			max_sd = i;
		}
	}

	/* select() Delete from readfds and writefds all the sockets not "ready" for an I/O operation. */
	if (select(max_sd +1 , &this->_readfds, &this->_writefds, NULL, &this->_timeout) < 0)
	{
		std::cerr << BLUE << "[ERROR] process " << RESET << std::endl;
		perror("select");
	}

	for (i = 0; i < max_sd + 1; i++)
	{

		if (FD_ISSET(i, &this->_readfds) && this->_servers_manager.is_server_active(i))
		{
			this->accept_new_connection(i);

			this->_out << "Considering client " << i << " on loop " << loop_count << " : " <<std::endl;
			this->_out<< "------------------- accept new connection -------------------" << std::endl;
			display_fd_set(this->_out, this->_readfds, this->_writefds);
			this->_out<< "copy = ";
			display_fd_set(this->_out, this->_cpy_readfds, this->_cpy_writefds);
			display_clients(this->_out, this->_map_clients);
		}
		else if (FD_ISSET(i, &this->_readfds))
		{
			this->recvs_request (i);

			this->_out << "Considering client " << i << " on loop " << loop_count << " : " <<std::endl;
			this->_out<< "------------------- recvs request -------------------" << std::endl;
			display_fd_set(this->_out, this->_readfds, this->_writefds);
			this->_out<< "copy = ";
			display_fd_set(this->_out, this->_cpy_readfds, this->_cpy_writefds);
			display_clients(this->_out, this->_map_clients);
		}
		else if (FD_ISSET(i, &this->_writefds))
		{
			this->send_response(i);
			
			this->_out << "Considering client " << i << " on loop " << loop_count << " : " <<std::endl;
			this->_out<< "------------------- send response -------------------" << std::endl;
			display_fd_set(this->_out, this->_readfds, this->_writefds);
			this->_out<< "copy = ";
			display_fd_set(this->_out, this->_cpy_readfds, this->_cpy_writefds);
			display_clients(this->_out, this->_map_clients);
		}
	}
}
