/* 
 * Tests pour la classe Livre.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 *
 */

#include <iostream>
#include "livre.h"

int main() {
	int erreur = 0;
	std::cout << "Test unitaire #3" << std::endl;
	std::string s = "Hogfather;9780061050466;Terry Pratchett;20";
	Livre livre(s);
	Livre book = livre;
	if(book.copies() != 20) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	book = book;
	if(book.copies() != 20) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	book = livre;
	if(book.copies() != 40) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	book = livre;
	book = livre;
	book = livre;
	if(book.copies() != 100) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	if(livre.copies() != 20) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
	}
