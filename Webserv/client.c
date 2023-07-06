#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void error_handling(char *message);

int main(int ac, char **av) {
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    int str_len;

    if (ac != 3) {
        printf("Usage : %s <IP> <port>\n", av[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error");

    memset(
        &serv_addr, 0,
        sizeof(serv_addr)); // 구조체 변수 serv_addr의 모든 멤버를 0으로 초기화
    serv_addr.sin_family = AF_INET;               // IPv4 인터넷 프로토콜
    serv_addr.sin_addr.s_addr = inet_addr(av[1]); // 32비트 IPv4 주소
    serv_addr.sin_port = htons(atoi(av[2])); // 16비트 TCP/UDP 포트번호

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");

    str_len = read(sock, message, sizeof(message) - 1);
    if (str_len == -1)
        error_handling("read() error");

    printf("Message from server : %s \n", message);
    close(sock);

    return (0);
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
