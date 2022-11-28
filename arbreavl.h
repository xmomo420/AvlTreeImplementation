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

        /**
         * Permet d'insérer l'élément passé en paramètre dans le noeud passé
         * par référence en paramètre.
         * @return true si l'élément à été insérer, false sinon.
         */
        bool inserer(Noeud*&, const T&);
        /**
         *
         * @return
         */
        bool contient(const Noeud *, const T&) const; //Binding references
        /**
         * Permet d'enlever l'élément passé en paramètre du noeud passé en
         * paramètre.
         * @return true si l'élément à été enlevé du noeud, false si
         * l'élément n'est pas contenu dedans.
         */
        bool enlever(Noeud *&, const T&);
        /**
        *  Effectue une rotation de la gauche vers la droite sur le noeud
        *  passé par référence en paramètre, ajuste également les indices
        *  d'équilibre affectés.
        */
        void rotationGaucheDroite(Noeud*&);
        /**
         *  Effectue une rotation de la droite vers la gauche sur le noeud
         *  passé par référence en paramètre, ajuste également les indices
         *  d'équilibre affectés.
         */
        void rotationDroiteGauche(Noeud*&);
        /**
         * Permet de trouver l'élément de plus élément le plus supérieur dans
         * le noeud passé en paramètre.
         * @return l'élément trouvé.
         */
        const T& trouverMax(Noeud*&) const;
        /**
         *  Vide le noeud passé en paramètre.
         */
        void vider(Noeud*&);
        /**
         *  Copie le noeud passé en paramètre dans la référence d'un noeud
         *  qui est également passé en paramètre.
         */
        void copier(const Noeud*, Noeud*&) const;
        /**
         * Vérifie si l'arbre passé en paramètre est égal à l'arbre courant,
         * c'est-à-dire s'ils ont le même nombre de noeuds et les mêmes
         * éléments.
         * @return true si les deux arbres sont égaux, false sinon.
         */
        bool equals(const ArbreAVL<T> &) const;   //Binding references


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
    copier(autre.racine, racine);
}

template <class T>
ArbreAVL<T>::~ArbreAVL() {
    vider(racine);
}

template <class T>
bool ArbreAVL<T>::vide() const {
	return racine == nullptr;
}

template <class T>
void ArbreAVL<T>::vider() {
    vider(racine);
    racine = nullptr;
}

template <class T>
bool ArbreAVL<T>::contient(const T& element) const
{
    return contient(racine, element);
}

template <class T>
void ArbreAVL<T>::inserer(const T& element)
{
    inserer(racine, element);
}

template <class T>
void ArbreAVL<T>::enlever(const T& element)
{
    if (racine != nullptr)
        enlever(racine, element);
}

template <class T>
ArbreAVL<T>& ArbreAVL<T>::operator=(const ArbreAVL& autre) {
    if(this != &autre ) {
        vider();
        copier(autre.racine, racine);
    }
    return *this;
}

template <class T>
bool ArbreAVL<T>::operator == (const ArbreAVL<T> & autre) const {
    return this == &autre || equals(autre);
}

template <class T>
typename ArbreAVL<T>::Iterateur ArbreAVL<T>::debut() const {
    Iterateur iter = Iterateur(*this);
    iter.courant = racine;
    while (iter.courant->gauche != nullptr) {
        iter.chemin.empiler(iter.courant);
        iter.courant = iter.courant->gauche;
    }
    return iter;
}

template <class T>
T & ArbreAVL<T>::operator[](const Iterateur & i) {
    assert(i);
    return i.courant->contenu;
}

template <class T>
const T & ArbreAVL<T>::operator[](const Iterateur & i) const {
    assert(i);
    return i.courant->contenu;
}

/************ Fonctions privées ***************/

template <class T>
bool ArbreAVL<T>::contient(const Noeud *noeud, const T& element) const {
    if (noeud != nullptr) {
        if (element == noeud->contenu)
            return true;
        if (element < noeud->contenu)
            return contient(noeud->gauche, element);
        else
            return contient(noeud->droite, element);
    } else
        return false;
}

template <class T>
void ArbreAVL<T>::copier(const Noeud* source, Noeud*& noeud) const
{
    if (source != nullptr) {
        noeud = new Noeud(source->contenu);
        noeud->equilibre = source->equilibre;
        copier(source->gauche, noeud->gauche);
        copier(source->droite, noeud->droite);
    }
}

template <class T>
bool ArbreAVL<T>::inserer(Noeud*& noeud, const T& element)
{
    if(noeud==nullptr)
    {
        noeud = new Noeud(element);
        return true;
    }
    if(element < noeud->contenu){
        if(inserer(noeud->gauche, element))
        {
            noeud->equilibre++;
            if(noeud->equilibre == 0)
                return false;
            if(noeud->equilibre == 1)
                return true;
            assert(noeud->equilibre==2);
            if(noeud->gauche->equilibre == -1)
                rotationDroiteGauche(noeud->gauche);
            rotationGaucheDroite(noeud);
        }
        return false;
    }
    else if (noeud->contenu < element){
        if (inserer(noeud->droite, element)) {
            noeud->equilibre--;
            if (noeud->equilibre == 0)
                return false;
            if (noeud->equilibre == -1)
                return true;
            assert(noeud->equilibre == -2);
            if (noeud->droite->equilibre == 1)
                rotationGaucheDroite(noeud->droite);
            rotationDroiteGauche(noeud);
        }
        return false;
    }
    // element == noeud->contenu
    noeud->contenu = element;  // Mise à jour
    return false;
}

