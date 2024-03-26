/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:43:38 by lfabbian          #+#    #+#             */
/*   Updated: 2023/12/14 18:39:31 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Request.hpp"

/////////////////////////////////
// CONSTRUCTORS & DESTRUCTORS //
/////////////////////////////////

#include <unistd.h>

Request::Request() {}

Request::Request(const std::string& str, const ServerConfig server_config) : _current_request(str), _server_config(server_config)
{
        this->_status_code = 0;
        this->_is_cgi = false;
}

Request::Request(const Request& other) {
    *this = other;
}

Request::~Request() {}

Request& Request::operator=(const Request& other)
{

        if (this != &other)
	{
                this->_current_request = other.getCurrentRequest();
                this->_path = other.getPath();
                this->_method = other.getMethod();
                this->_version = other.getVersion();
                this->_host = other.getHost();
                this->_connection = other.getConnection();
                this->_secfetchdest = other.getSecFetchDest();
                this->_port = other.getPort();
                this->_hostname = other.getHostname();
                this->_headers = other.getHeaders();
                this->_default_file = other.getDefaultFile();
                this->_status_code = other.getStatusCode();
                this->_status_string = other.getStatusString();
                this->_response = other.getResponse();
                this->_response_body = other.getResponseBody();
                this->_response_header = other.getResponseHeader();
                this->_server_config = other.getServerConfig();
                this->_filename = other.getFilename();
                this->_content_to_upload = other.getContentToUpload();
                

                //this->_body = other.getBody
	}
        return *this;
}


/////////////////////////////////
///////// SETTERS & GETTERS /////
/////////////////////////////////

std::string Request::getCurrentRequest() const
{
        return (this->_current_request);
}

std::string Request::getContentToUpload() const
{
        return (this->_content_to_upload);
}


std::string Request::getFilename() const
{
        return (this->_filename);
}


std::string Request::getVersion() const
{
        return (this->_version);
}

std::string Request::getMethod() const
{
        return (this->_method);
}

std::string Request::getPath() const
{
        return (this->_path);
}

const std::map<std::string, std::string>& Request::getHeaders() const
{
    return (this->_headers);
}

std::string Request::getHost() const
{
        return (this->_host);
}

std::string Request::getConnection() const
{
        return (this->_connection);
}

std::string Request::getSecFetchDest() const
{
        return (this->_secfetchdest);
}

std::string Request::getPort() const
{
        return (this->_port);
}

std::string Request::getHostname() const
{
        return (this->_hostname);
}

std::string Request::getType() const
{
        return (this->_path.substr(_path.find_last_of(".") + 1));
}

std::string Request::getDefaultFile() const
{
        return (this->_default_file);
}

std::string Request::getResponse() const
{
        return (this->_response);
}

ServerConfig Request::getServerConfig() const
{
        return (this->_server_config);
}


int Request::getStatusCode() const
{
        return this->_status_code;
}

std::string Request::getStatusString() const
{
        return this->_status_string;
}



std::string Request::getResponseBody() const
{
        return this->_response_body;
}

std::string Request::getResponseHeader() const
{
        return this->_response_header;
}

std::string Request::getBody() const
{
        return this->_body;
}

const std::map<std::string, std::string>& Request::getUserData() const
{
    return (this->_userData);
}

bool Request::getIsCgi() const
{
        return this->_is_cgi;
}
