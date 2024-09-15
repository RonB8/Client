#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <cerrno> 


using namespace std;

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        cerr << "Error creating socket: " << strerror(errno) << endl;
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // כתובת ה-IP של השרת (localhost)

    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        cerr << "Error connecting to server: " << strerror(errno) << endl;
        close(clientSocket);
        return 1;
    }

    const char* msg = "Hi dear server, whatsup??!";
    if (send(clientSocket, msg, strlen(msg), 0) < 0) {
        cerr << "Error sending data: " << strerror(errno) << endl;
        }
    }
    printf("%s\n", buffer);
    
    close(clientSocket);
    return 0;
}
