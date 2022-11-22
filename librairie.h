/* 
 * Squelette minimal pour classe Librairie du TP2.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 *
 */

#ifndef __LIBRAIRIE_H__
#define __LIBRAIRIE_H__

#include "arbreavl.h"
#include "livre.h"
#include <string>

class Librairie {
	/**** Vous n'avez pas le droit de modifier l'interface publique de cette classe ******/
	/**** Vous n'avez donc pas le droit d'ajouter des fonctions publiques ni de **********/ 
	/**** modifier les signatures des fonctions publiques ********************************/
	public:
		Librairie();
		~Librairie();
		Librairie & operator = (const Librairie &);

		/* 
		 * Insérer un Livre dans la librairie.
		 * Si le livre existe déjà dans la librairie, augmenter
		 * son champ "total" avec le champ "total" du Livre reçu 
		 * en paramètre.
		 */
		void inserer(Livre &);
		/* 
		 * Retourner le champ "total" d'un objet de type Livre.
		 * Si le Livre n'est pas dans la librairie retourner 0.
		 */
		int total(Livre &) const;
		/*
		 * Retourne "true" si le Livre est dans la librairie, 
		 * "false" si non.
		 */
		bool contient(const Livre &) const;
		/* 
		 * Cherche un Livre avec le champ "isbn". Retourner
		 * le Livre s'il est dans la librairie, si non, 
		 * retourner un Livre vide (Constructeur par défaut de
		 * la classe Livre).
		 */
		Livre trouver(unsigned long) const;
		/*
		 * Fusionne 2 librairies en insérant les livres de la 
		 * librairie en paramètre dans la librairie courante.
		 */
		void fusionner(Librairie &);
		/* 
		 * Retoune "true" si la librairie courant a exactement
		 * les mêmes livres (on se base l'opérateur "==" de la 
		 * classe Livre) que la librairie en paramètre.
		 */
		bool operator == (const Librairie & autre) const;

	private:
		ArbreAVL<Livre> lib;
		/**** Vous pouvez ajouter toute fonction privée nécessaire ***********/
        /**** N'oubliez pas d'expliquer son fonctionnement en commentaire ****/

        Livre chercher(Livre &) const;


};

Librairie::Librairie() {
}

Librairie::~Librairie() {
}

Librairie & Librairie::operator = (const Librairie & autre) {
    if (this != &autre)
        lib = autre.lib;
	return * this;
}

void Librairie::inserer(Livre & l) {
	lib.inserer(l);
}

bool Librairie::contient(const Livre & l) const {
	return lib.contient(l);
}

int Librairie::total(Livre & l) const {
    return chercher(l).copies();
}

Livre Librairie::trouver(unsigned long l) const {
    Livre livre = Livre(l);
    ArbreAVL<Livre>::Iterateur iter = lib.debut();
    while (iter && lib[iter] != livre)
        ++iter;
    if (iter)
        return lib[iter];
    else {
        livre = Livre();
        return livre;
    }
}

void Librairie::fusionner(Librairie & bib) {
    ArbreAVL<Livre>::Iterateur iter = bib.lib.debut();
    while (iter) {
        lib.inserer(bib.lib[iter]);
        ++iter;
    }
}

bool Librairie::operator == (const Librairie & autre) const {
  return lib == autre.lib;
}

/************ Fonctions privées ***************/

Livre Librairie::chercher(Livre &livre) const {
    ArbreAVL<Livre>::Iterateur iter = lib.debut();
    while (iter && lib[iter] != livre)
        ++iter;
    if (iter)
        return lib[iter];
    else {
        Livre defaut = Livre();
        return defaut;
    }
}

#endif
