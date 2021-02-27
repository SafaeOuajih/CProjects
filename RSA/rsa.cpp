#include "rsa.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define Matrix_dim 5

int pgcd (int a , int b){
int t;
while(1){
t= a%b;
if(t==0){
	return b ;
}
a=b;
b=t;
}
}
int encrypt(){
   //2 random prime numbers
   double p = 13;
   double q = 11;
   double n=p*q;//calculate n
   double track;
   double phi= (p-1)*(q-1);//calculate phi
   //public key
   //e stands for encrypt
   double e=7;
   //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
   while(e<phi) {
      track = pgcd(e,phi);
      if(track==1)
         break;
      else
         e++;
   }
   //private key
   //d stands for decrypt
   //choosing d such that it satisfies d*e = 1 mod phi
   double d1=1/e;
   double d=fmod(d1,phi);
   double message = 9;
   double c = pow(message,e); //encrypt the message
   double m = pow(c,d);
   c=fmod(c,n);
   m=fmod(m,n);
std::cout<< "the message is"<< message ; 
std::cout<<"\n p="<<p;
std::cout<<"\n q="<<q;
std::cout<<"\n encrypted = "<< c;
std::cout<<"\n decrypted = "<< m<<"\n";

  return 0;
}
