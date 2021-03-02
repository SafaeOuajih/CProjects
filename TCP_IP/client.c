#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#define size 200
#define Port 8080 
#define SA struct sockaddr

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
  
    // DO THE WORK HERE 	
    
    while(1){
    	while ((buffer[n++] = getchar()) != '\n') 
            ; 
  
    	write(sockfd, buffer, sizeof(buff));
    }
    
    //
    
    
    // close the socket 
    close(sockfd);
    return 0;
} 
