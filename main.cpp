#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "Liste.hpp"
#include "Concepteur.hpp"
#include "Jeu.hpp"
#include "lectureFichierJeux.hpp"
#include <iostream>
#include <fstream>
using namespace std;

//TODO: Vos surcharges d'opérateur <<
ostream& operator<<(ostream& os, Concepteur& concepteur) {
	
	os << "\t" << concepteur.getNom() << ", " << concepteur.getAnneeNaissance() << ", " 
	<< concepteur.getPays()	<< endl;
	return os;
}

ostream& operator<<(ostream& os, Liste<Concepteur>& listeConcepteurs) {
	for (unsigned i = 0; i < listeConcepteurs.size(); i++) {
		os << *listeConcepteurs[i]; //??
	}
	return os;
}

ostream& operator<<(ostream& os, Jeu& jeu) { // const ??
	os << "Titre : " << jeu.getTitre()<< endl;
	os << "Parution : " << jeu.getAnneeSortie() << endl;
	os << "Developpeur: " << jeu.getDeveloppeur() << endl;
	os << "Concepteurs du jeu :" << endl;
	os << jeu.getListeConcepteurs() << endl;

	return os;
}


ostream& operator<<(ostream& os, Liste<Jeu>& listeJeux) {
	for (unsigned i = 0; i < listeJeux.size(); i++) {
		os << *listeJeux[i]; //??
	}
	return os;
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi(); 
	#pragma endregion
	
	Liste<Jeu> lj = creerListeJeux("jeux.bin");
	static const string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";
	

	//cout << lj[2]->getTitre() << endl;
	cout << lj;


	// Tester la méthode trouverConcepteur()
	string nom = "Yoshinori Kitase";
	shared_ptr<Concepteur> ptr1 = lj[0]->trouverConcepteur([](auto c) { return c.getNom() == "Yoshinori Kitase"; });
	shared_ptr<Concepteur> ptr2 = lj[1]->trouverConcepteur([](auto c) { return c.getNom() == "Yoshinori Kitase"; });

	cout << ptr1 << endl; 
	cout << ptr2 << endl; // C'est bien le même pointeur 

	// Tester la copie
	Jeu copieJeu = *lj[2];
	copieJeu.getListeConcepteurs()[2];  //= copieJeu.getListeConcepteurs()[0]; // shared_ptr<Concepteur> = shared_ptr<Concepteur>
	
	cout << "Jeu initial: " << endl;
	cout << *lj[2] << endl;
	cout << "Copie du jeu intial, avec changement: " << endl;
	cout << copieJeu << endl;
	cout << copieJeu.getListeConcepteurs()[2] << endl;



	//TODO: Les l'affichage et l'écriture dans le fichier devraient fonctionner.
	//cout << ligneSeparation << lj;
	//ofstream("sortie.txt") << lj;

	//TODO: Compléter le main avec les tests demandés.
	//TODO: S'assurer qu'aucune ligne de code est non couverte.
	//NOTE: Il n'est pas nécessaire de couvrir les getters/setters simples fournis; il faut tester si vous en ajoutez ou les modifiez.
	//NOTE: Pour Liste, qui est générique, on demande de couvrir uniquement pour Liste<Jeu>, pas pour tous les types.
}