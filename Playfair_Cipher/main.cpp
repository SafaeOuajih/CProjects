#include "Playfair.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define Matrix_dim 5


int main(){
  std::cout <<"\nHello! ;)\n";
  std::cout <<"\nRules:\n";
  std::cout <<"- Key lenth < 25 \n";
  std::cout <<"- Key chars must be diffrent \n";
  std::cout <<"- Message lenth < 200 \n";
  std::cout <<"- Message/Key without capital letters \n";
  std::cout <<"- Message/Key without space key : not supported yet \n";
  std::cout <<"- Only alphabet \n";
  std::cout <<"- If message is odd we add 'a' at the end \n";
  std::cout <<"\n# Enter Key\n";
  char * key = new char[24];
  std::cin>>key;
  std::cout <<"\n# The Matrix is as follow : \n\n";
  char** Alpha = Matrix_Generator(Alpha,key);
  char* message = new char[200];
  std::cout<<"\n# Enter message\n";
  std::cin>>message;
  int len = strlen(message);
  if(len%2){
    message[len]='a';
     message[len+1]=0;
  }
  char* e_m= new char[200];
  e_m= Playfair_encrypt(message,e_m,Alpha);
  std::cout<< "\n# Your encrypted is : "<<e_m <<"   \n";
  delete[] key;
  delete[] message;
  delete[] e_m;
  free(Alpha);
  return 0;
}
