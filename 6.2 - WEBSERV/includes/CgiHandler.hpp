#ifndef CGI_HANDLER_HPP
#define CGI_HANDLER_HPP

#include <iostream>
#include "Color.hpp"
#include <unistd.h>
#include <map>
#include <signal.h>


#define MAX_ARGS 100


class CgiHandler
{
	private :
		const char* _scriptPath;
		const std::map<std::string, std::string> _mmap_args;
		std::string _py_body_response;
		char *args[MAX_ARGS];
		int _inf_loop;

		bool transform_map_to_strArray();

        const std::string _method;

		CgiHandler();

	public :
		~CgiHandler();
		CgiHandler(const char* scriptPath, const std::map<std::string, std::string> mmap_args, const std::string method);
		CgiHandler &operator=(CgiHandler &src);

		const char* get_arg(int i) const;
		const char* get_scriptPath() const;
		std::string get_py_body_response() const;

		int 		get_inf_loop() const;

		std::map<std::string, std::string> get_mmap_args() const;
		bool executePythonScript();

};

std::ostream& operator<<(std::ostream& os, const CgiHandler &cgi_hl);


#endif

