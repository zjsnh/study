#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include "src_Image.h"

#pragma comment(lib, "ws2_32.lib") // 链接 Winsock 库


int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    sockaddr_in serverAddr;
    char buffer[1024];
    const int maxMessages = 5; // 最大发送次数

    // 初始化 Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return 1;
    }

    // 创建套接字
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed" << std::endl;
        WSACleanup();
        return 1;
    }

    // 设置服务器地址
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8888);
    // 使用服务器的 IP 地址
    if (inet_pton(AF_INET, "123.60.163.45", &serverAddr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    src_init();
    
    for (int j = 0; j <= i; j++)
    {
        sendto(clientSocket, _src[j].c_str(), _src[j].length(), 0, (sockaddr*)&serverAddr, sizeof(serverAddr));
    }

    // 循环发送和接收数据
    while(true) {

        std::cout << "client send: ";
        std::string message;
        std::getline(std::cin, message);

        // 发送数据
        sendto(clientSocket, message.c_str(), message.length(), 0, (sockaddr*)&serverAddr, sizeof(serverAddr));

        // 接收响应
        int addrLen = sizeof(serverAddr);
        int bytesReceived = recvfrom(clientSocket, buffer, sizeof(buffer) - 1, 0, (sockaddr*)&serverAddr, &addrLen);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0'; // 添加字符串结束符
            std::cout << "Received response: " << buffer << std::endl;
        }

    }

    // 关闭套接字
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
