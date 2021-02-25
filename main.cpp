#include "Four_square_cipher.h"

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
  
  std::cout << "\n ";
  
  for(row =0;row< Matrix_dim;row++){
   
    for(col=0;col< Matrix_dim;col++){     
      std::cout << *(*(EKey1 + row) + col) <<" ";
    }
    std::cout << "\n ";
  }

  std::cout << "\n ";
  
  for(row =0;row< Matrix_dim;row++){
    for(col=0;col< Matrix_dim;col++){     
      std::cout << *(*(EKey2 + row) + col) <<" ";
    }
    std::cout << "\n ";
  }
  std::cout << "\n ";

  return 0;
}

	    
