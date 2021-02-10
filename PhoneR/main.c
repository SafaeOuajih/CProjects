#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

static char phone[10][10];
static char user[10][10];
static int i =0;
static char strin[10];

int main(int argc , char* argv){
printf("\n\n\n\n\n\n---------------------Welcome-----------------\n");
printf("\n---Print A: Add record\n");
printf("\n---Print L: List record\n");

//system("clear");
while (1) {
  fgets (strin, 10, stdin);
  if(strcmp(strin,"A\n")==0){
    system("clear");
    AddContact();
    system("clear");
  }
  else if (strcmp(strin,"L\n")==0) {
    system("clear");
    ListContacts();

  }
  else if (strcmp(strin,"D\n")==0) {
    system("clear");
    DeleteContact();
    system("clear");
  }
  else
    printf("chose smthing valid \n");
  printf("\n---Print A: Add record\n");
  printf("\n---Print L: List record\n");
}
return 0;
}

void AddContact(){
  printf("Enter Name\n");
  fgets (user[i], sizeof(user[i]), stdin);
  printf("Enter phone\n");
  fgets (phone[i], sizeof(phone[i]), stdin);
  //printf("mlksq%s\n",user[i]);
  i++;
}

void  DeleteContact(){

  printf("Which one you want to delete ?\n");
  fgets (strin, 10, stdin);
  int num = atoi(strin);
  if(num>i){
    printf("invalid number\n" );
  }else{
    strcpy(user[num], "Null");
    for (int k = num; k < i-1; k++) {
        strcpy(user[k], user[k+1]);
    }
  }
  i--;

}

void ListContacts(){
  printf("L is pressed\n");
  for (int j = 0; j < i; j++) {
    printf("*** Name : %s     Phone : %s\n", user[j], phone[j]);
  }
}
