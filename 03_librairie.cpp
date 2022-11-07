/* 
 * Tests pour la classe ArbreAVL.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 *
 */

#include "librairie.h"
#include <fstream>

int main() {
	int erreur = 0;
  std::cout << "Test unitaire #3" << std::endl;
	Librairie lib;
	std::ifstream lib_txt("exemple_librairie_a.txt");
	std::string ligne;
	while(std::getline(lib_txt, ligne)) {
		Livre livre(ligne);
		lib.inserer(livre);
  };
	std::string livre_str_1 = "The broom of the system;9784062061612;David Foster Wallace;19";
  Livre livre_1(livre_str_1);
	std::string livre_str_2 = "The Promise;9780399161490;Robert Crais;17";
  Livre livre_2(livre_str_2);
	std::string livre_str_3 = "The Broken Crown;9780886777401;Michelle West;12";
  Livre livre_3(livre_str_3);
	std::string livre_str_4 = "The Last Painting Of Sara De Vos;9781410490636;Dominic Smith;27";
  Livre livre_4(livre_str_4);
	std::string livre_str_5 = "Sunshine;9780425191781;Robin McKinley;13";
  Livre livre_5(livre_str_5);
	Librairie lib_bis = lib;
	lib.fusionner(lib_bis);
	if(!(lib == lib_bis)) {
		std::cerr << "ECHEC - I" << std::endl;
		erreur++;
	}
	if(!lib.contient(livre_1) || 
			!lib.contient(livre_2) || 
			!lib.contient(livre_3) || 
			!lib.contient(livre_4) || 
			!lib.contient(livre_5)) {
		std::cerr << "ECHEC - II" << std::endl;
		erreur++;
	}
	if(lib.total(livre_1) != 38 || 
		 	lib.total(livre_2) != 34 || 
			lib.total(livre_3) != 24 || 
			lib.total(livre_4) != 54 || 
			lib.total(livre_5) != 26) {
		std::cerr << "ECHEC - III" << std::endl;
		erreur++;
	}
	lib.fusionner(lib_bis);
	lib.fusionner(lib_bis);
	if(lib.total(livre_1) != 76 || 
		 	lib.total(livre_2) != 68 || 
			lib.total(livre_3) != 48 || 
			lib.total(livre_4) != 108 || 
			lib.total(livre_5) != 52) {
		std::cerr << "ECHEC - IV" << std::endl;
		erreur++;
	}
	if(!(lib == lib_bis)) {
		std::cerr << "ECHEC - V" << std::endl;
		erreur++;
	}
	if(erreur == 0)
    std::cout << "\t==> OK" << std::endl;
  return erreur;
}

