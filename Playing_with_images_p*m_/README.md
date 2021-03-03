les modes de fonctionnement :

mode 1 : creer une image P1
	Commande : ./tout 1 largeur hauteur couleur Nom_image.pbm
	- largeur > 0
	- hauteur > 0
	- couleur 0 ou 1
mode 2 : creer une image P2
	Commande : ./tout 2 largeur hauteur couleur Nom_image.pgm
	- largeur > 0
	- hauteur > 0
	- couleur [0 255 ]

mode 3 : creer une image P3
	Commande : ./tout 3 largeur hauteur couleur1 couleur2 couleur3 Nom_image.pgm
	- largeur > 0
	- hauteur > 0
	- couleur1 [0 255 ]
	- couleur2 [0 255 ]
	- couleur3 [0 255 ]

mode 4 : Convertir une image P1 ou P2 en P3
	Commande : ./tout 4 Nom_image.pvm Nom_dest.ppm
	- Nom_image.pvm avec v = b si l'image en entrée est P1 et v= g si l'image en entrée est P2 

mode 5 :Convertir une image P1 ou P3 en P2
	Commande : ./tout 5 Nom_image.pvm Nom_dest.ppm
	- Nom_image.pvm avec v = b si l'image en entrée est P1 et v= p si l'image en entrée est P3 

mode 6 :Ajouter une ligne à l'image P3
	Commande : ./tout 6 Nom_image.ppm  x0 y0 x1 x1 Nom_dest.ppm couleur1 couleur2 couleur3
	- (x0,y0) point de départ x0 < largeur_image  y0 < hauteur image
	- (x1,y1) point d'arrivée x1 < largeur_image  y1 < hauteur image
	- couleur1 [0 255 ]
	- couleur2 [0 255 ]
	- couleur3 [0 255 ]

mode 7 : Ajouter un cercle à l'image P3
	Commande : ./tout 7 x0 y0 Nom_image.ppm couleur1 couleur2 couleur3 Rayon Nom_dest.ppm 
	- (x0 , y0) centre du cercle x0 > R y0 > R && x0 < largeur y0 < hauteur
	- Rayon du cercle
	- couleur1 [0 255 ]
	- couleur2 [0 255 ]
	- couleur3 [0 255 ]

mode 8 : Ajouter un disque à l'image P3
	Commande : ./tout 8 x0 y0 Nom_image.ppm couleur1 couleur2 couleur3 Rayon Nom_dest.ppm 
	- (x0 , y0) centre du cercle x0 > R y0 > R && x0 < largeur y0 < hauteur
	- Rayon du disque
	- couleur1 [0 255 ]
	- couleur2 [0 255 ]
	- couleur3 [0 255 ]

mode 9 : Inverser l'image UPTODOWN
	Commande : ./tout 9 Nom_image.pvm  Nom_dest.pvm
	- Nom_image.pvm avec v = b si l'image est P1 et v= g si l'image est P2 et v= p si l'image est P3 
	- Nom_dest.pvm avec v = b si l'image est P1 et v= g si l'image est P2 et v= p si l'image est P3

mode 10 : Fusion de deux images : l'image finale sera la plus colorée
	Commande : ./tout 10 Nom_image1.pvm  Nom_image2.pvm  Nom_dest.pvm  x  y
	l'image 1 est l'image en BACKGROUND
	- Nom_image1.pvm avec v = b si l'image est P1 et v= g si l'image est P2 et v= p si l'image est P3 
	- Nom_image2.pvm avec v = b si l'image est P1 et v= g si l'image est P2 et v= p si l'image est P3
	- Nom_dest.pvm avec v = b si l'image est P1 et v= g si l'image est P2 et v= p si l'image est P3
	- (x , y) position de fusion  x > 0 y > 0 &&  x< largeur_image1 x< hauteur_image1

mode 11 : Fusionner 2 images avec un changement de transparence , l'image finale sera la plus colorée
	Commande : ./tout 11 Nom_image1.pvm  Nom_image2.pvm  Nom_dest.pvm  x  y alpha
	l'image 1 est l'image en BACKGROUND
	- Nom_image1.pvm avec v = b si l'image est P1 et v= g si l'image est P2 et v= p si l'image est P3 
	- Nom_image2.pvm avec v = b si l'image est P1 et v= g si l'image est P2 et v= p si l'image est P3
	- Nom_dest.pvm avec v = b si l'image est P1 et v= g si l'image est P2 et v= p si l'image est P3
	- (x , y) position de fusion  x > 0 y > 0 &&  x< largeur_image1 x< hauteur_image1
	- alpha le coefficient de transparence : [0 255]
	

