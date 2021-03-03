#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier_h.h"

void ajouter_ligne(char*nom, int x0 , int y0 , int x1 , int y1 , char*dest , int*coul) // dessine une ligne sur l'image nom
                                                                                        // et met le résultat dans dest
 {

   FILE *f;
   f = fopen (nom,"r");
   int x = largeur(nom);
   int y = hauteur(nom);
   char type1[50];
   type(nom ,type1);
   int*tab;
   tab = malloc(sizeof(int)*3*x*y);
   FILE *f2;
   f2 = fopen (dest,"w+");
   if ( strcmp(type1 , "P3")!=0) // si le format n'est pas P3
	{ 
	  printf("l'image n'est pas au bon format : lire le fichier README\n");
	}

   if (f2 == NULL)
     {
       fprintf(stderr, "\nErreur: Impossible de lire le fichier %s\n", nom);
       exit(1);
     }

   if (coul[0] < 0 || coul[0] > 255 ||coul[1] < 0 || coul[2] > 255 ||  coul[3] < 0 || coul[3] > 255){
     printf ( " Erreur : Saisir une couleur entre 0 et 255\n");
     exit(1); 
   } 

   if (x0 < 1 || y0 < 1 || x1 < 1 || y1 < 1 ){
      printf ( " Erreur : Saisir des coordonnées positives et inférieur aux dimensions de l'image, x :%d, y :%d \n", x,y);
     exit(1); 
   }

   if (x0 > x || y0 > y || x1 > x || y1 > y ){
     printf ( " Erreur : Saisir des coordonnées positives et inférieur aux dimensions de l'image, x :%d, y :%d \n", x,y);
     exit(1); 
   }

   remplir_tab(tab,nom);
   double p = (y1 - y0 ) / (x1 - x0); // la pente de la ligne
   if (p < 0 )
     {
       for(int i = 0 ; i < y0 - y1 ; i++) // modifier la matrice de l'image pour avoir la ligne
	 {
	   pixel_set(x0 - (i/p), y0-i , 0 , coul[0] , tab, type1 , x);
	   pixel_set(x0 - (i/p), y0-i , 1 ,  coul[1] , tab,type1 , x);
	   pixel_set(x0 - (i/p), y0-i , 2 ,  coul[2] , tab,type1 , x);

	 }
       fprintf(f2,"P3\n%d %d\n255\n",x, y );
     }
   if (p > 0 )
     {
       for(int i = 0 ; i < y1 - y0 ; i++)
	 {
	   pixel_set(x0 + (i/p), y0+i , 0 ,coul[0] , tab, type1 , x );
	   pixel_set(x0 + (i/p), y0+i , 1 , coul[1] , tab, type1 , x);
	   pixel_set(x0 + (i/p), y0+i , 2 ,coul[2] , tab, type1 , x);

	 }
       fprintf(f2,"P3\n%d %d\n255\n",x, y );
     }
   for(int j = 0 ; j < y  ; j++ )
     {
       for(int i = 0 ; i < 3*x  ; i++ )
	 {
	   fprintf(f2,"%d ", tab[i+3*x*j]);
	 }
       fprintf(f2, "\n");
     }
   
   fclose(f);
   fclose (f2);
 }
