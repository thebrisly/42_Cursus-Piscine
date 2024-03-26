#include "../includes/CgiHandler.hpp"
#define CGI_EXEC "/usr/bin/python3"
#define MAX_TIME_CHILD 3

CgiHandler::~CgiHandler(){}


CgiHandler::CgiHandler(const char* scriptPath, const std::map<std::string, std::string> mmap_args, const std::string method) : _scriptPath(scriptPath), _mmap_args(mmap_args), _method(method)
{
	this->_inf_loop = 0;
	this->transform_map_to_strArray();
}

const char* CgiHandler::get_scriptPath() const
{
	return this->_scriptPath;
}

std::string CgiHandler::get_py_body_response() const
{
	return this->_py_body_response;
}

std::map<std::string, std::string> CgiHandler::get_mmap_args() const
{
	return this->_mmap_args;
}

const char* CgiHandler::get_arg(int i) const
{
	return this->args[i];
}

int CgiHandler::get_inf_loop() const
{
	return this->_inf_loop;
}

bool CgiHandler::executePythonScript()
{

	int pid;
    //char* args[] = {(char*)"python", (char*)this->_scriptPath, (char*)"Hello from Python Script", NULL};
	int pipefd[2];
	char buf;

	if (pipe(pipefd) == -1) 
	{
		std::cerr << "CgiHandler.cpp :" << " executePythonScript" << std::endl;
		perror("pipe");
		return false;
	}


	pid = fork();
	if (pid == -1) 
	{
		std::cerr << "CgiHandler.cpp :" << " executePythonScript" << std::endl;
		perror("fork");
		return false;
	}
	if (pid == 0) 
	{
		//std::cerr << "CgiHandler.cpp :" << GREEN << " executePythonScript " << RESET <<  "Child process" << std::endl;

		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

    	execve(CGI_EXEC, this->args, NULL);
		std::cerr << MAGENTA << "[WARNING CHILD]" << RESET << " Impossible to" << " executePythonScript" << std::endl;
		perror("execve");		
		return false;
	}
	else 
	{
		close(pipefd[1]);

		pid_t result;

		bool child_checker = 1;

		time_t start_process_child = time(NULL);

		while (child_checker == 1)
		{
			result = waitpid(pid, NULL, WNOHANG);

			if (result == 0)
			{
				if ((time(NULL) - start_process_child) > MAX_TIME_CHILD)
				{
					kill(pid, SIGKILL);
					child_checker = 0;
					this->_inf_loop = 1;
					close(pipefd[0]);
					std::cerr << MAGENTA << "[WARNING PARENT]" << RESET << " Infinite loop" << " executePythonScript" << std::endl;

					return false;
				}
			}
			else if (result == -1)
			{
				std::cerr << MAGENTA << "[WARNING PARENT]" << RESET << " Impossible to" << " executePythonScript" << std::endl;
				child_checker = 0;
				close(pipefd[0]);
				return false;
			}
			else
			{
				child_checker = 0;
			}
		}

		while(read(pipefd[0], &buf, 1) > 0)
		{
			this->_py_body_response += buf;
		}
		//std::cerr << GREEN << "CgiHandler.cpp :" << RESET << this->_py_body_response << std::endl;
		close(pipefd[0]);

		std::cout << RED << "CgiHandler.cpp :" << RESET << " executePythonScript return true" << std::endl;
		return true;
	}
}

bool CgiHandler::transform_map_to_strArray()
{
	std::string cgi_exec = CGI_EXEC;
	args[0] = (char *) cgi_exec.c_str();
	args[1] = (char *) this->_scriptPath;



	// exit(0);

	if (this->_mmap_args.size() > MAX_ARGS)
	{
		//std::cerr << RED << "CgiHandler.cpp :" << RESET << " transform_map_to_strArray" << std::endl;
		//perror("Too many arguments");
		return false;
	}

	int i = 2;
	for (std::map<std::string, std::string>::const_iterator it = this->_mmap_args.begin(); it!= this->_mmap_args.end(); ++it)
	{
		// args[i] = (char*)it->first.c_str();
		// i++;
		args[i] = (char*)it->second.c_str();
		i++;
	}

	args[i] = NULL;

	return true;
}

 /*
 pipefd[0] => READ
 pipefd[1] => WRITE
 */

std::ostream& operator<<(std::ostream& os, const CgiHandler &cgi_hl)
{
	//os << CYAN <<"current request : " << RESET<< request.getCurrentRequest() << std::endl;

	os << BLUE <<" -------------------- CGI HANDLER -------------------- " << RESET << std::endl;
	os << MAGENTA << "      _scriptPath : " << RESET << cgi_hl.get_scriptPath() <<std::endl;
	os << MAGENTA << "_py_body_response : " << RESET << cgi_hl.get_py_body_response() <<std::endl;

	std::map<std::string, std::string> copy = cgi_hl.get_mmap_args();

	for (std::map<std::string, std::string>::iterator it = copy.begin(); it!= copy.end(); ++it)
	{
		os << MAGENTA << "      _mmap_args : " << RESET << it->first << " " << it->second <<std::endl;
	}

	return os;
}