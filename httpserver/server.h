#ifndef __LOIN_HTTPSERVER_SERVER_H
#define __LOIN_HTTPSERVER_SERVER_H

typedef struct ThreadArgs{
    int cfd;
    struct sockaddr_in* pcaddr;
} ThreadArgs;
#endif //__LOIN_HTTPSERVER_SERVER_H