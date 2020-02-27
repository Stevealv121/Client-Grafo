#include <iostream>
#include "TcpClient.hpp"


int main(){

    TcpClient client(54000,"127.0.0.1");
    client.run();

}