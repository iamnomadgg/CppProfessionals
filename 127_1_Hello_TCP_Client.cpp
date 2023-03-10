#include <cstring>
#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Now we're taking an ipaddress and a port number as arguments to our program
    if (argc != 3)
    {
        std::cerr << "Run program as 'program <ipaddress> <port>'\n";
        return -1;
    }
    auto &ipAddress = argv[1];
    auto &portNum = argv[2];
    addrinfo hints, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    int gAddRes = getaddrinfo(ipAddress, portNum, &hints, &p);
    if (gAddRes != 0)
    {
        std::cerr << gai_strerror(gAddRes) << "\n";
        return -2;
    }
    if (p == NULL)
    {
        std::cerr << "No addresses found\n";
        return -3;
    }
    // socket() call creates a new socket and returns it's descriptor
    int sockFD = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    if (sockFD == -1)
    {
        std::cerr << "Error while creating socket\n";
        return -4;
    }
    // Note: there is no bind() call as there was in Hello TCP Server
    // why? well you could call it though it's not necessary
    // because client doesn't necessarily has to have a fixed port number
    // so next call will bind it to a random available port number
    // connect() call tries to establish a TCP connection to the specified server
    int connectR = connect(sockFD, p->ai_addr, p->ai_addrlen);
    if (connectR == -1)
    {
        close(sockFD);
        std::cerr << "Error while connecting socket\n";
        return -5;
    }
    std::string reply(15, ' ');
    // recv() call tries to get the response from server
    // BUT there's a catch here, the response might take multiple calls
    // to recv() before it is completely received
    // will be demonstrated in another example to keep this minimal
    auto bytes_recv = recv(sockFD, &reply.front(), reply.size(), 0);
    if (bytes_recv == -1)
    {
        std::cerr << "Error while receiving bytes\n";
        return -6;
    }
    std::cout << "\nClient recieved: " << reply << std::endl;
    close(sockFD);
    freeaddrinfo(p);
    return 0;
}