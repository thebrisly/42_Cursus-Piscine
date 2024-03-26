#include "../includes/Request.hpp"
#include "../includes/Utils.hpp"
#include "../includes/Color.hpp"
#include "../includes/CgiHandler.hpp"
#include <unistd.h>
#include <dirent.h>
#include <cstdio>


bool deleteFile(const std::string filename)
{
    if (std::remove(filename.c_str()) == 0)
    {
        std::cout << MAGENTA << "[INFO] " << RESET << "File '" << filename << "' deleted successfully" << std::endl;
        return true;
    }
    else
    {
        std::cout << MAGENTA << "[INFO] " << RESET << "File '" << filename << "' impossible to delete" << std::endl;
        return false;
    }
}


void Request::checkRequest()
{
	int id_route;

	if (!checkHttpVersion())
	{
		this->_status_code = 505;
		this->_status_string = "HTTP Version Not Supported";
		std::cout << MAGENTA << "[INFO] checkRequest : " << RESET << "505 : HTTP Version Not Supported" << std::endl;
	}
	if (!check_host_port())
	{
		this->_status_code = 404; //trouver le bon code erreur
		this->_status_string = "Not Found";
		std::cout << MAGENTA << "[INFO] checkRequest : "<< RESET << "404 : Resource not found" << std::endl;
	}
	else if (this->_body.length() > this->_server_config.getMaxBodySize())
	{
		this->_status_code = 413; //Request Entity Too Large
		this->_status_string = "Request Entity Too Large";
		std::cout << MAGENTA << "[INFO] checkRequest : " << RESET << "413 : Request Entity Too Large" << std::endl;

	}
	else if ((id_route = this->getLocation()) == -1)
	{
		this->_status_code = 400; //page not found error
		this->_status_string = "Bad Request";
		std::cout << MAGENTA << "[INFO] checkRequest : " << RESET << "400 : Bad Request" << std::endl;
	}
	else if (!checkMethods(id_route))
	{
		this->_status_code = 405; //Method Not Allowed
		this->_status_string = "Forbidden";
		std::cout << MAGENTA << "[INFO] checkRequest : " << RESET << "405 : Bad Request (method not allowed)" << std::endl;
	}
	else if (checkRedirection(id_route))
	{
		std::cout << MAGENTA << "[INFO] checkRequest : " << RESET << "301 : Redirection" << std::endl;
		this->_status_code = 301; //redirection (error) code

		//this->checkRequest();
		return ;
	}
	else
	{
		if (this->isFile() == 1)
		{
			if (!this->issetFile(id_route))
			{
				this->_status_code = 404; //page not found error
				this->_status_string = "Not Found";
				std::cout << MAGENTA << "[INFO] checkRequest :" << RESET << "Response error 404 : page not found" << std::endl;
			}
			else
			{
				this->_status_code = 200;
				this->_status_string = "OK";
				std::cout << MAGENTA << "[INFO] checkRequest : " << RESET << "OK 200" << RESET << std::endl;
			}
		}
		else
		{
			if (doesPathExist(this->_server_config.getRoot() + this->_path) == false)
			{
				this->_status_code = 404;
				this->_status_string = "Not Found";
				std::cout << MAGENTA << "[INFO] checkRequest : "<< RESET << "Response error 404 : directory not found" << std::endl;
			}
			else
			{
				this->_status_code = 200;
				this->_status_string = "OK";
				std::cout << MAGENTA << "[INFO] checkRequest : "<< RESET << "(directory) Response OK 200" << std::endl;
			}

		}
	}
}

