#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    // creating socket
    int clinetSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // sending connection request
    connect(clinetSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    //sending data
    const char* message = "Hello, test server";
    send(clinetSocket, message, strlen(message),  0);
    printf("yes send message!");

    //closing socket
    close(clinetSocket);

    return 0;
}