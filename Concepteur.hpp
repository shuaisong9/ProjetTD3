#pragma once
#include <string>

class Concepteur
{
public:
	//TODO: Un constructeur par d�faut et un constructeur param�tr�.
	Concepteur() {}
	Concepteur(string nom, unsigned anneeNaissance, string pays) { 
		nom_ = nom;
		anneeNaissance_ = anneeNaissance;
		pays_ = pays;			
	}



	const std::string& getNom() const     { return nom_; }
	void setNom(const std::string& nom)   { nom_ = nom; }
	int getAnneeNaissance() const         { return anneeNaissance_; }
	void setAnneeNaissance(int annee)     { anneeNaissance_ = annee; }
	const std::string& getPays() const    { return pays_; }
	void setPays(const std::string& pays) { pays_ = pays; }

private:
	std::string nom_;
	unsigned anneeNaissance_;
	std::string pays_;
};
