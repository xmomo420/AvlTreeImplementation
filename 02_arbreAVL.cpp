/* 
 * Tests pour la classe ArbreAVL.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 *
 */

#include <iostream>
#include "arbreavl.h"

int main(){
	std::cout << "Test unitaire #2" << std::endl;
	int erreur = 0;
	ArbreAVL<int> arbre;
	if(arbre.contient(5)) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	int nombres[]{5, 1, 7, 2, 6};
	for(int n : nombres)
		arbre.inserer(n);
	if(arbre.taille() != 5) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	for(int n : nombres)
		if(!arbre.contient(n)) {
			std::cerr << "ECHEC - III (" << n << ")" << std::endl;
			erreur++;
		}
	for(int n : nombres) {
		arbre.inserer(n);
		if(arbre.taille() != 5) {
			std::cerr << "ECHEC - IV (" << n << ")" << std::endl;
			erreur++;
		}
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;    
}
