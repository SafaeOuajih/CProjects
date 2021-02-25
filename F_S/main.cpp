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
  int row = 0;
  int col = 0;
   std::cout << " ";
  for(row =0;row< Matrix_dim;row++){
   
    for(col=0;col< Matrix_dim;col++){     
      std::cout << *(*(AlphaM + row) + col) <<" ";
    }
     std::cout << "\n ";
  }
 
  std::cout << "\n";
  srand((unsigned int)time(NULL));
  Key_Generator();
  
  char * m = "safae";
  std::cout <<encrypt_F_S(m);
  key1= Key1();
  key2= Key2();
  std::cout << "\n ";
  
  for(row =0;row< Matrix_dim;row++){
   
    for(col=0;col< Matrix_dim;col++){     
      std::cout << *(*(key1 + row) + col) <<" ";
    }
    std::cout << "\n ";
  }

  std::cout << "\n ";
  
  for(row =0;row< Matrix_dim;row++){
    for(col=0;col< Matrix_dim;col++){     
      std::cout << *(*(key2 + row) + col) <<" ";
    }
    std::cout << "\n ";
  }
  std::cout << "\n ";

  return 0;
}

	    
