#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define PACKET_SIZE 1024;

#include <iostream>
#include <WinSock2.h>
#include <thread>
using namespace std;

#pragma comment(lib,"ws2_32.lib")

SOCKET server_socket, client_socket;

int TCP_IP_test() {
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		cout << "WSAStartup failed" << endl;
		return 1;
	}

	server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4444);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	WSACleanup();
	return 0;
}