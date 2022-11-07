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
	std::cout << "Test unitaire #1" << std::endl;
	std::string s = "When it's a jar: a novel;9781841497822;Tom Holt;20";
	Livre livre(s);
	if(livre.copies() != 20) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	std::string t = "When it's a jar: a novel";
	std::string a = "Tom Holt";
	unsigned long i = 9781841497822;
	int n = 40;
	Livre book(i, a, t, n);
	if(book.copies() != 40) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	if(!(book == livre) || !(livre == book)) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	Livre livre2(livre);
	if(livre2.copies() != 20) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	if(!(livre2 == livre) || !(livre == livre2)) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	Livre book2 = book;
	if(book2.copies() != 40) {
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	if(!(book == book2) || !(book2 == book)) {
		std::cerr << "ECHEC - VII" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
	}
