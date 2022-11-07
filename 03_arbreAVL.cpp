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
	std::cout << "Test unitaire #3" << std::endl;
	int erreur = 0;
	ArbreAVL<int> arbre;
	for(int i = 0; i < 10; i += 2)
		arbre.inserer(i);
	for(int i = 0; i < 10; i += 2)
		if(!arbre.contient(i)){
			std::cerr << "ECHEC - I (" << i << ")" << std::endl;
			erreur++;
		}
	for(int i = 1; i < 10; i += 2)
		if(arbre.contient(i)){
			std::cerr << "ECHEC - II (" << i << ")" << std::endl;
			erreur++;
		}
	for(int i = 1; i < 10; i += 2)
		arbre.inserer(i);

	for(int i = 0; i < 10; i++)
		if(!arbre.contient(i)){
			std::cerr << "ECHEC - III (" << i << ")" << std::endl;
			erreur++;
		}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
