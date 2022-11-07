/* 
 * Squelette minimal pour classe générique ArbreAVL<T> du TP2.
 * TP2 -- Arbres AVL
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 *
 */

#ifndef __ARBREAVL_H__
#define __ARBREAVL_H__

#include <assert.h>
#include "pile.h"

template <class T>
class ArbreAVL {
	/**** Vous n'avez pas le droit de modifier l'interface publique de cette classe ******/
  /**** Vous n'avez donc pas le droit d'ajouter des fonctions publiques ni de **********/
  /**** modifier les signatures des fonctions publiques ********************************/
	/**** Ça s'applique également sur les fonctions publiques de le classe Itérateur *****/
  public:
    ArbreAVL();
    ArbreAVL(const ArbreAVL &);
    ~ArbreAVL();
		ArbreAVL<T> & operator = (const ArbreAVL<T> & autre);
		
		/*
		 * Fonctions vues en cours/laboratoire. Le fonctionnement à
		 * implémenter pour le TP2 est identiques.
		 */
		bool vide() const;
    void vider();
    bool contient(const T &) const;
    void inserer(const T &);
    void enlever(const T &);
   
		/*
		 * Retourne "true" si les arbres AVl ont exactement les mêmes 
		 * éléments peu importe l'ordre d'apparition dans les deux 
		 * arblres. Si non,  retourne "false".
		 *
		 ************************ ATTENTION **************************
		 * Cet opérateur doit être implémenté en O(min(m,n)).				 *
		 * Où n et m sont les tailles de deux arbres AVL à comparer. *
		 *************************************************************
		 */
    bool operator == (const ArbreAVL<T> & autre) const;
	
		/*
		 * Cet itérateur est basé sur un parcours inordre de l'arbre
		 * courant.
		 */
		class Iterateur;
		Iterateur debut() const;
		T & operator[] (const Iterateur &);
    const T & operator[] (const Iterateur &) const;
    
		/* 
		 * Ces fonctions sont implémentées à des fins de test et de diagnostique.
		 * Vous ne devez pas les utiliser dans vos implémentations, ni les modifier!
		 */
		int taille() const;
		int hauteur() const;
		int equilibre(const T &) const;
		int get_equilibre(const T &) const;
		int occurrence(const T &) const;
		void afficher() const;

	private:
		struct Noeud{
			Noeud(const T &);
			T contenu;
			int equilibre;
			Noeud * gauche;
			Noeud * droite;
		};
		Noeud * racine;
		/**** Vous pouvez ajouter toute fonction privée nécessaire **********************/
		/**** N'oubliez d'expliquer son fonctionnement en commentaire *******************/
		/**** Ça s'applique également sur les attributs privés de le classe Itérateur ***/

		/*
		 * Ces fonctions sont implémentées à des fins de test.
		 * Vous ne devez pas les utiliser dans vos implémentations, ni les modifier!
		 */
    int compter(Noeud *) const;
		Noeud * trouver(const T &) const;
	  int hauteur(Noeud * n) const;
		int occurrence(Noeud * n, const T &) const;
		void preparerafficher(const Noeud *, int, int &, T *, int *) const;

	public:
		class Iterateur {
			public:
				Iterateur(const Iterateur &);
				Iterateur(const ArbreAVL &);
				operator bool() const;
				Iterateur operator++(int);
				Iterateur & operator++();

			private:
				Noeud * courant;
				const ArbreAVL & arbre_associe;
				Pile<Noeud *> chemin;
				friend class ArbreAVL;
		};
};

/************ Fonctions publiques ***************/

template <class T>
ArbreAVL<T>::Noeud::Noeud(const T& c) : contenu(c), equilibre(0), gauche(nullptr), droite(nullptr) {
}

template <class T>
ArbreAVL<T>::ArbreAVL() : racine(nullptr) {
}

template <class T>
ArbreAVL<T>::ArbreAVL(const ArbreAVL<T> & autre) : racine(nullptr) {
	// À compléter
}

template <class T>
ArbreAVL<T>::~ArbreAVL() {
	// À compléter
}

template <class T>
bool ArbreAVL<T>::vide() const {
	// À compléter
	return false;
}

template <class T>
void ArbreAVL<T>::vider() {
	// À compléter
}

template <class T>
bool ArbreAVL<T>::contient(const T & element) const {
	// À compléter
	return false;
}

template <class T>
void ArbreAVL<T>::inserer(const T & e) {
	// À compléter
}

template <class T>
void ArbreAVL<T>::enlever(const T & e) {
	// À compléter
}

