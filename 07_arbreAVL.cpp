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
	std::cout << "Test unitaire #7" << std::endl;
	ArbreAVL<int> arbre1;
	arbre1.inserer(1);
	arbre1.enlever(2);
	if(!arbre1.contient(1) || arbre1.contient(2) || arbre1.taille() != 1){
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	arbre1.enlever(1);
	if(arbre1.contient(1) || arbre1.contient(2) || arbre1.taille() != 0){
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}

	arbre1.inserer(2);
	arbre1.inserer(1);
	arbre1.inserer(3);
	arbre1.inserer(4);
	arbre1.enlever(3);
	if(arbre1.contient(3) || !arbre1.contient(4) || arbre1.taille() != 3){
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	arbre1.enlever(1);
	if(arbre1.contient(1) || !arbre1.contient(2) || arbre1.taille() != 2){
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	arbre1.vider();
	arbre1.inserer(2);
	arbre1.inserer(1);
	arbre1.inserer(3);
	arbre1.enlever(1);
	if(arbre1.contient(1) || !arbre1.contient(2) || !arbre1.contient(3)|| arbre1.taille() != 2){
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	ArbreAVL<int> arbre;
	for(int i = 0; i < 20; i += 2)
		arbre.inserer(i);
	for(int i = 1; i < 20; i += 2)
		arbre.inserer(i);
	for(int i = 0; i < 20; i++)
		arbre.enlever(i);
	for(int i = 0; i < 20; i++)
	if(arbre.contient(i)){
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
}