void	Request::prepareResponse()
{
	std::cout << MAGENTA <<  "[INFO] prepareResponse : " << RESET << this->_method << " " << this->_path <<std::endl;
	this->checkRequest();



	std::string		response;

	std::ostringstream fileContent;
	std::ifstream file;

	if (this->isFile())
	{
		file.open(this->_server_config.getRoot() + this->_path);
	}

	std::string fileType;
	fileType = findMimeType(findFileType(this->_path));

	if (_status_code == 200 || _status_code == 301)
	{
		if (file.is_open())
		{
			if (findFileType(this->_path) == "py" /*&& this->_method == "POST"*/)
			{
				file.close();
				fileType = "text/html";
				const std::string scriptPath = this->_server_config.getRoot() + this->_path;
				CgiHandler cgiHandler(scriptPath.c_str(), this->_userData, this->_method);
				if (cgiHandler.executePythonScript() == 1)
				{
					this->_response_body = cgiHandler.get_py_body_response();
				}
				else
				{
					if (cgiHandler.get_inf_loop() == 1)
					{
						this->_status_code = 508;
						this->_status_string = "Infinite Loop Detected";
						this->getErrorResponse();
					}
					else
					{
						this->_status_code = 500;
						this->_status_string = "Internal Server Error";
						this->getErrorResponse();
					}
				}
			}
			else if (this->_content_to_upload.length() > 0 && this->_method == "POST")
			{
				if (uploadFile(this->_filename, this->_content_to_upload) == false)
				{
					file.close();
					file.open(this->_server_config.getRoot() + "/uploadKO.html");
					fileContent << file.rdbuf();
					this->_response_body = fileContent.str();
					file.close();
				}
				else
				{
					fileContent << file.rdbuf();
					this->_response_body = fileContent.str();
					file.close();
				}
			}
			else if (this->_method == "DELETE")
			{
				file.close();
				fileType = "text/html";

				const std::string fullPath = this->_server_config.getRoot() + this->_path;

				if (deleteFile(fullPath) == true)
				{
					file.open(this->_server_config.getRoot() + "/deleteOK.html");
					fileContent << file.rdbuf();
					this->_response_body = fileContent.str();
					//std::cout << "[Response.cpp] " << MAGENTA << "DELETE prepare response body = " << RESET << body << std::endl;
					file.close();
				}
				else
				{
					file.open(this->_server_config.getRoot() + "/deleteKO.html");
					fileContent << file.rdbuf();
					this->_response_body = fileContent.str();
					//std::cout << "[Response.cpp] " << MAGENTA << "DELETE prepare response body = " << RESET << body << std::endl;
					file.close();
				}

			}
			else
			{
				fileContent << file.rdbuf();
				this->_response_body = fileContent.str();
				//std::cout << "[Response.cpp] " << MAGENTA << "prepare response body = " << RESET << body << std::endl;
				file.close();
			}

		}
		else //Not a file in a directory
		{
			bool directory_listing;
			try
			{
				directory_listing = this->_server_config.getRoute(this->_path).directory_listing;
			}
			catch(const std::exception& e)
			{
				//std::cerr << "[Response.cpp]" << RED << " prepare response " << RESET << "e.what = " << e.what() << '\n';
			}
			fileType = "text/html";
			if (directory_listing == false)
			{
				std::ifstream file(this->_server_config.getRoot() + this->_server_config.getDefaultFile());
				std::ostringstream fileContent;
				if (file.is_open())
				{
					fileContent << file.rdbuf();
					this->_response_body = fileContent.str();
				}
				else
				{
					std::cerr << "ERROR : Cannot read default file : " << this->_server_config.getRoot() + this->_server_config.getDefaultFile() << std::endl;
				}
			}
			else
			{
				DIR *dir;
				struct dirent *ent;
				std::string dirPath = this->_server_config.getRoot() + this->_path;
				dir = opendir(dirPath.c_str());
				fileType = "text/html";
				if (dir != NULL)
				{
					//fileType = "text/html";
					this->_response_body = "<html><head><title>Directory Listing</title></head><body>";
					this->_response_body += "<h1>Directory Listing of " + dirPath + "</h1>";
					this->_response_body += "<ul>";

					while ((ent = readdir(dir)) != NULL)
					{
						std::string filePath = dirPath + "/" + std::string(ent->d_name);
						std::string hrefPath = filePath.substr(this->_server_config.getRoot().length());
						this->_response_body += "<li><a href='" + hrefPath + "'>" + std::string(ent->d_name) + "</a></li>";
						//body += "<li><a href='" + std::string(ent->d_name) + "'>" + std::string(ent->d_name) + "</a></li>";
					}

					this->_response_body += "</ul></body></html>";
					closedir(dir);
					// std::cout << "[Response.cpp]" << MAGENTA << " prepare response " << RESET << "MIME type = " << fileType << std::endl;
				}
			}
		}
	}
	else
	{
		file.close();
		fileType = "text/html";
		this->getErrorResponse();
		// std::cout << YELLOW << "FILE NOT FOUND" << RESET << std::endl;

	}

	response = "HTTP/1.1 " + std::to_string(this->_status_code) + " " + this->_status_string + "\r\n";
	response += "Content-Type: "+fileType+"\r\n";
	response += "Content-Length: " + std::to_string(this->_response_body.size()) + "\r\n";
	response += "Connection: keep-alive\r\n";
	response += "Location: " + this->_path + "\r\n\r\n";
	response += this->_response_body;

	this->_response = response;
}

