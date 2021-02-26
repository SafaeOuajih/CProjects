#include "Playfair.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define Matrix_dim 5


int main(){


  char * key ;
  std::cin>>key;
  char** Alpha = Matrix_Generator(Alpha,key);
  // free(Alpha);
  // free(key);
  return 0;
}
