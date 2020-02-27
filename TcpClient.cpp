//
// Created by steve on 20/02/20.
//

#include "TcpClient.hpp"

TcpClient::TcpClient(int port, string ipAddress) :m_port(port), m_ipAddress(ipAddress) {

}

TcpClient::~TcpClient() {

}

void TcpClient::run() {

    char buf[4096];
    string userInput;

    //while loop

    while(true){

        int sending = createSocket();
        if(sending == -1){

            break;
        }
        int server = connectToServer(sending);
        if(server == -1){

            //error
            break;
        }

        do{
            //		Enter lines of text
            cout << "> ";
            getline(cin, userInput);

            //		Send to server
            int sendRes = send(sending, userInput.c_str(), userInput.size() + 1, 0);
            if (sendRes == -1)
            {
                cout << "Could not send to server! Whoops!\r\n";
                continue;
            }

            //		Wait for response
            memset(buf, 0, 4096);
            int bytesReceived = recv(sending, buf, 4096, 0);
            if (bytesReceived == -1)
            {
                cout << "There was an error getting response from server\r\n";
                break;
            }
            else
            {
                //		Display response
                cout << "SERVER> " << string(buf, bytesReceived) << "\r\n";
            }

        }while(true);

        close(sending);


    }



}

void TcpClient::sendMessage() {

}

void TcpClient::receive() {

}

int TcpClient::createSocket() {

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        return 1;
    }

    return sock;
}

int TcpClient::connectToServer(int socket) {

    //	Create a hint structure for the server we're connecting with
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(m_port);
    inet_pton(AF_INET, m_ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(socket, (sockaddr*)&hint, sizeof(hint));
    //int connectRes = connect(socket, NULL, NULL);
    if (connectRes == -1)
    {
        //cerr<<"Can't connect to server"<<endl;
        return 1;
    }
    //cout<<"connected to server"<<endl;
    return 0;

}
