#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(int connfd)
{
    char buff[MAX];
    int n;

    for(;;)
    {
        memset(buff, 0, sizeof(buff));
        // read from client and copy to buffer
        read(connfd, buff, MAX);
        // print buffer
        printf("From client: %s\t To client: ", buff);
        memset(buff, 0, MAX);
        n = 0;
        // copy message in buffer and send to client
        while ((buff[n++] = getchar()) != '\n')
        ;

        // send to client
        write(connfd, buff, sizeof(buff));

        // exit stops the session
        if (strncmp("exit", buff, 4) == 0)
        {
            printf("Server session ended...\n");
            break;
        }
    }
}

int main(int argc, const char* argv[])
{
    int server_fd, new_socket;
    ssize_t valread;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    char* hello = "Hello from server(Thinkpad-X250)";

    // file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // to be continued...

}