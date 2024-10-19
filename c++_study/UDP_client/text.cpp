#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include "src_Image.h"

#pragma comment(lib, "ws2_32.lib") // ���� Winsock ��


int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    sockaddr_in serverAddr;
    char buffer[1024];
    const int maxMessages = 5; // ����ʹ���

    // ��ʼ�� Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return 1;
    }

    // �����׽���
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed" << std::endl;
        WSACleanup();
        return 1;
    }

    // ���÷�������ַ
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8888);
    // ʹ�÷������� IP ��ַ
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

    // ѭ�����ͺͽ�������
    while(true) {

        std::cout << "client send: ";
        std::string message;
        std::getline(std::cin, message);

        // ��������
        sendto(clientSocket, message.c_str(), message.length(), 0, (sockaddr*)&serverAddr, sizeof(serverAddr));

        // ������Ӧ
        int addrLen = sizeof(serverAddr);
        int bytesReceived = recvfrom(clientSocket, buffer, sizeof(buffer) - 1, 0, (sockaddr*)&serverAddr, &addrLen);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0'; // ����ַ���������
            std::cout << "Received response: " << buffer << std::endl;
        }

    }

    // �ر��׽���
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
