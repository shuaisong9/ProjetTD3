#pragma once
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <string>
#include <memory>
#include <functional>

using namespace std;

class Jeu
{
public:
	//TODO: un constructeur par défaut et un constructeur paramétré.
	Jeu() {
		titre_ = "";
		anneeSortie_ = 0;
		developpeur_ = "";
		//listeConcepteurs_ = 
	}

	Jeu(string titre, unsigned annneSortie, string developpeur) {
		titre_ = titre;
		anneeSortie_ = annneSortie;
		developpeur_ = developpeur;
	}

	// Constructeur de copie
	Jeu(Jeu& autreJeu) {
		titre_ = autreJeu.titre_;
		anneeSortie_ = autreJeu.anneeSortie_;
		developpeur_ = autreJeu.developpeur_;
		listeConcepteurs_ = autreJeu.listeConcepteurs_;
	}

	const std::string& getTitre() const     { return titre_; }
	void setTitre(const std::string& titre) { titre_ = titre; }
	unsigned getAnneeSortie() const         { return anneeSortie_; }
	void setAnneeSortie(unsigned annee)     { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(const std::string& developpeur) { developpeur_ = developpeur; }

	//TODO: Pouvoir accéder à la liste de concepteurs.
	Liste<Concepteur>& getListeConcepteurs() { return listeConcepteurs_; } // erased const before {}
		// Ajouter surchage d'operateur [] ??	
	
	//void ajouterConcepteur(const std::shared_ptr<Concepteur>& concepteur);


	//TODO: Votre méthode pour trouver un concepteur selon un critère donné par une lambda, en utilisant la méthode de Liste.
	shared_ptr<Concepteur> trouverConcepteur(function <bool(Concepteur&)> critere) {
		return listeConcepteurs_.trouver(critere);
	}


private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	//TODO: Attribut de la liste des concepteurs du jeu
	Liste<Concepteur> listeConcepteurs_;

};
