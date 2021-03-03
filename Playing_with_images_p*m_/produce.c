#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier_h.h"

void creer_imageP2 (int x,int y, int color, char*nom) // creer une image P2 de nom "nom" de taille x , y de couleur , color
{
  FILE*f ;
 f = fopen (nom,"w"); // cree un fichier nom

  if (f == NULL)
    {
      fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n", nom);
      exit(1);
    }
  if (color < 0 || color > 255){
    printf ( " Erreur : Saisir une couleur entre 0 et 255\n");
    exit(1); 
  } 
  if (x < 1 || y < 1){
    printf ( " Erreur : Saisir des dimensions positives\n");
    exit(1); 
  } 
  fprintf(f, "P2\n%d %d\n255\n",x , y);
  for ( int i = 0; i < y; i++) // remplir le fichier par la couleur désirée
    {

      for ( int j = 0 ; j < x-1; j++)
	{

	  fprintf(f, "%d ",color);

	}
      fprintf(f, "%d",color);

      fprintf(f,"\n");
    }

  fclose( f ) ;
}

void creer_imageP1 (int x,int y, int color , char*nom) // creer une image P1 de nom "nom" de taille x , y de couleur , color
{
  FILE*f ;
  f = fopen (nom,"w");

  if (f == NULL)
    {
      fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n", nom);
      exit(1);
    }
  if (color < 0 || color > 1){
    printf ( " Erreur : Saisir une couleur entre 0 et 1\n");
    exit(1); 
  } 
  if (x < 1 || y < 1){
    printf ( " Erreur : Saisir des dimensions positives\n");
    exit(1); 
  } 

  fprintf(f, "P1\n%d %d\n",x , y);
  for ( int i = 0; i < y; i++) // remplir le fichier
    {

      for ( int j = 0 ; j < x-1; j++)
	{

	  fprintf(f,"%d ", color);
	}
	  fprintf(f,"%d", color);

      fprintf(f,"\n");

    }

  fclose( f ) ;
}

void creer_imageP3 (int x,int y, int color1 , int color2 , int color3 , char*nom ) // creer une image P3 de nom "nom" de taille x , y
                                                                                  //de couleur , {color1 , color2 , color3}
{
  FILE*f ;
  f = fopen (nom,"w");

  if (f == NULL)
    {
      fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n", nom);
      exit(1);
    }
  if (color1 < 0 || color1 > 255 ||color2 < 0 || color2 > 255 ||  color3 < 0 || color3 > 255){
    printf ( " Erreur : Saisir une couleur entre 0 et 255\n");
    exit(1); 
  } 
  if (x < 1 || y < 1){
    printf ( " Erreur : Saisir des dimensions positives\n");
    exit(1); 
  }


  fprintf(f, "P3\n%d %d\n255\n", x , y);

  for ( int i = 0; i < y; i++) //  remplir le fichier
    {

      for ( int j = 0 ; j < x-1; j++)
	{
	  fprintf(f,"%d %d %d  ", color1, color2, color3);
	}
	  fprintf(f,"%d %d %d", color1, color2, color3);

      fprintf(f,"\n");
    }
  fclose( f );

}
