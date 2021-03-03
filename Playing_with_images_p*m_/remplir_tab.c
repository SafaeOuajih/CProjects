#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier_h.h"
void remplir_tab(int tab[],char* nom) // remplir le tableau tab par la matrice de l'image "nom"
{
  FILE *f;
  char type[20];
  char tab2[20];
  char x1[20];
  char y1[20];
  char a[20]; // fscanf effect
  f = fopen (nom,"r");
  fscanf (f,"%s", type);// type
  fscanf (f,"%s", x1); // largeur
  fscanf (f,"%s", y1); // hauteur
  int x = atoi( x1 );
  int y= atoi (y1 );
  if ( strcmp(type,"P1")== 0 )
    {

      for (int i = 0 ; i < x*y ; i++)
	{
	  fscanf (f,"%s",tab2);
	  tab[i] = atoi(tab2);
	}
      // fclose(f);
    }
  if ( strcmp(type,"P2")== 0 )
    {
      fscanf (f,"%s", a);
      for (int i = 0 ; i < x*y ; i++)
	{
	  fscanf (f,"%s",tab2);
	  tab[i] = atoi(tab2);
	}
      // fclose(f);

    }
    if ( strcmp(type,"P3")== 0 )
    {
      fscanf (f,"%s", a);
      for (int i = 0 ; i < 3*x*y ; i++)
	{
	  fscanf (f,"%s",tab2);
	  tab[i] = atoi(tab2);
	}
      //   fclose(f);

    }
    fclose(f);

}
