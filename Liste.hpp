#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include "gsl/span"
#include "cppitertools/range.hpp"
using namespace std;


template <typename T>
class Liste
{
public:
	//TODO: Constructeurs et surcharges d'op�rateurs
	Liste() {
		nElements_ = 0;
		capacite_ = 1;
		elements_ = make_unique<shared_ptr<T>[]>(capacite_);
	}

	// Constructeur de copie
	Liste(Liste &autreListe) {
		*this = autreListe;
	}
	// Surcharge d'op�rateur =
	Liste& operator= (Liste& autreListe) {
		if (this != &autreListe) {
			nElements_ = autreListe.nElements_;
			capacite_ = autreListe.capacite_;

			//unique_ptr<shared_ptr<T>[]> newElements_ = make_unique<shared_ptr<T>[]>(capacite_);
			elements_ = make_unique<shared_ptr<T>[]>(capacite_);
			for (unsigned i = 0; i < nElements_; i++) {
				//shared_ptr<T> newElem = make_shared<T>(*autreListe.elements_[i]);
				elements_[i] = autreListe.elements_[i];
			}			
			return *this;
		}
	}

	// Surcharge d'op�rateur []
	shared_ptr<T> operator[] (unsigned index) const {	// const ou non??
		return elements_[index];
	}
	shared_ptr<T> operator[] (unsigned index) {	
		return elements_[index];
	}
		// Operateur = pour regler probleme de build: 
		// Attempting to reference a deleted function 
		// Constructeur de copie (?)

	//
	//TODO: M�thode pour ajouter un �l�ment � la liste
	void ajouterElement(const std::shared_ptr<T>& element) {
		if (nElements_ >= capacite_) {
			augmenterCapacite();
		}

		elements_[nElements_] = element;
		nElements_++;
	}
	
	// Pour size, on utilise le m�me nom que les accesseurs de la biblioth�que standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//TODO: M�thode pour changer la capacit� de la liste
	void changerCapacite(unsigned int nouvelleCapacite)
	{
		if (nouvelleCapacite <= capacite_)
		{
			return;  // La nouvelle capacit� doit �tre sup�rieure � l'ancienne
		}

		auto nouvelElements = make_unique<shared_ptr<T>[]>(nouvelleCapacite);
		for (unsigned int i = 0; i < nElements_; i++)
		{
			nouvelElements[i] = elements_[i]; // memes pointeurs -- c'est ca qu'on veut
		}

		elements_ = move(nouvelElements);
		capacite_ = nouvelleCapacite;
	}

	void augmenterCapacite()
	{
		unsigned int nouvelleCapacite = capacite_ * 2;
		changerCapacite(nouvelleCapacite);
	}

	//TODO: M�thode pour trouver une �l�ment selon un crit�re (lambda).
	shared_ptr<T> trouver(function <bool(T&)> critere) {
		for (unsigned i = 0; i < this->size(); i++) {
			if (critere(*elements_[i])) {		// 
				return elements_[i];
			}
		}
		// Si va trouve: return nullptr?
		return nullptr;
	}
	


private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les �l�ments de la liste.
	unique_ptr<shared_ptr<T>[]> elements_;
};



