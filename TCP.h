#ifndef TCP_H
#define TCP_H

#include "socket.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int SendDataTCP(SOCKET s,const char *data);
char* RecvDataTCP(SOCKET s);
#endif //TCP_H