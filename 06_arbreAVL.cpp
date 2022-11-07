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
	std::cout << "Test unitaire #6" << std::endl;
	ArbreAVL<int> arbre;
	arbre.vider();
	if(!arbre.vide()){
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	arbre.inserer(2);
	if(arbre.vide()){
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	arbre.vider();
	if(!arbre.vide()){
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	arbre.inserer(2);
	arbre.inserer(3);
	arbre.inserer(1);
	if(arbre.vide()){
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	arbre.vider();
	if(!arbre.vide()){
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
