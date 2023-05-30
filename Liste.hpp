#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"
//version 2

template <typename T>
class Liste
{
public:
	//TODO: Constructeurs et surcharges d'op�rateurs
    Liste() = default;

	Liste(const Liste<T>& liste) {
		nElements_ = liste.size();
		capacite_ = liste.getCapacite();
		elements_ = liste.getElement;
	}

	shared_ptr<T[]> getElement() const { return elements_; }
	int getCapacite() { return capacite_ };
	int getNbElements() { return nElements_; }


	//ostream& operator<<(ostream& out, )

	shared_ptr<T> operator[](int index) const { return elements_[index]; }


	//TODO: M�thode pour ajouter un �l�ment � la liste
	void ajouterElement(unique_ptr<shared_ptr<T>[]> element) {
		if (nElements == capacite)
			changerCapacite(max(1, capacite * 2));
		elements[nElements++] = move(element);
	}
	
	friend ostream& operator <<(ostream& out, const Liste& eleList) {
		for (auto& i : range(eleList.size())) {
			out << eleList.elements[i]<<endl;
		}
	}

	// Pour size, on utilise le m�me nom que les accesseurs de la biblioth�que standard,
	//qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }


	//TODO: M�thode pour changer la capacit� de la liste
	void changerCapacite(unsigned nvcapacite) {
		auto nouvelle_liste = make_unique<shared_ptr<T>[]>(nvcapacite);
		if (elements != nullptr) {
			nElements = min(nvcapacite, nElements_) { //this is working
				for (int i = 0; i < nElements_; i++) {
					nouvelle_liste = move(elements_[i]);
				}
			}
		}
		elements_ = move(nvcapacite);
		capacite_ = nvcapacite;
	}

	//shared_ptr<T> operator[] (unsigned int index) const { return elements_[index];}

	shared_ptr <T> trouverElement(const Liste<T>& liste, const function<bool(T)>& critere) {
		shared_ptr<T> ptr = nullptr;
		for (int i = 0; i < liste.size(); i++) {
			if (critere(liste.getElement()[i])) {
				ptr = liste.getElement()[i];
			}
		}
		return ptr;
	}


	//TODO: M�thode pour trouver une �l�ment selon un crit�re (lambda).
	
	size_t nElements = 0;
	size_t capacite = 0;

private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les �l�ments de la liste.
    //unique_ptr<shared_ptr<T>[]> elements_; 
	shared_ptr<T [] > elements_;
};


