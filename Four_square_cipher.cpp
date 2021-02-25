#include "Four_square_cipher.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#define Matrix_dim 5

char ** EKey1;
char ** EKey2;

char ** alloc_array(){
  int row = 0;
  int col = 0;
  char** Alphab_Matrix =(char**) malloc((Matrix_dim + 1)*sizeof(char*));
  for(int i = 0; i<Matrix_dim +1;i++){
    *(Alphab_Matrix+i)=(char*) malloc((Matrix_dim + 1)*sizeof(char));
  }
    
  for(row =1;row< Matrix_dim+1;row++){
    for(col=1;col< Matrix_dim+1;col++){
      *(*(Alphab_Matrix + row-1) + col-1)=0;
    }  

  }
  return  Alphab_Matrix ;
}
char** Matrix_Generator(){
  int row = 0;
  int col = 0;
  char** Alphab_Matrix = alloc_array();
  
  for(row =1;row< Matrix_dim+1;row++){
    for(col=1;col< Matrix_dim+1;col++){
      *(*(Alphab_Matrix + row-1) + col-1)='a'+  ((row-1)% Matrix_dim)*Matrix_dim + col-1 ;
    }  

  }
  
  for(row =2;row< Matrix_dim;row++){
    for(col=0;col< Matrix_dim;col++){
      
      *(*(Alphab_Matrix + row) + col)=  *(*(Alphab_Matrix + row) + col)+1;
    }  

  }
  *(*(Alphab_Matrix + 1) + 4)='k';
  return Alphab_Matrix ;
}

bool char_in_array(char c , char ** Array){
  for(int i =0;i< Matrix_dim; i++){
    for(int j=0; j< Matrix_dim; j++)
      if (c == Array[i][j])
	return true;    
  }
  return false;
}

int* char_pos(char c, char**Array){
  int * pos = (int*)malloc(2*sizeof(int)); 
  for(int i =0;i< Matrix_dim; i++){
    for(int j=0; j< Matrix_dim; j++)
      if (c == Array[i][j]){
	*pos=i;
	*(pos+1)=j;
      }   
  }
  return pos;
}
void Key_Generator(){
  int row = 0;
  int col = 0;
  srand((unsigned int)time(NULL));
  char c = rand() % ('z'-'a') + 'a';
  EKey1 = alloc_array();
  EKey2 = alloc_array();
  for(row =1;row< Matrix_dim+1;row++){
    for(col=1;col< Matrix_dim+1;col++){
      while(char_in_array(c, EKey1)){
	c = rand() % ('z'-'a') + 'a';
      }
      *(*(EKey1 + row-1) + col-1)= c ;
    }
  }
  c = rand() % ('z'-'a') + 'a';
  for(row =1;row< Matrix_dim+1;row++){
    for(col=1;col< Matrix_dim+1;col++){
      while(char_in_array(c, EKey2)){
	c = rand() % ('z'-'a') + 'a';
      }
      *(*(EKey2 + row-1) + col-1)= c ;
    }
  }
}


char*  encrypt_F_S(char * message){
  int len = strlen(message);
  int i = 0;
  int j =0;
  int * pos1;
  int * pos2;
  char ** AlphaM =  Matrix_Generator();
  char* encrypt_m = (char*)malloc(len*sizeof(char));
  for(int k=0; k< len ; k=k+2){
    if(char_in_array(message[k], AlphaM)){
      pos1 = char_pos(message[k], AlphaM);
      pos2 = char_pos(message[k+1], AlphaM);
      encrypt_m[k]= EKey1[pos1[0]][pos2[1]];  
      encrypt_m[k+1]= EKey2[pos2[0]][pos1[1]];  
    }
  }
  return encrypt_m;
}
