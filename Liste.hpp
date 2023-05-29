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

	shared_ptr<T> operator[] (unsigned index) const {	// const ou non??
		return elements_[index];
	}
	shared_ptr<T> operator[] (unsigned index) {	// const ou non??
		return elements_[index];
	}
		// Operateur de copie pour regler probleme de build: 
		// Attempting to reference a deleted function 

	//
	//TODO: M�thode pour ajouter un �l�ment � la liste
	void ajouterElement(const std::shared_ptr<T>& element) {
		elements.push_back(element);
		nElements_++;
	}

	// Pour size, on utilise le m�me nom que les accesseurs de la biblioth�que standard, qui permet d'utiliser certaines fonctions de la bibliotheque sur cette classe.
	unsigned size() const         { return nElements_; }
	unsigned getCapacite() const  { return capacite_; }

	//TODO: M�thode pour changer la capacit� de la liste

    void changerCapacite(int nouvelleCapacite){
        auto nouvelle_list = make_unique<T[]>(nouvelleCapacite);
        if(elements_!= nullptr){
            nElements_ = min(nouvelleCapacite, nElements_){
                for(int i=0; i<nElements_; i++){
                    nouvelle_list[i] = move(elements_[i]);
                }
            }
        }
        elements_ =move(nouvelleCapacite);
        capacite_ = nouvelleCapacite;
    }

	//TODO: M�thode pour trouver une �l�ment selon un crit�re (lambda).
	template <typename Conteneur, typename PredicatUnaire>
	auto trouverElement(const Conteneur& valeurs, const PredicatUnaire& critere)
	{
		auto iter = std::ranges::find_if(valeurs, critere);
		return (iter != valeurs.end()) ? *it : nullptr;
		// Return: reference � smartPtr
	}

	template <typename PredicatUnaire>
	auto trouverElement2(const PredicatUnaire& critere)
	{
		auto iter = std::ranges::find_if(elements_, critere);
		return (iter != elements_.end()) ? *it : nullptr;
		// Return: reference � smartPtr
	}


private:
	unsigned nElements_;
	unsigned capacite_;
	//TODO: Attribut contenant les �l�ments de la liste.
	unique_ptr<shared_ptr<T>[]> elements_;

	//vector<unique_ptr<Item>> items;
	//auto unItem = make_unique<Item>();
	//items.push_back(move(unItem));
};



