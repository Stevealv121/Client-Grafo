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
/**
 *Client class implementation
 */
class TcpClient {

public:
    /**
     * Constructor client
     * @param port number
     * @param ipAddress number
     */
    TcpClient(int port, string ipAddress);
    ~TcpClient();
    /**
     * main loop
     */
    void run();
    //send msg
    void sendMessage(int socket, string msg);

private:
    /**
     * port to connect
     */
    int m_port;
    /**
     * ip Address
     */
    string m_ipAddress;

    /**
     * Create socket
     * @return socket
     */
    int createSocket();
    /**
     * connect to server socket
     * @param socket server
     * @return socket
     */
    int connectToServer(int socket);

};


#endif //CLIENT_GRAFO_SOCKET_HPP
