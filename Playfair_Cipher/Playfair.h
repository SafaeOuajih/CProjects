#ifndef __PLAYFAIR_H__
#define __PLAYFAIR_H__

char ** alloc_array( char** Alphab_Matrix );
char**  Matrix_Generator(char** Alphab_Matrix, char* Key);
char* Playfair_encrypt(char* message, char*e_m , char** Matrix);

#endif
