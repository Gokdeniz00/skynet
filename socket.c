#include "socket.h"
void PrintLastError(const char* msg) {
    printf("%s: %d\n", msg, WSAGetLastError());
}
SOCKET createSocket(int family, int type, int protocol){
    SOCKET s = socket(family, type, protocol);
    if(s==INVALID_SOCKET){
        PrintLastError("Error Creating Socket");
        return 1;
    }
    return s;
}
int bindSocket(SOCKET s, char* ip, int port){
    struct sockaddr_in server = createServer(ip, port);
    if(bind(s,(struct sockaddr*) &server,sizeof(server))== SOCKET_ERROR){
        PrintLastError("Error binding socket");
    }
    return 0;
}
struct sockaddr_in createServer(char* ip, int port){
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);
    return server;
}
int listenSocket(SOCKET s,int backlog){
    if(listen(s,backlog)){
        PrintLastError("Error Listening");
        return 1;
    }
    return 0;
}
struct Conn acceptConnection(SOCKET s){
    struct Conn c;
    c.connSocket = accept(s,(struct sockaddr*)&c.server,sizeof(&c.server));
    if(c.connSocket == INVALID_SOCKET){
        PrintLastError("Error Accepting");
    }
    return c;
}
void destroySocket(SOCKET s){
    closesocket(s);
    printf("Socket succesfully closed.");
}