template <class T>
void ArbreAVL<T>::vider(Noeud*& noeud)
{
    if (noeud != nullptr) {
        if (noeud->gauche != nullptr)
            vider(noeud->gauche);
        if (noeud->droite != nullptr)
            vider(noeud->droite);
        delete(noeud);
    }
}

template <class T>
void ArbreAVL<T>::rotationGaucheDroite(Noeud*& racinesousarbre)
{
    Noeud *temp = racinesousarbre->gauche;
    int  ea = temp->equilibre;
    int  eb = racinesousarbre->equilibre;
    int  neb = -(ea>0 ? ea : 0) - 1 + eb;
    int  nea = ea + (neb < 0 ? neb : 0) - 1;

    temp->equilibre = nea;
    racinesousarbre->equilibre = neb;
    racinesousarbre->gauche = temp->droite;
    temp->droite = racinesousarbre;
    racinesousarbre = temp;
}

template <class T>
void ArbreAVL<T>::rotationDroiteGauche(Noeud*& racinesousarbre)
{
    Noeud *tmp = racinesousarbre->droite;
    int eb = tmp->equilibre;
    int ea = racinesousarbre->equilibre;
    int nea = -(eb < 0 ? eb : 0) + 1 + ea;
    int neb = (nea > 0 ? nea : 0) + 1 + eb;

    tmp->equilibre = neb;
    racinesousarbre->equilibre = nea;
    racinesousarbre->droite = tmp->gauche;
    tmp->gauche = racinesousarbre;
    racinesousarbre = tmp;
}

template<class T>
const T &ArbreAVL<T>::trouverMax(Noeud *& noeud) const {
    assert(noeud != nullptr);
    if (noeud->droite != nullptr)
        return trouverMax(noeud->droite);
    else return noeud->contenu;
}

template <class T>
bool ArbreAVL<T>::enlever(Noeud *&noeud, const T& element) {
    if (noeud != nullptr) {
        if (element < noeud->contenu) { // Cas de gauche
            bool retour = false;
            if (enlever(noeud->gauche, element)) {
                noeud->equilibre--;
                if (noeud->equilibre == -1) return false;   //  Correction labo : impossible que l'équilibre soit 1
                if (noeud->equilibre == 0) return true;
                assert(noeud->equilibre == -2); // Arbre déséquilibré, donc il faut le rééquilibrer avec des rotations.
                retour = noeud->droite->equilibre != 0;
                if (noeud->droite->equilibre == 1) rotationGaucheDroite
                            (noeud->droite);
                rotationDroiteGauche(noeud);
            }
            return retour;
        }
        if (element > noeud->contenu) { //Cas de droite
            bool retour = false;
            if (enlever(noeud->droite, element)) {
                noeud->equilibre++;
                if (noeud->equilibre == 1) return false;
                if (noeud->equilibre == 0) return true;
                assert(noeud->equilibre == 2);  // Arbre déséquilibré, donc il faut le rééquilibrer avec des rotations.
                retour = noeud->gauche->equilibre != 0;
                if (noeud->gauche->equilibre == -1) rotationDroiteGauche
                            (noeud->gauche);
                rotationGaucheDroite(noeud);
            }
            return retour;
        }
        //  Cas element == noeud->element
        Noeud *tmp = noeud;
        if (noeud->gauche == nullptr) { noeud = noeud->droite; delete(tmp);
            return true; }
        if (noeud->droite == nullptr) { noeud = noeud->gauche; delete(tmp);
            return true; }
        noeud->contenu = trouverMax(noeud->gauche);
        return enlever(noeud->gauche, noeud->contenu);
    } else
        return false;
}

template <class T>
bool ArbreAVL<T>::equals(const ArbreAVL<T> &autre) const {
    Iterateur iterThis = debut();
    Iterateur iterAutre = autre.debut();
    bool continu = true;
    while (continu && iterThis && iterAutre) {
        continu = contient(racine, autre[iterAutre]);
        ++iterAutre;
        ++iterThis;
    }
    return continu && !(iterAutre && !iterThis || !iterAutre && iterThis);
}

/************ Iterateur ***************/

template <class T>
ArbreAVL<T>::Iterateur::Iterateur(const ArbreAVL & a) : arbre_associe(a), courant(nullptr) {
}

template <class T>
ArbreAVL<T>::Iterateur::Iterateur(const Iterateur & i) : arbre_associe(i.arbre_associe), courant(i.courant) {
}

template <class T>
typename ArbreAVL<T>::Iterateur ArbreAVL<T>::Iterateur::operator++(int) {
    assert(courant);
    Iterateur duplication = Iterateur(*this);
    operator++();
    return duplication;
}


template <class T>
typename ArbreAVL<T>::Iterateur& ArbreAVL<T>::Iterateur::operator++() {
    assert(courant);
    Noeud *suivant = courant->droite;
    while (suivant) {
        chemin.empiler(suivant);
        suivant = suivant->gauche;
    }
    if (!chemin.vide())
        courant = chemin.depiler();
    else
        courant = nullptr;
	return *this;
}

template <class T>
ArbreAVL<T>::Iterateur::operator bool() const {
	return courant != nullptr;
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
