#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sys/select.h>


#define MAX_CLIENT 1024
#define BUFFER_SIZE 1000000


#include "Client.hpp"

std::string findFileType(std::string fileName);
std::string findMimeType (std::string extension);
std::string reducePath(std::string& path);

void sendRedirectionResponse(int clientSocket, const std::string& newUrl);

void display_clients(std::ofstream & out, std::map<int, Client> & map_clients);
void display_fd_set(std::ofstream & out, const fd_set & readfds, const fd_set & writefds);
bool doesPathExist(const std::string& path);
void saveBinaryFile(const std::string& filename, const std::vector<uint8_t>& data);
bool uploadFile(const std::string& filename, const std::string& data);
std::string loadPage(const std::string& path);
const std::string prepareRescueResponse();
void *ft_memset(void *b, int c, size_t len);


#endif