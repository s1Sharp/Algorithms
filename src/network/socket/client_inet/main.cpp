#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define SERVER_ADRESS "127.0.0.1"
#define SERVER_PORT 34255
char message[] = "Hello there!\n";
char buf[sizeof(message)];

int main()
{
    int sock;
    struct sockaddr_in addr;
    
    printf("socket pre");
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        printf("socket error");
        exit(1);
    }
    printf("socket");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_ADRESS);
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("connect error %s", strerror(errno));
        exit(2);
    }
    printf("connected");
    send(sock, message, sizeof(message), 0);
    recv(sock, buf, sizeof(message), 0);
    printf(buf);
    close(sock);
    return 0;
}
