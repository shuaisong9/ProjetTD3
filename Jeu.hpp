#pragma once
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <string>
#include <memory>
#include <functional>

using namespace std;

class Concepteur;

class Jeu
{
public:
	//TODO: un constructeur par d�faut et un constructeur param�tr�.
	Jeu() 
	{
	}
	//Jeu(string titre, unsigned annneSortie, string developpeur);
	Jeu(const std::string& titre, unsigned anneeSortie, const std::string& developpeur) : titre_(titre), anneeSortie_(anneeSortie), developpeur_(developpeur)
	{
	}
	//~Jeu();

	const std::string& getTitre() const     { return titre_; }
	void setTitre(const std::string& titre) { titre_ = titre; }
	unsigned getAnneeSortie() const         { return anneeSortie_; }
	void setAnneeSortie(unsigned annee)     { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(const std::string& developpeur) { developpeur_ = developpeur; }

	//TODO: Pouvoir acc�der � la liste de concepteurs.
	 Liste<Concepteur>& getListeConcepteurs();
		// Ajouter surchage d'operateur [] ??	
	void ajouterConcepteur(const std::shared_ptr<Concepteur>& concepteur);


	//TODO: Votre m�thode pour trouver un concepteur selon un crit�re donn� par une lambda, en utilisant la m�thode de Liste.
	template <typename PredicatUnaire>
	auto trouverConcepteur(const PredicatUnaire& critere);


private:
	std::string titre_;
	unsigned anneeSortie_;
	std::string developpeur_;
	//TODO: Attribut de la liste des concepteurs du jeu
		// ptrIntelligent 
	Liste<Concepteur> listeConcepteurs_;

};
