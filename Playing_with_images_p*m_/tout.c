#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier_h.h"

int main(int argc, char* argv[])
{
  if ( argc == 1){
    printf("Erreur : veuillez saisir des arguments : lire le fichier README\n ");
  }
  if ( argc > 1){
    int  mode = atoi( argv[1]);
    switch (mode) {
    case 1:
      if ( argc > 5){
	int largeur = atoi(argv[2]);
	int hauteur = atoi(argv[3]);
	int color = atoi(argv[4]);
	char *nom = argv[5];
	
	creer_imageP1(largeur, hauteur, color, nom);
      }
      if ( argc < 6){
	printf("Erreur : Pas asser d'argument saisi, lire le fichier README\n");
      }
      break;
    case 2:
      if ( argc > 5){
	int largeur = atoi(argv[2]);
	int hauteur = atoi(argv[3]);
	int color = atoi(argv[4]);
	char *nom = argv[5];
	
	creer_imageP2(largeur, hauteur, color, nom);
      }
      if ( argc < 6){
	printf("Erreur : Pas asser d'argument saisi, lire le fichier README\n");
      }
      break;
    case 3:
      if ( argc > 7){
	int largeur = atoi(argv[2]);
	int hauteur = atoi(argv[3]);
	int color1 = atoi(argv[4]);
	int color2 = atoi(argv[5]);
	int color3 = atoi(argv[6]);
	char *nom = argv[7];
	
	creer_imageP3(largeur, hauteur, color1, color2, color3, nom);
      }
      if ( argc < 8){
	printf("Erreur : Pas asser d'argument saisi, lire le fichier README\n");
      }
      break;
    case 4:
      if ( argc > 3){
	char *nom = argv[2];
	char *dest = argv[3];
	convertir_p3(nom, dest);
      }
      if ( argc < 4){
	printf("Erreur : Pas asser d'argument saisi, lire le fichier README\n");
      }
      break;
    case 5:
      if ( argc > 3){
	char *nom = argv[2];
	char *dest = argv[3];
	convertir_p2(nom, dest);
      }
      if ( argc < 4){
	printf("Erreur : Pas asser d'argument saisi, lire le fichier README\n");
      }
      break;
    case 6 : 
       if ( argc > 10){
	char *nom  = argv[2];
	int x0 = atoi(argv[3]);
	int y0 = atoi(argv[4]);
	int x1 = atoi(argv[5]);
	int y1 = atoi(argv[6]);
	char *dest = argv[7];
	int color1 = atoi(argv[8]);
	int color2 = atoi(argv[9]);
	int color3 = atoi(argv[10]);
	int coul[3] = { color1, color2, color3 };
	ajouter_ligne(nom, x0 , y0, x1, y1, dest, coul);
      }
      if ( argc < 11){
	printf("Erreur : Pas asser d'argument saisi, lire le fichier README\n");
      }
      break;
    case 7 :
      if ( argc > 8){
	char *nom  = argv[2];
	int x0 = atoi(argv[3]);
	int y0 = atoi(argv[4]); 
	int color1 = atoi(argv[5]);
	int color2 = atoi(argv[6]);
	int color3 = atoi(argv[7]);
	int rayon = atoi(argv[8]);
	char *nouveau_nom = argv[5];
	int coul[3] = { color1, color2, color3 };
	ajouter_cercle(nom, x0 , y0, coul, rayon, nouveau_nom);
      }
      if ( argc < 9){
	printf("Erreur : Pas asser d'argument saisi, lire le fichier README\n");
      }
      break;

   case 8 :
      if ( argc > 8){
	char *nom  = argv[2];
	int x0 = atoi(argv[3]);
	int y0 = atoi(argv[4]); 
	int color1 = atoi(argv[5]);
	int color2 = atoi(argv[6]);
	int color3 = atoi(argv[7]);
	int rayon = atoi(argv[8]);
	char *nouveau_nom = argv[5];
	int coul[3] = { color1, color2, color3 };
	ajouter_disque(nom, x0 , y0, coul, rayon, nouveau_nom);
      }
      if ( argc < 9){
	printf("Erreur : Pas asser d'argument saisi, lire le fichier README\n");
      }
      break;
     
    case 9:
      if ( argc > 3){
	char *nom = argv[2];
	char *dest = argv[3];
	inverser(nom, dest);
      }
      if ( argc < 4){
	printf("Erreur : Pas asser d'argument saisi, lire le fichier README\n");
      }
      break;
      
    case 10:
      if ( argc > 6){
	char *nom1 = argv[2];
	char *nom2 = argv[3];
	char *dest = argv[4];
	int x = atoi(argv[5]);
	int y = atoi(argv[6]);
	fusion_c(nom1, nom2 , dest, x, y);
      }
      if ( argc < 7){
	printf("Erreur : Pas asser d'argument saisi, lire le fichier README\n");
      }
      break;

     case 11:
      if ( argc > 7){
	char *nom1 = argv[2];
	char *nom2 = argv[3];
	char *dest = argv[4];
	int x = atoi(argv[5]);
	int y = atoi(argv[6]);
	int alpha = atoi(argv[7]);
	transp_c(nom1, nom2 , dest, x, y, alpha);
      }
      if ( argc < 8){
	printf("Erreur : Pas asser d'argument saisi, lire le fichier README\n");
      }
      break;
      
    default:
      printf("Erreur : Saisir un mode entre 1 et 11 \n");
      break;
    }
  
  }






  // creer_imageP3 (500 ,500 , 255 , 255 , 255  ,"3.ppm");
  // creer_imageP2 (10,10,50, "2.pgm");
  // creer_imageP1 (70,70,0 , "1.pbm");
  // creer_imageP3 (854 , 585 , 7 , 10 , 1 ,"3.ppm");
  // creer_imageP3 (515 , 512 , 7 , 10 , 1 ,"4.ppm");
  // convertir_p2("chats.ppm","convert2.pgm");
  // convertir_p3("1.pbm","convert1.ppm");
  // transp("chats.ppm","2.ppm" ,"transptest.ppm",3,3 ,50);
  // convertir_p2("chats.ppm","noir_blanc.pgm");
  // int coul[3]={50 , 100 , 2 };
  // ajouter_ligne("chats.ppm", 150 , 150 , 200 , 200 , "modif.ppm" , coul);

    // ajouter_ligne("modif.ppm", 200 , 200 , 350 , 40 , "modific2.ppm" , coul);

    /* 
   int x[8] = { 3 , 10 , 20 , 50, 3 , 10 , 20 , 50 };
   int y[8] = { 3 , 10 , 20 , 50 , 3 , 10 , 20 , 50 };
    
    polyligne("chats.ppm" , 5 , x , y , "fin.ppm"  , coul);
    */
  // fusion("chats.ppm" ,"2.ppm","fusionchat.ppm",2 ,2);
   
  // cercle_main ("chats.ppm", 100,100 ,coul,50,"cercle.ppm");
  // disque_main ("chats.ppm", 100,100 ,coul,50,"disque.ppm");

  return 0;
}