void Request::getErrorResponse()
{
	std::map<int, std::string> errorPages = this->_server_config.getErrorPages();
	std::map<int, std::string>::const_iterator it = errorPages.find(this->_status_code);
	if (it == errorPages.end())
	{

		// std::cout << YELLOW << "2" << RESET << std::endl;
		std::ifstream default_error_file("web/default_error_pages/" + std::to_string(this->_status_code)+ ".html");
		std::ostringstream default_error_file_content;
		default_error_file_content << default_error_file.rdbuf();
		this->_response_body = default_error_file_content.str();
	}
	else
	{
		std::ifstream errorfile;
		std::ostringstream errorFileContent;
		// std::cout << this->_server_config.getRoot() + it->second << std::endl;
		this->_response_body = "";
		// std::cout << it->second << std::endl;
		errorfile.open(this->_server_config.getRoot() + it->second);
		errorFileContent << errorfile.rdbuf();
		this->_response_body = errorFileContent.str();
		// std::cout << RED << body << RESET << std::endl;

	}
}


// 1. Check version HTTP —> si marche pas : envoyer response error 505

bool Request::checkHttpVersion() const
{
	if (this->_version == "HTTP/1.1\r")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Request::check_host_port() const
{
	if (this->_hostname != this->_server_config.getServerName() && this->_hostname != this->_server_config.getIPAddress())
	{

		return false;
	}

	unsigned long ul_port = std::stoul(this->_port);

	if (ul_port != this->_server_config.getPort())
	{
		return false;
	}
	return true;
}

bool Request::issetFile(int id_route) const
{
	(void) id_route;
	//RouteConfig route = this->_server_config.getRoutes()[id_route];


	std::string root_path_file = this->_server_config.getRoot() + this->_path;
	std::ifstream file;

	file.open(root_path_file);
	if (file)
	{
		file.close();
		//std::cout << MAGENTA << "[INFO] " << RESET << "issetFile : OK "<< root_path_file << std::endl;
		return true;
	}
	else
	{
		//std::cout << MAGENTA << "[INFO] " << RESET << "issetFile : KO "<< root_path_file << std::endl;
		return false;
	}
}


bool Request::checkMethods(int id_route) const
{
	RouteConfig route = this->_server_config.getRoutes()[id_route];
	std::vector<std::string> authorized_methods = route.methods;

	for (std::vector<std::string>::const_iterator it = authorized_methods.begin(); it!= authorized_methods.end(); ++it)
	{
		if (*it == this->_method)
		{
			// std::cout << "[Response.cpp] " << GREEN << "checkMethods : OK " << RESET << std::endl;
			return true;
		}
	}

	// std::cout << "[Response.cpp] " << RED << "checkMethods : OK " << RESET << std::endl;
	return false;
}

bool Request::checkRedirection(int id_route)
{
	(void) id_route;
	// std::cout << "[Response.cpp] " << GREEN << "checkRedirection " <<RESET << " Checking for redirection for ["<< this->_path << "]" <<std::endl;
    //// std::cout << "Current Path: " << this->_path << std::endl;
	std::string usingPath = this->_path;

	if (this->_path == "")
		usingPath = "/";
	else
		usingPath = this->_path;
	RouteConfig route;// = this->_server_config.getRoutes()[id_route];
	try
	{
		route = this->_server_config.getRoute(usingPath);
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
		// std::cout << "[Response.cpp] " << RED << "checkRedirection " << RESET << " No Redirection found" << std::endl;
		return false;
	}

	// std::cout << "[Response.cpp] " << GREEN << "checkRedirection " << RESET << RED << "Redirection to " << RESET << route.redirection << std::endl;
	if (route.redirection != "")
	{

		this->_path = this->_server_config.getRoute(usingPath).redirection;
		// std::cout << "[Response.cpp] " << GREEN << "checkRedirection " << RESET << RED << "Redirection to " << RESET << route.redirection << std::endl;
		return true;
	}

	// std::cout << "[Response.cpp] " << GREEN << "checkRedirection : " << RESET <<  " No Redirection found"<< std::endl;
    return false;
}



// 1 if file, 0 if folder
bool Request::isFile() const {
    size_t lastSlashPos = this->_path.find_last_of('/');
    size_t lastDotPos = this->_path.find_last_of('.');

    // Case 1: No dot in the path, likely a directory
    if (lastDotPos == std::string::npos) {
		// std::cout << "[Response.cpp] " << GREEN << "isFile : " << RESET << "not a file" << std::endl;
        return false;
    }

    // Case 2: Dot present, but no slash - could be a file without directories
    if (lastSlashPos == std::string::npos) {
		// std::cout << "[Response.cpp] " << GREEN << "isFile : " << RESET << "OK file" <<std::endl;
        return true;
    }

    // Case 3: Dot after the last slash - likely a file
    if (lastDotPos > lastSlashPos) {
		// std::cout << "[Response.cpp] " << GREEN << "isFile : " << RESET << "OK file" <<std::endl;
        return true;
    }

    // Default case: Likely a directory
	// std::cout << "[Response.cpp] " << GREEN << "isFile : " << RESET << "not a file" <<std::endl;
    return false;
}
