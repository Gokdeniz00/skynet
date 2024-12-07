#include "skynet.h"

int initSkyNet(){
    WSADATA wsaDATA;
    if(WSAStartup(MAKEWORD(2,2),&wsaDATA)!=0){
        printf("WSAStartup failed:",WSAGetLastError());
        return 1;
    }
    printf("SkyNet Initialised");
    return 0;
}
void cleanSkyNet(){
    WSACleanup();
}