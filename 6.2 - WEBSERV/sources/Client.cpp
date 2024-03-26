#include "../includes/Client.hpp"
#include <fstream>

Client::Client(const int socket, const ServerConfig server_config) : _socket(socket), _server_config(server_config)
{
	this->_session_time = clock();
	this->_socket_mod = 0;
	this->_size_response = 0;
	this->_size_request = 0;
}

Client::Client(): _socket(0), _socket_mod(0), _size_response(0), _size_request(0){};

Client::~Client() {};

clock_t Client::get_session_time() const
{
	return this->_session_time;
}

void Client::set_session_time (clock_t session_time)
{
	this->_session_time = session_time;
}

int Client::get_socket() const
{
	return this->_socket;
};

unsigned long Client::get_size_response () const
{
	return this->_size_response;
};

void Client::set_size_response (unsigned long size_response)
{
	this->_size_response = size_response;
}

unsigned long Client::get_size_request () const
{
	return this->_size_request;
};

void Client::set_size_request (unsigned long size_request)
{
	this->_size_request = size_request;
}

int Client::get_socket_mod() const
{
	return this->_socket_mod;
};

void Client::set_socket_mod (int socket_mod)
{
	this->_socket_mod = socket_mod;
}

void Client::set_request (std::string request)
{
	this->_request = request;
}

std::string Client::get_request() const
{
	return this->_request;
}

void Client::set_response (std::string response)
{
	this->_response = response;
}

std::string Client::get_response() const
{
	return this->_response;
}

ServerConfig Client::get_server_config() const
{

	return this->_server_config;

}

// Response Client::get_response_object() const
// {
// 	return this->_response_object;
// }

// void Client::set_response_object (Response response_object)
// {
// 	this->_response_object = response_object;
// }

const Request& Client::get_request_object() const
{
	return this->_request_object;
}

void Client::set_request_object (Request request_object)
{
	this->_request_object = request_object;
}

std::ostream& operator<<(std::ostream& os, const Client &cl)
{
	os << "       _socket = " << cl.get_socket() << std::endl;
	os << "  _socket_mode = " << cl.get_socket_mod() << std::endl;
	os << "      _request = " << std::endl;
	os << cl.get_request();
	os << " _size_request = " << cl.get_size_request() << std::endl;
	//os << "     _response = " << cl.get_response() << std::endl;
	os << "_size_response = " << cl.get_size_response() << std::endl;
	os << "connected to server : " << cl.get_server_config().getPort() << std::endl;

	return os;
}
