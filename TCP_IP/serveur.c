#include <sdtio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>


int main(int argc, char*argv[]){


  int port; // the used port
  char * buffer = new char[200];
  printf("#Enter the Port\n");
  if(argc != 2){
    printf("#Invalid argument number \n");
    exit(0);
  }
  port = atoi(argv[1]);
return 0;
}
