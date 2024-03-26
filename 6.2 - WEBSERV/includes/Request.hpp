#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <string>
# include <vector>
# include <map>
# include <string>
# include <iostream>
# include <sstream>
# include <fstream>

#include "ServerConfig.hpp"

class Request {

    public :
        // Constructors, Destructors & Overloading operations
        Request();
        Request(const Request& other);
        Request(const std::string& str, const ServerConfig server_config);
		~Request();
		Request& operator=(const Request&);


        // function to initialize http methods
        std::vector<std::string>		            initMethods();
        void                                        clearRequest(); // pour vider le contenu et laisser de la place pour une nouvelle requete

        // parsing the request
        bool                                        parseRequest(const std::string& request);
        void                                        parseHeader(std::string& header);
        void                                        parseBody();
        std::string                                 readFirstLine(const std::string& line);
        std::string                                 readVersion(const std::string& line);
        std::string                                 readMethod(const std::string& line);
        void                                        parseMultipartData();
        


        std::string extractBoundary() const;
        void processMultipartPart(const std::string& part);


        // getters and setters
        std::string                                 getCurrentRequest() const;
        std::string                                 getVersion() const;
        std::string                                 getMethod() const;
        std::string                                 getPath() const;
        std::string                                 getHost() const;
        std::string                                 getConnection() const;
        std::string                                 getSecFetchDest() const;
        std::string                                 getPort() const;
        std::string                                 getHostname() const;
        std::string                                 getType() const;
        std::string                                 getDefaultFile() const;
        std::string                                 getResponse() const;
        std::string                                 getResponseBody() const;
        std::string                                 getResponseHeader() const;
        std::string                                 getBody() const;
        ServerConfig                                getServerConfig() const;

        int                                         getStatusCode() const;
        std::string                                 getStatusString() const;
        bool                                        getIsCgi() const;


        const std::map<std::string, std::string>&   getHeaders() const;
        const std::map<std::string, std::string>&   getUserData() const;

        void                                        parseUserData();
        void                                        parseHostHeader(const std::string& hostHeader, std::string& hostname, std::string& port) const;

        std::string                                 getSecFetchDestHeader() const;
        std::string                                 getHostHeader() const;
        std::string                                 getConnectionHeader() const;

        std::string                                 getFilename() const;
        std::string                                 getContentToUpload() const;

        void                                        checkRequest();
        bool                                        checkHttpVersion() const;
        bool                                        check_host_port() const;
        bool                                        checkPathType() const;
        bool                                        checkFileOrDirectory() const;
        bool                                        checkActionAuthorization() const;
        bool                                        checkMethods(int id_route) const;
        bool                                        checkRedirection(int id_route);

        void    	                                prepareResponse();
        void                                        getErrorResponse();

        bool                                        fileIsAvaible() const;


        bool                                        issetFile(int id_route) const;
        bool                                        isFile() const;


        int                                         getLocation() const;


    private :

        // variables linked to the parsed request
        std::string                                 _current_request;
        std::string                                 _path;
        std::string                                 _method;
        std::string                                 _version;
        std::string                                 _host;
        std::string                                 _connection;
        std::string                                 _secfetchdest;
        std::string                                 _port;
        std::string                                 _hostname;
        std::string                                 _body;

        std::map<std::string, std::string>	        _headers; //dictionnary of keys, values
        std::map<std::string, std::string>          _userData;
        std::string                                 _default_file;

        int                                         _status_code;
        std::string                                 _status_string;

        std::string                                 _response;
        std::string                                 _response_body;
        std::string                                 _response_header;


        ServerConfig                                _server_config;
        bool                                        _is_cgi;

        std::string                                 _filename;
        std::string                                 _content_to_upload;

};

std::ostream& operator<<(std::ostream& os, const Request &request);

#endif
