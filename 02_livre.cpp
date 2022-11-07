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
	std::cout << "Test unitaire #2" << std::endl;
	std::string s1 = "When it's a jar: a novel;9781841497822;Tom Holt;20";
	std::string s2 = "Hogfather;9780061050466;Terry Pratchett;20";
	std::string s3 = "The Inheritance Trilogy: Includes: The Hundred Thousand Kingdoms, The Broken Kingdoms, The Kingdom Of Gods, The Awakened Kingdom;9780316334006;N. K. Jemisin;13";
	std::string s4 = "The Obelisk Gate;9780316229265;N. K. Jemisin;13";
	std::string s5 = "A confederation of valor: Valor's choice ;9780756403997;Tanya Huff;23";
	Livre liv1(s1);
	Livre liv2(s2);
	Livre liv3(s3);
	Livre liv4(s4);
	Livre liv5(s5);
	if(liv1 == liv2 || liv2 == liv1) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(liv1 < liv2 || liv3 < liv2 || liv4 > liv5) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	liv1 = liv5;
	if(liv1 != liv5) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	liv1 = liv2 = liv3 = liv4 = liv5;
	if(liv1 != liv2 || liv2 != liv3 || liv3 != liv4 || liv4 != liv5) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	if(liv2.copies() != 23 || liv3.copies() != 23 || liv4.copies() != 23 || liv5.copies() != 23) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(liv1.copies() != 46) {
		std::cerr << "ECHEC - VI" << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << "\t==> OK" << std::endl;
	return erreur;
	}
