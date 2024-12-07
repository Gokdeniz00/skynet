#ifndef SOCKET_H
#define SOCKET_H

#include <WinSock2.h>
#include <stdio.h>
struct Conn{
    struct sockaddr_in server;
    SOCKET connSocket;
};
SOCKET createSocket(int family,int type,int protocol);
int bindSocket(SOCKET s, char* ip, int port);
struct sockaddr_in createServer(char* ip, int port);
void PrintLastError(const char* msg);
void destroySocket(SOCKET s);
#endif //ENDIF