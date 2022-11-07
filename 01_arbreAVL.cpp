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
	std::cout << "Test unitaire #1" << std::endl;
	int erreur = 0;
	ArbreAVL<int> A;
	A.inserer(4);
	A.inserer(2);
	A.inserer(6);
	A.inserer(1);
	A.inserer(3);
	A.inserer(5);
	A.inserer(7);
	if(A.taille() != 7) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	A.inserer(3);
	A.inserer(3);
	A.inserer(6);
	A.inserer(6);
	A.inserer(6);
	A.inserer(3);
	A.inserer(3);
	A.inserer(3);
	if(A.taille() != 7) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	for(int i = 1; i <= 7; i++) {
		if(A.equilibre(i) != A.get_equilibre(i)) {
			std::cerr << "ECHEC - III (" << i << ")"<< std::endl;
			erreur++;
		}
		if(A.occurrence(i) != 1) {
			std::cerr << "ECHEC - IV (" << i << ")"<< std::endl;
			erreur++;
		}
	}
	ArbreAVL<int> B;
	int n = 10000;
	for(int i = 0; i < n; i++)
		B.inserer(i);

  if(B.taille() != n) {
    std::cerr << "ECHEC - V" << std::endl;
    erreur++;
  }
	for(int j = 0; j < 10; j++)
		for(int i = 0; i < n; i++)
			B.inserer(i);
  if(B.taille() != n) {
    std::cerr << "ECHEC - VI" << std::endl;
    erreur++;
  }
	for(int i = 0; i < n; i++)
		if(B.equilibre(i) != B.get_equilibre(i)) {
			std::cerr << "ECHEC - VII (" << i << ")"<< std::endl;
			erreur++;
		}
	for(int i = 0; i < n; i++)
		if(B.occurrence(i) != 1) {
			std::cerr << "ECHEC - VII (" << i << ")"<< std::endl;
			erreur++;
		}
	if(erreur == 0)
		std::cout << "\t==> OK"<< std::endl;
	return erreur;
}
