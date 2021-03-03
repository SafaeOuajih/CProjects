#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier_h.h"

void inverser(char*nom, char*dest)
{
  FILE*f;
  int x = largeur(nom);
  int y = hauteur(nom);
  int *Tab;
  Tab = malloc(sizeof(int)*3*x*y);
  char a[4];
  char type[4];
  f = fopen (nom,"r");
  if (f == NULL)
    {
      fprintf(stderr, "\nErreur: Impossible de lire le fichier");
      exit(1);
    }
  remplir_tab(Tab ,nom);
  fscanf(f,"%s",type);
  fscanf(f,"%s",a);
  fscanf(f,"%s",a);
  if ( strcmp(type , "P2")==0)
    {
      FILE*f3 ;
      f3 = fopen (dest,"w+");
      if (f3 == NULL)
	{
	  fprintf(stderr, "\nErreur: Impossible de lire le fichier");
	  exit(1);
	}
      fprintf(f3, "P2\n%d %d\n255\n",x , y);
    
      for(int i = 0 ; i<x*y  ; i++ ) // remplir le fichier destination
	{
	  fprintf(f3, "%d ",Tab[x*y - i]);

	}
      fclose( f3 ) ;
  
    }
  if ( strcmp(type , "P1")==0)
    {
      FILE*f3 ;
      f3 = fopen (dest,"w+");
      if (f3 == NULL)
	{
	  fprintf(stderr, "\nErreur: Impossible de lire le fichier");
	  exit(1);
	}
      fprintf(f3, "P1\n%d %d\n",x , y);
    
      for(int i = 0 ; i<x*y  ; i++ ) // remplir le fichier destination
	{
	  fprintf(f3, "%d ",Tab[x*y - i]);

	}
      fclose( f3 ) ;
  
    }
  if ( strcmp(type , "P3")==0)
    {
      FILE*f3 ;
      f3 = fopen (dest,"w+");
      if (f3 == NULL)
	{
	  fprintf(stderr, "\nErreur: Impossible de lire le fichier");
	  exit(1);
	}
      fprintf(f3, "P3\n%d %d\n255\n",x , y);
    
      for(int i = 0 ; i<3*x*y  ; i=i+3 ) // remplir le fichier destination
	{

	  fprintf(f3, "%d ",Tab[3*x*y - (i+2)-1]);
	  fprintf(f3, "%d ",Tab[3*x*y - (i+1)-1]);
	  fprintf(f3, "%d ",Tab[3*x*y - (i+0)-1 ]);

	}
      fclose( f3 ) ;
  
    }
  if ( strcmp(type , "P1")!=0 && strcmp(type , "P2")!=0 &&  strcmp(type , "P3")!=0) // si le format n'est ni P1 ni P2 ni P3
    { 
      printf("l'image n'est pas au bon format : lire le fichier README\n");
    }
  fclose(f);
}
