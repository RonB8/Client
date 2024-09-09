#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

int main(){

    //client syntax
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    //address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    //sending
    const char* msg = "Hi dear client!";
    send(clientSocket, msg, strlen(msg), 0);

    //close socket
     close(clientSocket);


    return 0;
}
