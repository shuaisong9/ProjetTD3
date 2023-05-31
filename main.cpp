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

ostream& operator<<(ostream& out, const Concepteur& c) {
	out << "Nom " << c.getNom() << "\t" << " Annee Naissance " << c.getAnneeNaissance() << "\t" << " Pays " << c.getPays() << "\t" << endl;
	return out;
}
/*
ostream& operator <<(ostream& out, Jeu& j) {
	out << "Titre " << j.getTitre() << "\t" << j.getAnneeSortie() << "\t" << j.getDeveloppeur() << "\n";
	for (int i = 0; j.getConcepteurs().size()) > i; i++ {

	}

}


ostream& operator<<(ostream& out, const Liste<Jeu>& listeJeux) {
	for (int i = 0; i < listeJeux.size(); i++) {
		out<<listeJeux.get
	}
}
*/


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

	//TODO: Les l'affichage et l'écriture dans le fichier devraient fonctionner.
	cout << ligneSeparation << lj;
	ofstream("sortie.txt") << lj;
	cout<<ligneSeparation<<endl;




	//TODO: Compléter le main avec les tests demandés.

	cout << "Titre a indice 1: " << lj[1]->titre<<endl;
	cout << "Nom de son Concepteur" << lj[2]->concepteurs[1]->nom << endl;
	
	shared_ptr<Concepteur> concep = lj[0]->trouverConcepteur("Yoshinori Kitase");

}
