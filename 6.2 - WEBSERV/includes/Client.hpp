#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include "ServerConfig.hpp"
#include "Request.hpp"

class Client
{
	private :
		const int	_socket;
		std::string _request;
		std::string _response;
		int _socket_mod;
		unsigned long _size_response;
		unsigned long _size_request;

		Request _request_object;

		const ServerConfig	_server_config;

		clock_t	_session_time;



	public :
		Client(int socket, const ServerConfig server_config);
		Client();
		~Client();

		int get_socket() const;

		ServerConfig get_server_config() const;

		clock_t get_session_time() const;
		void set_session_time (clock_t session_time);


		unsigned long get_size_response() const;
		void set_size_response (unsigned long size_response);

		unsigned long get_size_request() const;
		void set_size_request (unsigned long size_request);

		int get_socket_mod() const;
		void set_socket_mod (int socket_mod);

		std::string get_request() const;
		void set_request (std::string request);

		std::string get_response() const;
		void set_response (std::string response);

		const Request& get_request_object() const;

		void set_request_object (Request request_object);

};

std::ostream& operator<<(std::ostream& os, const Client &cl);




#endif
