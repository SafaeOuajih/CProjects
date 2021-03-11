#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h> 
#include <netinet/in.h>
#include <signal.h>
#define size 200
#define MAX 200

/*
struct sockaddr_in {
   uint8_t         sin_len;       // longueur totale     
   sa_family_t     sin_family;    // famille : AF_INET    
   in_port_t       sin_port;      // le numéro de port    
   struct in_addr  sin_addr;      // l'adresse internet   
   unsigned char   sin_zero[8];   // un champ de 8 zéros  
*/
void chat(int sockfd){
  int n =0;
  int pid;
  char buff[MAX];
  struct sockaddr_in client;
  int len = sizeof(client);
  
    // Listen
    if ((listen(sockfd, 5)) != 0) {    // 5 for max pending connections
      printf("Listen failed...\n"); 
      exit(0); 
    } 
    else
      printf("Server listening..\n");
  // infinite loop for chat
        pid = fork();

  for (;;) {
    //Accept connection
    
    int id_client = accept(sockfd,(struct sockaddr*)&client,&len);
    if (id_client < 0) { 
      printf("server acccept failed...\n"); 
      exit(0); 
    } 
    else
      printf("server acccept the client [%d] [%d]\n",getppid(), getpid());
    
    //fork
    
    if (pid < 0) {
      perror("ERROR on fork");
      exit(1);
    }
    
    if(pid>0){
      // close(id_client);
      //id_client = accept(sockfd,(struct sockaddr*)&client,&len);
      ;
    }else{    //fils 
      bzero(buff, MAX); 
      // read the message from client and copy it in buffer 
      read(id_client, buff, sizeof(buff)); 
      // print buffer which contains the client contents 
      printf("From client: %s\t To client : ", buff);      
      // if msg contains "Exit" then server exit and chat ended. 
      if (strncmp("exit", buff, 4) == 0) { 
	printf("Server Exit...\n");
	close(id_client);
	//close(sockfd);
	//break; 
      }
      /*
      bzero(buff, MAX); 
      n = 0; 
      // copy server message in the buffer 
      while ((buff[n++] = getchar()) != '\n') 
	; 
  
      // and send that buffer to client 
      write(id_client, buff, sizeof(buff)); 
      if (strncmp("exit\n", buff, 6) == 0) { 
	printf("Server Exit...\n");
	close(id_client);
	//close(sockfd);
	//break; 
      }
      */
    }
  }
}

void chat2(int sockfd){
  int n =0;
  int pid;
  char buff[MAX];
  struct sockaddr_in client;
  int len = sizeof(client);
  int id_client;
  if ((listen(sockfd, 5)) != 0) {  
    printf("Listen failed...\n"); 
    exit(0); 
    
  } 
  
  else
    printf("Server listening..\n");
  pid = fork();
  id_client = accept(sockfd,(struct sockaddr*)&client,&len);
  if (id_client < 0) { 
    printf("server acccept failed...\n"); 
    exit(0); 
  } 
  else
    printf("server acccept the client [%d] [%d]\n",getppid(), getpid());
  
  while(1){
    bzero(buff, MAX); 
    read(id_client, buff, sizeof(buff)); 
    printf("From client: %s\t To client : ", buff);      
    if (strncmp("exit", buff, 4) == 0) { 
      printf("Server Exit...\n");
      close(id_client);
    }
    bzero(buff, MAX); 
    n = 0; 
    while ((buff[n++] = getchar()) != '\n') 
      ; 
    write(id_client, buff, sizeof(buff)); 
    if (strncmp("exit\n", buff, 6) == 0) { 
      printf("Server Exit...\n");
      close(id_client);
    }
  } 
}
int main(int argc, char*argv[]){
	
  struct sockaddr_in serveraddr;//, client;
  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM means that it is a TCP socket
                                            // SOCK_DGRAM means that it is a UDP socket
  int n =0;
  if (sockfd == -1) { 
    printf("Socket Creation failed \n"); 
    exit(0); 
  } 
  else
    printf("Socket Successfully created \n");
 
  int port; // The used port
    
  char * buffer = (char*)malloc(size*sizeof(char));
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

  chat2(sockfd);
  
  
  //  close(sockfd);
  return 0;
}
