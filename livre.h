/*
 * Squelette minimal pour classe Livre du TP2.
 * TP2 -- Arbres AVL 
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 *
 */

#ifndef __LIVRE_H__
#define __LIVRE_H__

#include <sstream>
#include <ostream>

class Livre {
  /**** Vous n'avez pas le droit de modifier l'interface publique de cette classe ******/
  /**** Vous n'avez donc pas le droit d'ajouter des fonctions publiques ni de **********/
  /**** modifier les signatures des fonctions publiques ********************************/
  public:
		/* 
		 * Constructeur avec les paramètres (dans cet ordre) :
		 * 		isbn 		(valeur par défaut : 0)
		 * 		auteur	(valeur par défaut : "")
		 * 		titre		(valeur par défaut : "")
		 * 		total		(valeur par défaut : 0)
		 */
    Livre(unsigned long, std::string, std::string, int);
		/* 
		 * Constructeur avec une chaine de caractères de la
		 * forme :
		 * 		titre;isbn;auteur;total
		 *
		 * Pour des exemples, le fichier "exemple_librairie_a.txt"
		 */
    Livre(std::string &);
    Livre(const Livre &);
    ~Livre();
		/*
		 * Opérateur d'affectation. Les champs "titre", "auteur"
		 * doivent être écrasés.
		 * Si le Livre en paramètre a le même champs "isbn" que le 
		 * Livre courant, alors le champs "total" du Livre courant 
		 * sera incrémenté de la valeur du champs "total" du Livre
		 * en paramètre. Si non, les champs "isbn" et "total" seront
		 * également écrasés.
		 */
		Livre & operator = (const Livre &);

		/*
		 * Retourne le champ "total".
		 */
    int copies() const;
		/* 
		 * Opérateurs de comparaison. Ils sont basés sur le champs 
		 * "isbn". Deux Livres sont égaux, si leur champs "isbn" sont
		 * égaux. De même pour les autres opérateurs.
		 */
		bool operator == (const Livre & autre) const;
		bool operator != (const Livre & autre) const;
		bool operator < (const Livre & autre) const;
		bool operator > (const Livre & autre) const;
  
	private:
		unsigned long isbn;
		std::string auteur;
		std::string titre;
		int total;
    /**** Vous pouvez ajouter toute fonction privée nécessaire ***********/
    /**** N'oubliez pas d'expliquer son fonctionnement en commentaire ****/

	friend std::ostream & operator << (std::ostream &, const Livre &);
};

Livre::Livre(unsigned long i = 0, std::string a = "", std::string t = "", int s = 0) {
    isbn = i;
    auteur = a;
    titre = t;
    total = s;
}

Livre::Livre(std::string & ligne) {
    std::string sub = ligne;
    unsigned short indice = sub.find(';');
    titre = sub.substr(0, indice);
    sub = sub.substr(indice + 1);
    indice = sub.find(';');
    isbn = std::stol(sub.substr(0, indice));
    sub = sub.substr(indice + 1);
    indice = sub.find(';');
    auteur = sub.substr(0, indice);
    sub = sub.substr(indice + 1);
    indice = sub.find(';');
    total = std::stoi(sub.substr(0, indice));
}

Livre::Livre(const Livre & l) {
    isbn = l.isbn;
    auteur = l.auteur;
    titre = l.titre;
    total = l.total;
}

Livre::~Livre() {
}

int Livre::copies() const {
	return total;
}

Livre & Livre::operator = (const Livre & autre) {
    if (this != &autre) {
        auteur = autre.auteur;
        titre = autre.titre;
        if (*this == autre)
            total += autre.total;
        else {
            total = autre.total;
            isbn = autre.isbn;
        }
    }
	return * this;
}

bool Livre::operator == (const Livre & autre) const {
    return this == &autre || isbn == autre.isbn;
}

bool Livre::operator != (const Livre & autre) const {
    return this != &autre && isbn != autre.isbn;
}

bool Livre::operator < (const Livre & autre) const {
    return this != &autre && isbn < autre.isbn;
}

bool Livre::operator > (const Livre & autre) const {
    return this != &autre && isbn > autre.isbn;
}

std::ostream & operator << (std::ostream & os, const Livre & l) {
	os << l.isbn << " [ copies : " << l.total << " ]\n\t" << l.auteur << " - " << l.titre;
	return os;
}

#endif
