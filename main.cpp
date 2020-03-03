#include <iostream>
#include <stdio.h>
#include "Client/TcpClient.hpp"


int main(){

  TcpClient client(54000,"127.0.0.1");
  client.run();

}