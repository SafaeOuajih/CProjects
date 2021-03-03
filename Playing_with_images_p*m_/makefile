

tout : cercle.o convertir.o dimensions.o Fusion.o inverser.o ligne.o produce.o remplir_tab.o tout.o transp.o
	gcc  cercle.o convertir.o dimensions.o Fusion.o inverser.o ligne.o produce.o remplir_tab.o tout.o transp.o -o tout


cercle.o: cercle.c fichier_h.h
	gcc -c -Wall -std=c99   cercle.c

convertir.o: convertir.c fichier_h.h
	gcc -c -Wall -std=c99   convertir.c

dimensions.o: dimensions.c fichier_h.h
	gcc -c -Wall -std=c99   dimensions.c

Fusion.o: Fusion.c fichier_h.h
	gcc -c -Wall -std=c99   Fusion.c

inverser.o: inverser.c fichier_h.h
	gcc -c -Wall -std=c99   inverser.c

ligne.o: ligne.c fichier_h.h
	gcc -c -Wall -std=c99   ligne.c


produce.o: produce.c fichier_h.h
	gcc -c -Wall -std=c99   produce.c

remplir_tab.o: remplir_tab.c fichier_h.h
	gcc -c -Wall -std=c99   remplir_tab.c

tout.o: tout.c fichier_h.h
	gcc -c -Wall -std=c99   tout.c

transp.o: transp.c fichier_h.h
	gcc -c -Wall -std=c99   transp.c


clean :
	rm *.o

