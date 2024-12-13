#include <stdio.h>
#include "skynet.h"

int main(int argc,char* argv){
    int sn=initSkyNet();
    if(sn!=0){
        printf("Error initializing Skynet");
        return 1;
    }
    prinf("Skynet is up!");
    SOCKET sock;
    int sc=createSocket(AF_INET , SOCK_STREAM , 0,&sock);
    if(sc!=0){
        
    }

    return 0;
}