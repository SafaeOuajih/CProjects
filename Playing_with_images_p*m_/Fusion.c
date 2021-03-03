#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier_h.h"

void fusion(char* nom1, char* nom2 , char*dest, int x, int y) // superposer 2 images nom1 et nom2 de meme type
                                                              // l'image nom1 est le backgroung ( grandes dimensions )
                                                              // la position de superposition est choisie par x et y
{

  int x1 = largeur(nom1);
  int y1 = hauteur(nom1);
  int*tab;
  tab = malloc(sizeof(int)*3*x1*x1);
  int x2 = largeur(nom2);
  int y2 = hauteur(nom2);
  char type1[50];
  char type2[50];
  type(nom1 ,type1);
  type(nom2 ,type2);
  FILE*f ;
  f = fopen (dest,"w+");

  if (f == NULL)
    {
      fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n", "p2");
      exit(1);
    }
  if (x < 0 || y < 0 ){
    printf ( " Erreur : Saisir des coordonnées positives et inférieur aux dimensions de l'image, x :%d, y :%d \n", x1, y1);
    exit(1); 
  }

  if (x > x1  || y > y1 ){
    printf ( " Erreur : Saisir des coordonnées positives et inférieur aux dimensions de l'image, x :%d, y :%d \n", x1, y1);
    exit(1); 
  }

    if ( strcmp(type1,"P1") == 0 || strcmp(type1 ,"P2") == 0 )
      {
	int tab2[x2*y2];
	remplir_tab(tab,nom1); // tab contient la matrice de nom1
	remplir_tab(tab2,nom2); // tab 2 contient la matrice de nom2

	for ( int j = 0 ; j < y2 ; j++ ) // modification de tab : contient la matrice de la superposition
	  {

	    for( int i = 0 ; i < x2 ; i++ )
	      {
		int i1 = x1*(y+j)+i+x;
		int i2 = x2*j + i;
		if ((x + i <= x1) && (y + j <= y1))
		  {
		    tab[i1]= tab2[i2];
		  }
	      }

	  }
	if(  strcmp(type1,"P1") == 0 ) // l'ecriture dans le fichier dest depend du type des images , pour P1 :
	  {
	    fprintf(f,"P1\n%d %d\n",x1 ,y1);
	    for(int j = 0 ; j < y1  ; j++ )
	      {
		for(int i = 0 ; i < x1  ; i++ )
		  {
		    fprintf(f,"%d ",tab[i+x1*j]);
		  }
		fprintf(f, "\n");


	      }
	  }
	if(  strcmp(type1,"P2") == 0 ) // pour P2
	  {
	    fprintf(f,"P2\n%d %d\n255\n",x1 ,y1);
	    for(int j = 0 ; j < y1  ; j++ )
	      {
		for(int i = 0 ; i < x1  ; i++ )
		  {
		    fprintf(f,"%d ",tab[i+x1*j]);
		  }
		fprintf(f, "\n");


	      }
	  }
      }

    if ( strcmp(type1,"P3")== 0 ) // si le type est P3
      {
	int tab2[3*x2*y2];
	remplir_tab(tab,nom1); //
	remplir_tab(tab2,nom2); //

	for ( int j = 0 ; j < y2 ; j++ ) // modification tab pour contenir la matrice de la superposition
	  {

	    for( int i = 0 ; i < 3*x2 ; i++ )
	      {
		int i1 = 3*x1*(y+j)+i+3*x;
		int i2 =3*x2*j + i;
		tab[i1]= tab2[i2];
	      }

	  }
	fprintf(f,"P3\n%d %d\n255\n",x1 ,y1);
	for(int j = 0 ; j < y1  ; j++ ) // remplir le fichier destination
	  {
	    for(int i = 0 ; i < 3*x1  ; i=i+3 )
	      {
		for( int k = 0 ; k<3 ;k++)
		  {
		    fprintf(f,"%d ",tab[k+i+3*x1*j]);
		  }
		fprintf(f," ");
	      }
	    fprintf(f, "\n");


	  }
      }


  fclose(f);

}

void fusion_c(char* nom1, char* nom2 , char*dest, int x, int y)
{

  char type1[50];
  char type2[50];
  type(nom1 ,type1);
  type(nom2 ,type2);
  if ( strcmp(type1, type2) == 0 ){
    fusion(nom1 , nom2 , dest, x, y);
  }
  if ( strcmp(type1,"P1") == 0  &&  strcmp(type2,"P2") == 0 )
    {
      convertir_p2( nom1 , nom1);
      fusion(nom1 , nom2 , dest, x, y);
    }
  if ( strcmp(type1,"P2") == 0  &&  strcmp(type2,"P1") == 0 )
    {
      convertir_p2( nom2 , nom2);
      fusion(nom1 , nom2 , dest, x, y);
    }
  if ( strcmp(type1,"P1") == 0  &&  strcmp(type2,"P3") == 0 )
    {
      convertir_p3( nom1 , nom1);
      fusion(nom1 , nom2 , dest, x, y);
    }
  if ( strcmp(type1,"P2") == 0  &&  strcmp(type2,"P3") == 0 )
    {
      convertir_p3( nom1 , nom1);
      fusion(nom1 , nom2 , dest, x, y);
    }
  if ( strcmp(type1,"P3") == 0  &&  strcmp(type2,"P1") == 0 )
    {
      
      convertir_p3( nom2 , nom2);
      fusion(nom1 , nom2 , dest, x, y);
    }
  if ( strcmp(type1,"P3") == 0  &&  strcmp(type2,"P2") == 0 )
    {
      convertir_p3( nom2 , nom2);
      fusion(nom1 , nom2 , dest, x, y);
    }
  if ((strcmp(type1 , "P1")!=0 && strcmp(type1 , "P2")!=0 &&  strcmp(type1 , "P3")!=0) ||(  strcmp(type2 , "P1")!=0 && strcmp(type2 , "P2")!=0 && strcmp(type2 , "P3")!=0)) // si le format n'est ni P1 ni P2 ni P3
    { 
      printf("les images ne sont pas au bon format : lire le fichier README\n");
    }
}
