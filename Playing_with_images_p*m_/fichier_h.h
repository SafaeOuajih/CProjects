#ifndef FICHIER_H
#define FICHIER_H

void fusion(char* nom1, char* nom2 , char*dest, int x, int y);
void fusion_c(char* nom1, char* nom2 , char*dest, int x, int y);
void creer_imageP2 (int x,int y, int color, char*nom);
void creer_imageP1 (int x,int y, int color , char*nom);
void creer_imageP3 (int x,int y, int color1 , int color2 , int color3 , char*nom);
void remplir_tab(int tab[],char* nom);
void convertir_p3(char*nom, char*dest);
void convertir_p2(char*nom, char*dest);
void pixel_set(int x, int y ,int z,int val, int tab[], char*type , int largeur);
void ajouter_ligne(char*nom, int x0 , int y0 , int x1 , int y1 , char*dest , int*coul);

void disque(int x0, int y0, int r,int* coul, int tab[], int largeur, int hauteur, char type[]);
void cercle(int x0, int y0, int r,int* coul, int tab[], int largeur, int hauteur, char type[]);

void ajouter_cercle ( char *nom, int x0, int y0,int * coul, int r, char *nouveau_nom);
void ajouter_disque ( char *nom, int x0, int y0,int * coul, int r, char *nouveau_nom);
int largeur(char* nom);
int hauteur(char* nom);
void type(char* nom , char* type);
void transp(char* nom1, char* nom2 , char*dest, int x, int y ,int  alpha);
void transp_c(char* nom1, char* nom2 , char*dest, int x, int y, int alpha);

void inverser(char*nom, char*dest);


#endif
