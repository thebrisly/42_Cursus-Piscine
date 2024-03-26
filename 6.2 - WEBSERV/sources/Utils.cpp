#include "../includes/Utils.hpp"

#include <sys/stat.h>

bool doesPathExist(const std::string& path)
{
    struct stat info;

    if (stat(path.c_str(), &info) != 0) {
        // Error accessing the file (path does not exist or no permission)
        return false;
    }
	return true;
}

std::string findFileType(std::string fileName)
{
	unsigned long pos = 0;
	while (pos != std::string::npos)
	{
		pos = fileName.find(".");
		fileName.erase(0, pos + 1);
	}
	return fileName;
}

std::string findMimeType (std::string extension)
{
	std::map<std::string, std::string> ext_to_MimeType;

	ext_to_MimeType["css"] = "text/css";
	ext_to_MimeType["jpe"] = "text/jpeg";
	ext_to_MimeType["jpg"] = "text/jpeg";
	ext_to_MimeType["jpeg"] = "text/jpeg";
	ext_to_MimeType["png"] = "text/png";
	ext_to_MimeType["html"] = "text/html";

	if (ext_to_MimeType.find(extension) == ext_to_MimeType.end())
	{
		return "application/octet-stream";
	}

	return ext_to_MimeType[extension];
}


std::string reducePath(std::string& path)
{
    if (path == "/") {
        return path;
    }

    size_t lastSlashPos = path.find_last_of('/');

    if (lastSlashPos == std::string::npos || lastSlashPos == 0) {
        path = "/";
    } else {
        path = path.substr(0, lastSlashPos);
    }

    return path;
}

void display_clients(std::ofstream & out, std::map<int, Client> & map_clients)
{
	for (std::map<int, Client>::iterator it = map_clients.begin(); it!= map_clients.end(); ++it)
	{
		out << "Client : " << it->first << std::endl;
		out << (*it).second << std::endl;
	}
}

void display_fd_set(std::ofstream & out, const fd_set & readfds, const fd_set & writefds)
{
	out << "readfds : ";
	for (int i = 0; i < MAX_CLIENT; i++)
	{
		if (FD_ISSET(i, &readfds))
		{
			out << i << " " ;
		}
	}
	out << std::endl;
	out << "writefds : ";
	for (int i = 0; i < MAX_CLIENT; i++)
	{
		if (FD_ISSET(i, &writefds))
		{
			out << i << " " ;
		}
	}
	out << std::endl;
}

bool uploadFile(const std::string& filename, const std::string& data)
{
	const std::string UPLOAD_DIRECTORY = "web/website0/uploads/";
	std::string fullPath = UPLOAD_DIRECTORY + filename;
	std::ofstream file(fullPath, std::ios::binary);
	if (!file) {
		std::cerr << "Error opening file for writing: " << fullPath << std::endl;
		return false;
	}
	file.write(data.c_str(), data.size());
	return file.good();
}


std::string loadPage(const std::string& path)
{
	std::string result;
	std::ifstream file;
	std::ostringstream fileContent;

	file.open(path);

	if (file.is_open())
	{
		fileContent << file.rdbuf();
		result = fileContent.str();
		file.close();
	}
	else
	{
		result = "Error 500 - Internal Server error";
	}
	return result;
}

const std::string prepareRescueResponse ()
{
	std::string response_rescue_h;
	std::string response_rescue_b;

	response_rescue_b = loadPage("web/default_error_pages/500.html");

	response_rescue_h = "HTTP/1.1 500 OK\r\n";
	response_rescue_h += "Content-Type: text/html\r\n";
	response_rescue_h += "Content-Length: " + std::to_string(response_rescue_b.length()) + "\r\n";
	response_rescue_h += "Connection: keep-alive\r\n";
	response_rescue_h += "\r\n";

	return response_rescue_h + response_rescue_b;
}

void	*ft_memset(void *b, int c, size_t len)
{
	char *str;

	str = (char *) b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}