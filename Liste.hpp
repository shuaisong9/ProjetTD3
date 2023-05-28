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

	shared_ptr<T> operator[] (unsigned index) const {	// const ou non??
		return elements_[index];
	}
	shared_ptr<T> operator[] (unsigned index) {	// const ou non??
		return elements_[index];
	}
		// Operateur = pour regler probleme de build: 
		// Attempting to reference a deleted function 
		// Constructeur de copie (?)

	//
	//TODO: Méthode pour ajouter un élément à la liste
	//void ajouterElement(const std::shared_ptr<T>& element) {
	//	elements.push_back(element);
	//	nElements_++;
	//}
	
	// Pour size, on utilise le même nom que les accesseurs de la bibliothèque standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//TODO: Méthode pour changer la capacité de la liste

	//TODO: Méthode pour trouver une élément selon un critère (lambda).
	shared_ptr<T> trouver(function <bool(T&)> critere) {
		for (unsigned i = 0; i < this->size(); i++) {
			if (critere(*(*this)[i])) {		// 
				return (*this)[i];
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

	//vector<unique_ptr<Item>> items;
	//auto unItem = make_unique<Item>();
	//items.push_back(move(unItem));
};



