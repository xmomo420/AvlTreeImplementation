/* 
 * Tests pour la classe ArbreAVL.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 *
 */

#include <iostream>
#include "arbreavl.h"

int main() {
	int erreur = 0;
	std::cout << "Test unitaire #8" << std::endl;
	ArbreAVL<int> arbre1;
	for(int i = 0; i < 20; i++)
		arbre1.inserer(i);
	ArbreAVL<int> arbre2;
	arbre2 = arbre1;
	for(int i = 0; i < 20; i++)
		if(!arbre2.contient(i)) {
			std::cerr << "ECHEC - I" << std::endl;
			erreur++;
		}
	ArbreAVL<int> arbre3;
	arbre2 = arbre3;
	for(int i = 0; i < 20; i++)
		if(arbre2.contient(i)) {
			std::cerr << "ECHEC - II" << std::endl;
			erreur++;
		}
	arbre1 = arbre1;
	if(arbre1.vide()) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	for(int i = 0; i < 20; i++)
	if(!arbre1.contient(i)){
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
