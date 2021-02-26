#include "Four_square_cipher.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#define Matrix_dim 5

char ** key1;
char ** key2;

int main(){
 
  char ** AlphaM = Matrix_Generator();
  char * m= (char*)malloc(200*sizeof(char));
  char * e_m= (char*)malloc(200*sizeof(char));
  char * d_m= (char*)malloc(200*sizeof(char));
  char * Key = (char*)malloc(30*sizeof(char));
  int row = 0;
  int col = 0;
  char choice;
   std::cout << " ";
   /*  
  for(row =0;row< Matrix_dim;row++){
   
    for(col=0;col< Matrix_dim;col++){     
      std::cout << *(*(AlphaM + row) + col) <<" ";
    }
     std::cout << "\n ";
  }
 
  std::cout << "\n";
   */
  srand((unsigned int)time(NULL));
  Key_Generator();
  std::cout <<"\nRules:\n";
  std::cout <<"- Message lenth < 200 \n";
  std::cout <<"- Message without 'j' or capital letters \n";
  std::cout <<"- Message without space key : not supported yet \n";
  std::cout <<"- Only alphabet \n";
  std::cout <<"\nWhat do you want to do : \n\t A - Encrypt Message \n\t B - Decrypt Message\n";
  std::cin >> choice;
  if(!((choice =='A')||((choice =='B')))){
    std::cout <<"#Invalid Choice, Try again ;) \n";
    exit(0);
  }
  std::cout <<"\n #Enter your sweet message \n";
  std::cin >> m;
  std::cout << "\n";
  std::cout <<" #Your message is:"<<m<<"\n";
  if(choice =='A'){
    e_m = encrypt_F_S(m);
    std::cout <<" #The encrypted message is: "<<e_m<<"\n";
    key1= Key1();
    key2= Key2();
    std::cout << "\n";
    std::cout <<" #The first Key is :\n-: ";

    for(row =0;row< Matrix_dim;row++){
   
      for(col=0;col< Matrix_dim;col++){     
	std::cout << *(*(key1 + row) + col) ;
      }
    }

    std::cout << "\n";
    std::cout <<" #The second Key is :\n-: ";
    for(row =0;row< Matrix_dim;row++){
      for(col=0;col< Matrix_dim;col++){     
	std::cout << *(*(key2 + row) + col) ;
      }
    }
  
    std::cout << "\n ";
  }else{

    std::cout <<" #Enter The first Key : 25 char \n";
    std::cin >> Key;  
    key1=alloc_array();
    key2=alloc_array();    
    totwo_dim(Key,key1);
    std::cout <<" #Enter The second Key : 25 char \n";	
    std::cin >> Key;
    totwo_dim(Key,key2);
    std::cout << "\n ";  
    d_m =  decrypt_F_S(m, key1, key2);
    std::cout <<" #Decrypted message : "<< d_m<<"\n";
  }
  return 0;
}

	    
