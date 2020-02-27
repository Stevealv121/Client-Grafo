//
// Created by steve on 20/02/20.
//

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

#ifndef CLIENT_GRAFO_SOCKET_HPP
#define CLIENT_GRAFO_SOCKET_HPP

using namespace std;
class TcpClient {

public:

    TcpClient(int port, string ipAddress);
    ~TcpClient();
    //main loop
    void run();
    //send
    void sendMessage();
    //receive
    void receive();

private:

    int m_port;
    string m_ipAddress;

    //create socket
    int createSocket();
    //connect to server
    int connectToServer(int socket);

};


#endif //CLIENT_GRAFO_SOCKET_HPP