template <class T>
ArbreAVL<T> & ArbreAVL<T>::operator = (const ArbreAVL & autre) {
	// À compléter
	return *this;
}

template <class T>
bool ArbreAVL<T>::operator == (const ArbreAVL<T> & autre) const {
	// À compléter
	return false;
}

template <class T>
typename ArbreAVL<T>::Iterateur ArbreAVL<T>::debut() const {
	// À compléter
}

template <class T>
T & ArbreAVL<T>::operator[](const Iterateur & i) {
	// À compléter
}

template <class T>
const T & ArbreAVL<T>::operator[](const Iterateur & i) const {
	// À compléter
}

/************ Fonctions privées ***************/


/************ Iterateur ***************/

template <class T>
ArbreAVL<T>::Iterateur::Iterateur(const ArbreAVL & a) : arbre_associe(a), courant(nullptr) {
}

template <class T>
ArbreAVL<T>::Iterateur::Iterateur(const Iterateur & i) : arbre_associe(i.arbre_associe), courant(i.courant) {
}

template <class T>
typename ArbreAVL<T>::Iterateur ArbreAVL<T>::Iterateur::operator++(int) {
	// À compléter
	return *this;
}

template <class T>
typename ArbreAVL<T>::Iterateur& ArbreAVL<T>::Iterateur::operator++() {
	// À compléter
	return *this;
}

template <class T>
ArbreAVL<T>::Iterateur::operator bool() const {
	// À compléter
	return false;
}

/************ Fonctions de tests ***************/

#include <climits>

template <class T>
int ArbreAVL<T>::taille() const {
	return compter(racine);
}

template <class T>
int ArbreAVL<T>::hauteur() const {
	return hauteur(racine);
}

template <class T>
int ArbreAVL<T>::equilibre(const T & e) const {
	int equi = INT_MIN;
	if(contient(e)) {
		Noeud * n = trouver(e);
		equi = hauteur(n->gauche) - hauteur(n->droite);
	}
	return equi;
}

template <class T>
int ArbreAVL<T>::get_equilibre(const T & e) const {
	int equi = INT_MIN;
	if(contient(e)) {
		Noeud * n = trouver(e);
		equi = n->equilibre;
	}
	return equi;
}

template <class T>
int ArbreAVL<T>::occurrence(const T & e) const {
	return occurrence(racine, e);
}

template <class T>
int ArbreAVL<T>::compter(Noeud * n) const{
    if(n == nullptr) 
			return 0;
    return 1 + compter(n->gauche) + compter(n->droite);
}

template <class T>
typename ArbreAVL<T>::Noeud * ArbreAVL<T>::trouver(const T & e) const {
	Noeud * n = racine;
	while(n != nullptr && n->contenu != e) {
		if(n->contenu > e)
			n = n->gauche;
		else
			n = n->droite;
	}	
	return n;
}
   
template <class T>
int ArbreAVL<T>::hauteur(Noeud * n) const {
	if(n == nullptr)
		return 0;
	int g = hauteur(n->gauche);
	int d = hauteur(n->droite);
	return 1 + (g < d ? d : g);
}

template <class T>
int ArbreAVL<T>::occurrence(Noeud * n, const T & e) const {
	int o = 0;
	if(n != nullptr) {
		if(n->contenu == e)
			o++;
		o += occurrence(n->gauche, e) + occurrence(n->droite, e); 
	}
	return o;
}

#include <iostream>

template <class T>
void ArbreAVL<T>::afficher() const{
    std::cout << "Contenu de l'arbre (";
    int n = taille();
    std::cout << n << " noeuds)\n";
    T* elements = new T[n];
    int* profondeurs = new int[n];
    n=0;
    preparerafficher(racine, 0, n, elements, profondeurs);
    for(int p=0;;p++){
        bool derniereprofondeur = true;
        for(int i=0;i<n;i++){
            if(profondeurs[i]==p){
                std::cout << elements[i];
                derniereprofondeur = false;
            }
            std::cout << '\t';
        }
        std::cout << '\n';
        if(derniereprofondeur) break;
    }
    delete[] profondeurs;
    delete[] elements;
    std::cout << "-------------" << std::endl;
}

template <class T>
void ArbreAVL<T>::preparerafficher(const Noeud* n, int profondeur, int& rang, T* elements, int* profondeurs) const{
    if(n==nullptr) return;
    preparerafficher(n->gauche, profondeur+1, rang, elements, profondeurs);
    elements[rang] = n->contenu;
    profondeurs[rang] = profondeur;
    rang++;
    preparerafficher(n->droite, profondeur+1, rang, elements, profondeurs);
}

#endif
