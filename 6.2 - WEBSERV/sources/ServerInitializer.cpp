#include "../includes/ServerInitializer.hpp"

ServerInitializer::ServerInitializer(const ServerConfig config, int size_waiting_list) : _config(config), _size_waiting_list(size_waiting_list)
{

	this->_sock_server = socket(AF_INET, SOCK_STREAM, 0);

	if (this->_sock_server <= 0)
	{
		std::cerr << "Could not create server socket" << std::endl;
		throw std::runtime_error("Could not create server socket");
	}

	this->_opt = 1;
	if( setsockopt(this->_sock_server, SOL_SOCKET, SO_REUSEADDR, (char *)&(this->_opt), sizeof(this->_opt)) < 0 )
	{
		std::cerr << "Could not set socket option" << std::endl;
		throw std::runtime_error("Could not set socket option");
	}

	this->_server_addr.sin_family = AF_INET;
	
	if(inet_pton(AF_INET, this->_config.getIPAddress().c_str(), &_server_addr.sin_addr) <= 0) { 
		perror("Invalid address/ Address not supported");
		//exit(EXIT_FAILURE);
	}

	//// std::cout << "Le port = " << this->_config.getPort() << std::endl;

	this->_server_addr.sin_port = htons(this->_config.getPort());

	this->_addrlen = sizeof(this->_server_addr);

	this->bind_listen_socket_serv();

}

ServerInitializer::~ServerInitializer(){};

int & ServerInitializer::get_ref_addrlen()
{
	return this->_addrlen;
}

int ServerInitializer::get_sock_server() const
{
	return this->_sock_server;
}

struct sockaddr_in ServerInitializer::get_server_addr()
{
	return this->_server_addr;
}

void ServerInitializer::bind_listen_socket_serv()
{
	if (bind(this->_sock_server, (struct sockaddr *)&(this->_server_addr), sizeof(this->_server_addr))<0)
	{
		std::cerr << "bind : " << strerror(errno) << std::endl;
		throw std::runtime_error("Could not bind socket to port");
	}

	if (listen(this->_sock_server, this->_size_waiting_list) < 0)
	{
		std::cerr << "listen : " << strerror(errno) << std::endl;
		throw std::runtime_error("Could not listen on socket");
	}

	if (fcntl(this->_sock_server, F_SETFL, O_NONBLOCK) < 0)
	{
		std::cerr << "fcntl : " << strerror(errno) << std::endl;
		throw std::runtime_error("Could not set socket on NONBLOCK mode");
	}
}

struct sockaddr_in & ServerInitializer::get_ref_server_addr()
{
	return this->_server_addr;
}

const ServerConfig	ServerInitializer::get_config() const
{
	return this->_config;
}


