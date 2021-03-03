#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier_h.h"

void pixel_set(int x, int y ,int z,int val,int tab[], char*type, int largeur)
{
  if((strcmp(type,"P1")==0) || (strcmp(type,"P2") == 0))
{
tab[ y*largeur + x] = val;
}
if(strcmp(type,"P3") == 0)
 {
tab[ y*largeur*3 + 3*x + z] = val;
}

}

void disque(int x0, int y0, int r,int* coul, int tab[], int largeur, int hauteur, char type[])
{
  int x = 0;
  while(x < largeur){
      int y = 0;
      while(y < hauteur)
	{
	  if(((x-x0)*(x-x0) + (y-y0)*(y-y0)) < r*r)
	    {
	      pixel_set(x,y,0,coul[0],tab, type, largeur);
	      pixel_set(x,y,1,coul[1],tab, type, largeur);
	      pixel_set(x,y,2,coul[2],tab, type, largeur);
	    }
	  y++;
	}
      x++;
    }
}

void cercle(int x0, int y0, int r,int* coul, int tab[], int largeur, int hauteur, char type[])
{
  int x = 0;
  int epaisseur = r;
  while(x < largeur){
      int y = 0;
      while(y < hauteur)
	{
	  if((r*r - epaisseur  < ((x-x0)*(x-x0) + (y-y0)*(y-y0))) &&( ((x-x0)*(x-x0) + (y-y0)*(y-y0))  < r*r + epaisseur ) )
	    {
	      pixel_set(x,y,0,coul[0],tab, type, largeur);
	      pixel_set(x,y,1,coul[1],tab, type, largeur);
	      pixel_set(x,y,2,coul[2],tab, type, largeur);
	    }
	  y++;
	}
      x++;
    }
}









void ajouter_cercle ( char *nom, int x0, int y0,int * coul, int r, char *nouveau_nom){
  FILE *f1;
  f1 = fopen(nom,"r");
  char Type[4];
  fscanf(f1 ,"%s", Type) ;

  fclose(f1);

  if (strcmp(Type,"P3")==0)
    { FILE*f;
      int Largeur = largeur(nom);
      int Hauteur = hauteur(nom);


      int *tab;
      tab = malloc(sizeof(int)*3*Largeur*Hauteur);
      char a[4];

      f = fopen (nom,"r");

      fscanf(f,"%s",a);
      fscanf(f,"%s",a);
      fscanf(f,"%s",a);
      fscanf(f,"%s",a);
      if (f == NULL)
        {
	  fprintf(stderr, "\nErreur: Impossible de lire le fichier");
	  exit(1);
	}

      if (coul[0] < 0 || coul[0] > 255 ||coul[1] < 0 || coul[2] > 255 ||  coul[3] < 0 || coul[3] > 255){
	printf ( " Erreur : Saisir une couleur entre 0 et 255\n");
	exit(1); 
      } 

      if (x0 < 1 || y0 < 1 ){
	printf ( " Erreur : Saisir des coordonnées positives et inférieur aux dimensions de l'image, x :%d, y :%d \n", Largeur, Hauteur);
	exit(1); 
      }

      if (x0 > Largeur || y0 > Hauteur ){
	printf ( " Erreur : Saisir des coordonnées positives et inférieur aux dimensions de l'image, x :%d, y :%d \n", Largeur, Hauteur);
	exit(1); 
      }

      for( int i =0 ; i < 3*Largeur*Hauteur ;i++)
	{
	  fscanf(f,"%s",a);
	  tab[i] = atoi(a);
	}
      fclose(f);

      cercle(x0, y0, r, coul, tab, Largeur, Hauteur, Type);

      FILE*f2 ;
      f2 = fopen (nouveau_nom,"w+");

      if (f2 == NULL)
	{
	  fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n", "p2");
	  exit(1);
	}
      fprintf(f2,"P3\n%d %d\n255\n",Largeur ,Hauteur);
      for(int j = 0 ; j < Hauteur  ; j++ )
	{
	  for(int i = 0 ; i < 3*Largeur  ; i=i+3 )
	    {
	      for( int k = 0 ; k<3 ;k++)
		{
		  fprintf(f2,"%d ",tab[k+i+3*Largeur*j]);
		}
	      fprintf(f2," ");
	    }
	  fprintf(f2, "\n");


	}
      fclose(f2);
    }
  if ( strcmp(Type , "P3")!=0) // si le format n'est pas P3
    { 
      printf("l'image n'est pas au bon format : lire le fichier README\n");
    }


}


void ajouter_disque ( char *nom, int x0, int y0,int * coul, int r, char *nouveau_nom){
  FILE *f1;
  f1 = fopen(nom,"r");
  char Type[4];
  fscanf(f1 ,"%s", Type) ;

  fclose(f1);

  if (strcmp(Type,"P3")==0)
    { FILE*f;
      int Largeur = largeur(nom);
      int Hauteur = hauteur(nom);


      int *tab;
      tab = malloc(sizeof(int)*3*Largeur*Hauteur);
      char a[4];

      f = fopen (nom,"r");

      fscanf(f,"%s",a);
      fscanf(f,"%s",a);
      fscanf(f,"%s",a);
      fscanf(f,"%s",a);
      if (f == NULL)
        {
	  fprintf(stderr, "\nErreur: Impossible de lire le fichier");
	  exit(1);
	}

       if (coul[0] < 0 || coul[0] > 255 ||coul[1] < 0 || coul[2] > 255 ||  coul[3] < 0 || coul[3] > 255){
	printf ( " Erreur : Saisir une couleur entre 0 et 255\n");
	exit(1); 
      } 

      if (x0 < 1 || y0 < 1 ){
	printf ( " Erreur : Saisir des coordonnées positives et inférieur aux dimensions de l'image, x :%d, y :%d \n", Largeur, Hauteur);
	exit(1); 
      }

      if (x0 > Largeur || y0 > Hauteur ){
	printf ( " Erreur : Saisir des coordonnées positives et inférieur aux dimensions de l'image, x :%d, y :%d \n", Largeur, Hauteur);
	exit(1); 
      }

      for( int i =0 ; i < 3*Largeur*Hauteur ;i++)
	{
	  fscanf(f,"%s",a);
	  tab[i] = atoi(a);
	}
      fclose(f);

      disque(x0, y0, r, coul, tab, Largeur, Hauteur, Type);

      FILE*f2 ;
      f2 = fopen (nouveau_nom,"w+");

      if (f2 == NULL)
	{
	  fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n", "p2");
	  exit(1);
	}
      fprintf(f2,"P3\n%d %d\n255\n",Largeur ,Hauteur);
      for(int j = 0 ; j < Hauteur  ; j++ )
	{
	  for(int i = 0 ; i < 3*Largeur  ; i=i+3 )
	    {
	      for( int k = 0 ; k<3 ;k++)
		{
		  fprintf(f2,"%d ",tab[k+i+3*Largeur*j]);
		}
	      fprintf(f2," ");
	    }
	  fprintf(f2, "\n");


	}
      fclose(f2);
    }
  if ( strcmp(Type , "P3")!=0) // si le format n'est pas P3
    { 
      printf("l'image n'est pas au bon format : lire le fichier README\n");
    }


}



