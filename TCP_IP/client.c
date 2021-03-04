#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#define size 200
#define Port 8080 
#define SA struct sockaddr
#define MAX 200



void chat(int sockfd){

int n = 0;
      char buff[MAX]; 

    for (;;) { 
        bzero(buff, sizeof(buff)); 
        printf("Enter the string : "); 
        n = 0; 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
        write(sockfd, buff, sizeof(buff)); 
        bzero(buff, sizeof(buff)); 
        read(sockfd, buff, sizeof(buff)); 
        printf("From Server : %s", buff); 
        if ((strncmp(buff, "exit", 4)) == 0) { 
            printf("Client Exit...\n"); 
            break; 
        } 
    } 

}
int main() 
{ 
    int sockfd; 
    int n = 0;
    struct sockaddr_in servaddr, cli; 
    char*buffer = (char*)malloc(size*sizeof(char));
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Socket Creation failed :( \n"); 
        exit(0); 
    } 
    else
        printf("Socket Successfully Created :) \n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(Port); 
    
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("Connection with the server Failed :( \n"); 
        exit(0); 
    } 
    else
        printf("Connected to the server :)\n"); 
  
  
    chat(sockfd);
    
    
    // close the socket 
    close(sockfd);
    return 0;
} 

