cmake_minimum_required(VERSION 3.12)
project(Client_Grafo)

set(CMAKE_CXX_STANDARD 14)


add_executable(Client_Grafo main.cpp Client/TcpClient.cpp Client/TcpClient.hpp Client/SimpleGUI.cpp Client/SimpleGUI.hpp)
