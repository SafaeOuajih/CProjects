#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier_h.h"
int largeur(char* nom) // renvoit la largeur d'une image à partir de son nom
{
  char x1[20] ; // probleme allocation dynamique
 FILE *f;
  if ((f = fopen (nom,"r+")) == NULL)
    return EXIT_FAILURE;
fscanf (f,"%s",x1);
fscanf (f,"%s",x1);
int x = atoi( x1 );
  fclose(f);

  return x ;
}
int hauteur(char* nom) // renvoit la hauteur d'une image à partir de son nom
{
  char y1[20] ; // probleme allocation dynamique
 FILE *f;
  if ((f = fopen (nom,"r+")) == NULL)
    return EXIT_FAILURE;
fscanf (f,"%s",y1);
fscanf (f,"%s",y1);
fscanf (f,"%s",y1);
int y = atoi( y1 );
  fclose(f);

  return y ;
}

void type(char* nom , char* type) // le type de l'image est recopié dans char*type
{
 FILE *f;
 f = fopen (nom,"r+");
fscanf (f,"%s",type);
  fclose(f);
}
