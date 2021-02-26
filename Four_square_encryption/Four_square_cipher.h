#ifndef __Four_square_cipher_H__
#define __Four_square_cipher_H__

char ** alloc_array( char** Alphab_Matrix );
char** Matrix_Generator( char** Alphab_Matrix );
bool char_in_array(char c , char ** Array);
int* char_pos(char c, char**Array);
void Key_Generator();
char*  encrypt_F_S(char * message);
char*  decrypt_F_S(char * message);
char* decrypt_F_S(char* message, char **Key1, char** Key2);
char** Key1();
char** Key2();
void totwo_dim(char*key, char** Key);
#endif
