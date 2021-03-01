#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h> 
#include <netinet/in.h> 
/*
struct sockaddr_in {
   uint8_t         sin_len;       // longueur totale     
   sa_family_t     sin_family;    // famille : AF_INET    
   in_port_t       sin_port;      // le numéro de port    
   struct in_addr  sin_addr;      // l'adresse internet   
   unsigned char   sin_zero[8];   // un champ de 8 zéros  
*/

int main(int argc, char*argv[]){
	
  struct sockaddr_in serveraddr,client;//, client;
  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM means that it is a TCP socket
                                            // SOCK_DGRAM means that it is a UDP socket
  if (sockfd == -1) { 
    printf("Socket Creation failed \n"); 
    exit(0); 
  } 
  else
    printf("Socket Successfully created \n");
 
  int port; // The used port
    
  char * buffer = (char*)malloc(200*sizeof(char));
  printf("#Enter the Port\n");
  if(argc != 2){
    printf("#Invalid argument number \n");
    exit(0);
  }
  port = atoi(argv[1]);
  
  // bzero(&serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons(port);
  
  // Bind socket to ip
  if ((bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr))) != 0) { 
    printf("socket bind failed...\n"); 
    exit(0); 
  } 
  else
    printf("Socket successfully binded..\n"); 

  if ((listen(sockfd, 5)) != 0) {    // 5 for max pending connections
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
  int len = sizeof(client);
  //Accept connection
  int connected = accept(sockfd,(struct sockaddr*)&client,&len);
  if (connected < 0) { 
    printf("server acccept failed...\n"); 
    exit(0); 
  } 
  else
    printf("server acccept the client...\n"); 
  
 close(sockfd); 
return 0;
}
