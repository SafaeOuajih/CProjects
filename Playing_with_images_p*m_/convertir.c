#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier_h.h"

void convertir_p3(char*nom, char*dest) // convertir l'image "nom" en image P3 "dest" ,
                                       // la fonction traite les deux formats P1 et P2
{
 FILE*f;
 int x = largeur(nom);
 int y = hauteur(nom);
 int *Tab;
 Tab = malloc(sizeof(int)*3*x*y);
  char a[4];
  char type[4];
 f = fopen (nom,"r");

      fscanf(f,"%s",type);
      fscanf(f,"%s",a);
      fscanf(f,"%s",a);
      if ( strcmp(type , "P2")==0)  // si le format de l'image est P2 :
	{
	  fscanf(f,"%s",a);

	  if (f == NULL)
	    {
	      fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
	      exit(1);
	    }
	  for( int i =0 ; i < 3*x*y ;i+=3) // remplir le tableau Tab par la matrice de l'image P3 desirée
	    {
	      fscanf(f,"%s",a);
	      Tab[i] = atoi(a);
	      Tab[i+1] = atoi(a);
	      Tab[i+2] = atoi(a);
	    }

	    FILE*f2 ;
	   f2 = fopen (dest,"w+");
	  if (f2 == NULL)
	    {
	      fprintf(stderr, "\nErreur: Impossible de lire le fichier\n");
	      exit(1);
	    }
	  fprintf(f2, "P3\n%d %d\n255\n",x , y);

	  for(int j = 0 ; j < y  ; j++ )  // remplir le fichier dest
	    {
	      for(int i = 0 ; i < 3*x-3  ; i = i+3 )
		{
		  int i1 = i + 3*x*j;
		  for(int k = 0 ; k< 3 ; k++)
		    {
		      fprintf(f2,"%d ",Tab[i1+k]);

		    }
		  fprintf( f2 ," ");
		}

	      for(int j = 0 ; j< 3 ; j++)
		{
		  fprintf(f2,"%d ",Tab[3*x-3+j]);

		}

	      fprintf(f2 , "\n");
	    }
	  fclose( f2 ) ;
	}

      if ( strcmp(type , "P1")==0)       // si le format de l'image est P1 :
	{
	  if (f == NULL)
	    {
	      fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
	      exit(1);
	    }
	  for( int i =0 ; i < 3*x*y ;i+=3)  // remplir le tableau Tab par la matrice de l'image P3 desirée
	    {
	      fscanf(f,"%s",a);
	      Tab[i] = atoi(a);
	      Tab[i+1] = atoi(a);
	      Tab[i+2] = atoi(a);
	    }
	  FILE*f3 ;
	  f3 = fopen (dest,"w");
	  if (f3 == NULL)
	    {
	      fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
	      exit(1);
	    }

	  fprintf(f3, "P3\n%d %d\n255\n",x , y);
	  for(int j = 0 ; j < y  ; j++ )        // remplir le fichier dest
	    {
	      for(int i = 0 ; i < 3*x  ; i = i+3 )
		{
		  int i1 = i + 3*x*j;
		  for(int k = 0 ; k< 3 ; k++)
		    {
		      if(Tab[i1+k]==0)
			fprintf(f3,"%d ",255);
		      else
			fprintf(f3,"%d ",0);
		    }
		  fprintf( f3 ," ");

		}
	      fprintf(f3 , "\n");
	    }
	  fclose( f3 ) ;

	}
      if ( strcmp(type , "P3")==0) // si le format est P3
	{ 
	  printf("l'image est déja de format P3\n");
	}
      if ( strcmp(type , "P1")!=0 && strcmp(type , "P2")!=0 &&  strcmp(type , "P3")!=0) // si le format n'est ni P1 ni P2 ni P3
	{ 
	  printf("l'image n'est pas au bon format : lire le fichier README\n");
	}
      fclose( f ) ;

}

void convertir_p2(char*nom, char*dest) // convertir l'image "nom" en image P2 "dest" ,
                                       // la fonction traite les deux formats P1 et P3
{
  FILE*f;
  int x = largeur(nom);
  int y = hauteur(nom);
  int*Tab ;
  Tab = malloc(sizeof(int)*3*x*y);
  char a[4];
  char type[4];
  f = fopen (nom,"r");

      fscanf(f,"%s",type);
      fscanf(f,"%s",a);
      fscanf(f,"%s",a);
      if ( strcmp(type , "P3")==0) // si l'image à convertir est de format P3 :
	{
	  fscanf(f,"%s",a);

	  if (f == NULL)
	    {
	      fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
	      exit(1);
	    }
	  for( int i =0 ; i < 3*x*y ;i++) // remplir Tab[] par la matrice de l'image à convertir
	    {
	      fscanf(f,"%s",a);
	      Tab[i] = atoi(a);
	    }

	    FILE*f2 ;
	   f2 = fopen (dest,"w+");
	  if (f2 == NULL)
	    {
	      fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
	      exit(1);
	    }
	  fprintf(f2, "P2\n%d %d\n255\n",x , y);
	  int* tab2;
	  tab2=malloc(sizeof(int)*x*y);
	  int c = 0;
	  for(int i=0 ; i < x*y ; i++) // tab2 le tableau de l'image P2 désirée ..
                                    //on prend la valeur moyenne des 3 valeurs du pixel
	    {

	      tab2[i] = (Tab[i+c] + Tab[i+1+c] + Tab[i+2+c])/3 ;
	      c = c+2;
	    }

	  for(int j = 0 ; j < y  ; j++ ) // remplir le fichier destination
	    {
	      for(int i = 0 ; i < x  ; i++ )
		{
		  fprintf(f2,"%d ", tab2[i+x*j]);
		}
	      fprintf(f2,"\n");
	    }

	  fclose( f2 ) ;
	}

      if ( strcmp(type , "P1")==0) // si l'image à convertie est de format P1
	{
	  if (f == NULL)
	    {
	      fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
	      exit(1);
	    }
	  for( int i =0 ; i < x*y ;i++)
	    {
	      fscanf(f,"%s",a);
	      Tab[i] = atoi(a);
	    }
	  FILE*f3 ;
	  f3 = fopen (dest,"w");
	  if (f3 == NULL)
	    {
	      fprintf(stderr, "\nErreur: Impossible de lire le fichier \n");
	      exit(1);
	    }

	  fprintf(f3, "P2\n%d %d\n255\n",x , y);
	  for(int j = 0 ; j < y  ; j++ ) // remplir le fichier destination
	    {
	      for(int i = 0 ; i < x-1  ; i++)
		{
		  fprintf(f3,"%d ",Tab[i]);
		}
	      fprintf(f3,"%d",Tab[x-1]);
	      fprintf(f3 , "\n");
	    }
	  fclose( f3 ) ;

	}
      if ( strcmp(type , "P2")==0) // si le format est P3
	{ 
	  printf("l'image est déja de format P2\n");
	}
      if ( strcmp(type , "P1")!=0 && strcmp(type , "P2")!=0 &&  strcmp(type , "P3")!=0) // si le format n'est ni P1 ni P2 ni P3
	{ 
	  printf("l'image n'est pas au bon format : lire le fichier README\n");
	}
      fclose( f ) ;

}
