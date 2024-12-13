#include "TCP.h"

int SendDataTCP(SOCKET s, const char *data){
    int data_length = sizeof(data);
    int success = send(s,data,data_length,0);
    if(success==SOCKET_ERROR){
        PrintLastError("Error while sending! Error code");
        return -1;
    }
    printf("Data successfully sent.");
    return 0;
}
char* RecvDataTCP(SOCKET s){
    char buf[1025];
    char *recvdata= NULL;
    int total_bytes = 0;
    int bytes_received;
    bool connection_closed=false;
    bool receive_failed=false; 
    while(connection_closed==false|| receive_failed==false)
        bytes_received=recv(s,buf,sizeof(&buf)-1,0);

        if(bytes_received==SOCKET_ERROR){
            PrintLastError("Error while receiving! Error code");
            free(recvdata);
            receive_failed=true;
        }
        if(bytes_received==0){
            printf("Connection closed by the server");
            connection_closed=true; 
        }
        buf[bytes_received]="\0";
        char *new_data = realloc(recvdata, total_bytes + bytes_received + 1);
        if (!new_data) {
            printf("Memory allocation failed.\n");
            return recvdata;
        }
        recvdata=new_data;

        memcpy(recvdata + total_bytes, buf, bytes_received);
        total_bytes += bytes_received;

        recvdata[total_bytes] = '\0';
        if(receive_failed){
            return NULL;
        }if(connection_closed){
            return;
        }
        return recvdata;
}