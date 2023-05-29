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
	//TODO: Constructeurs et surcharges d'opérateurs
	Liste() {
		nElements_ = 0;
		capacite_ = 1;
		elements_ = make_unique<shared_ptr<T>[]>(capacite_);
	}

	// Constructeur de copie
	Liste(Liste &autreListe) {
		*this = autreListe;
	}
	// Surcharge d'opérateur =
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

	// Surcharge d'opérateur []
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
	//TODO: Méthode pour ajouter un élément à la liste
	void ajouterElement(const std::shared_ptr<T>& element) {
		if (nElements_ >= capacite_) {
			augmenterCapacite();
		}

		elements_[nElements_] = element;
		nElements_++;
	}
	
	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//TODO: Méthode pour changer la capacité de la liste
	void changerCapacite(unsigned int nouvelleCapacite)
	{
		if (nouvelleCapacite <= capacite_)
		{
			return;  // La nouvelle capacité doit être supérieure à l'ancienne
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

	//TODO: Méthode pour trouver une élément selon un critère (lambda).
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
	//TODO: Attribut contenant les éléments de la liste.
	unique_ptr<shared_ptr<T>[]> elements_;
};



