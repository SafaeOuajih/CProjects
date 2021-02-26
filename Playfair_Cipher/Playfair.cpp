#include "Playfair.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#define Matrix_dim 5

char ** EKey1;
char ** EKey2;

char ** alloc_array( char** Matrix ){
  int row = 0;
  int col = 0;
  Matrix =(char**) malloc((Matrix_dim + 1)*sizeof(char*));
  for(int i = 0; i<Matrix_dim +1;i++){
    *(Matrix+i)=(char*) malloc((Matrix_dim + 1)*sizeof(char));
  }
    
  for(row =1;row< Matrix_dim+1;row++){
    for(col=1;col< Matrix_dim+1;col++){
      *(*(Matrix + row-1) + col-1)=0;
    }  

  }
  return  Matrix ;
}


bool char_in_key(char c, char* key){

  int len = strlen(key);
  for (int i=0; i<len;i++){
    if(c== *(key+i))
      return true;
  }
  return false;
}


char** Matrix_Generator(char** Alphab_Matrix, char * Key){
  int row = 0;
  int col = 0;
  Alphab_Matrix = alloc_array(Alphab_Matrix);
  int len = strlen(Key);
  char c = rand() % ('z'-'a') + 'a';
  if(len>25){
    std::cout << "#Key lenght is not valid (< 25 char)";
    exit(0);
  }
  
  int row_m = (len-1)/5;
  int col_m = ((len-1)/(row+1))%5;
  char* HKey = (char*)malloc(Matrix_dim*sizeof(char));
  for(int i = 0; i< len ; i ++){
    *(HKey+i)= *(Key+i);
  }
  for(int i=len;i<Matrix_dim*5; i++){
    while(char_in_key(c, HKey)){
      c = rand() % ('z'-'a') + 'a';
    }
    *(HKey+i)=c;
  }
  if(row_m){
    for(row = 0; row< row_m; row++){
      for(col= 0; col< Matrix_dim; col++){ 
	Alphab_Matrix[row][col]=*(HKey+((row)% Matrix_dim)*Matrix_dim + col);
      }  
    }
    for(col= 0; col< col_m+1; col++){ 
      Alphab_Matrix[row_m][col]=*(HKey+((row_m)% Matrix_dim)*Matrix_dim + col);
    }  
  }else{
    
    for(row = 0; row< Matrix_dim; row++){
      for(col= 0; col< Matrix_dim; col++){ 
	Alphab_Matrix[row][col]=*(HKey+((row)% Matrix_dim)*Matrix_dim + col);
      }  
    }
  }
  
  for(int i =0;i< Matrix_dim;i++){
    
    for(int j=0 ; j< Matrix_dim; j++){

      std::cout<< *(*(Alphab_Matrix + i) + j) <<" ";

    }
    std::cout<<"\n";

  }
  return Alphab_Matrix ;
}
