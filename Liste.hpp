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

	T operator[] (int index) {	// const ou non??
		return *elements_[index].get();
	}



	//TODO: M�thode pour ajouter un �l�ment � la liste

	// Pour size, on utilise le m�me nom que les accesseurs de la biblioth�que standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//TODO: M�thode pour changer la capacit� de la liste

	//TODO: M�thode pour trouver une �l�ment selon un crit�re (lambda).

private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les �l�ments de la liste.
	unique_ptr<shared_ptr<T>[]> elements_;

	//vector<unique_ptr<Item>> items;
	//auto unItem = make_unique<Item>();
	//items.push_back(move(unItem));
};



