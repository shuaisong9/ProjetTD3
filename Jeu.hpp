#pragma once
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <string>
#include <memory>
#include <functional>

class Jeu
{
public:
	//TODO: un constructeur par d�faut et un constructeur param�tr�.
    Jeu() =default;
    Jeu(std::string titre, unsigned anneeSortie, std::string developpeur): titre_(titre),
    anneeSortie_(anneeSortie), developpeur_(developpeur){}

	const std::string& getTitre() const     { return titre_; }
	void setTitre(const std::string& titre) { titre_ = titre; }
	unsigned getAnneeSortie() const         { return anneeSortie_; }
	void setAnneeSortie(unsigned annee)     { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(const std::string& developpeur) { developpeur_ = developpeur; }

	//TODO: Pouvoir acc�der � la liste de concepteurs.
    Liste<Concepteur>& getConcepteur(){
		return concepteurs_;
    }


	//TODO: Votre m�thode pour trouver un concepteur selon un crit�re donn� par une lambda, en utilisant la m�thode de Liste.

	shared_ptr<Concepteur> trouverConcepteur(const function<bool(Concepteur)>& critere) {
		shared_ptr<Concepteur> ptrConcepteur = nullptr;
		for (int i = 0; i < concepteurs_.size(); i++) {
			if (critere(concepteurs_.getElement()[i])) {

			}
		}
	}

private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	//TODO: Attribut de la liste des concepteurs du jeu
    Liste<Concepteur> concepteurs_;

};

//shared_ptr<Concepteur> Jeu::trouverConcepteur(const function<bool(Concepteur)& critere))
