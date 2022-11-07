/* 
 * Tests pour la classe ArbreAVL.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 *
 */

#include <iostream>
#include "arbreavl.h"

int nbMinAVL(int h){
    if(h == 0) 
			return 0;
    if(h == 1) 
			return 1;
    return 1 + nbMinAVL(h - 2) + nbMinAVL(h - 1);
}

int main() {
	int erreur=0;
	std::cout << "Test unitaire #5" << std::endl; 
	time_t t;
	srand((unsigned) time(&t));
	for(int test = 0; erreur < 0 && test < 500; test++) {
		ArbreAVL<int> arbre;
		for(int i = 0, n = 0; i < 500; i++) {
			int nombre = rand() % 2000;
			if(arbre.contient(nombre)) 
				continue;
			arbre.inserer(nombre);
			n++;
			int h = arbre.hauteur();
			int nbmin = nbMinAVL(h);
			if(n < nbmin){
				std::cerr << "ECHEC - II (" << test << " - " << n << ")" << std::endl;
				erreur++;
			}
		}
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
