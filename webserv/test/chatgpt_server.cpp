#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int PORT = 8080;

std::string generateResponse() {
    std::string response = "HTTP/1.1 200 OK\r\n";
    response += "Content-Type: text/html\r\n\r\n";
    response += "<html><body><h1>Mon serveur web minimaliste</h1><p>Bienvenue !</p></body></html>";
    return response;
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientLen = sizeof(clientAddr);

    // Créez une socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Erreur lors de la création de la socket." << std::endl;
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    // Liez la socket au port
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Erreur lors de la liaison du serveur au port " << PORT << std::endl;
        return 1;
    }

    // Écoutez les connexions entrantes
    listen(serverSocket, 5);

    std::cout << "Serveur en cours d'exécution sur le port " << PORT << std::endl;

    while (true) {
        // Acceptez une connexion entrante
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientLen);

        if (clientSocket < 0) {
            std::cerr << "Erreur lors de l'acceptation de la connexion." << std::endl;
            return 1;
        }

        char buffer[1024];
        ssize_t bytesRead = read(clientSocket, buffer, sizeof(buffer));

        if (bytesRead > 0) {
            std::string request(buffer, bytesRead);
            std::string response = generateResponse();

            // Envoyer la réponse au client
            send(clientSocket, response.c_str(), response.length(), 0);
        }

        close(clientSocket);
    }

    close(serverSocket);
    return 0;
}
