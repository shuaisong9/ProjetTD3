// Fonctions pour lire le fichier binaire.
#include "lectureFichierJeux.hpp"
#include <fstream>
#include "cppitertools/range.hpp"
using namespace std;

#pragma region "Fonctions de lecture de base"
UInt8 lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}
#pragma endregion



shared_ptr<Concepteur> chercherConcepteur(Liste<Jeu>& listeJeux, string nom)
{
	for (unsigned int i = 0; i < listeJeux.size(); i++)
	{
		shared_ptr<Jeu> ptrJeu = listeJeux[i];
		unsigned int nbreConcepteurs = ptrJeu->getListeConcepteurs().size();
		//
		for (unsigned int j = 0; j < nbreConcepteurs; j++)
		{
			shared_ptr<Concepteur> ptrConcepteur = ptrJeu->getListeConcepteurs()[j]; // ??
			if (ptrConcepteur->getNom() == nom)
			{
				return ptrConcepteur;
			}
		}
	}
	return nullptr;
}

shared_ptr<Concepteur> lireConcepteur(Liste<Jeu>& lj, istream& f)
{
	string nom = lireString(f);
	unsigned anneeNaissance = lireUint16(f);
	string pays = lireString(f);

	//TODO: Compl�ter la fonction (�quivalent de lireDesigner du TD2).
	shared_ptr<Concepteur> concepteurExistant = chercherConcepteur(lj, nom);
	if (concepteurExistant != nullptr) {
		return concepteurExistant;
	}
	else {
		shared_ptr<Concepteur> newConcepteur = make_shared<Concepteur>(nom, anneeNaissance, pays);
		return newConcepteur;
	}
	//cout << "C: " << nom << endl;  //TODO: Enlever cet affichage temporaire servant � voir que le code fourni lit bien les jeux.
}



shared_ptr<Jeu> lireJeu(istream& f, Liste<Jeu>& lj)
{
	string titre          = lireString(f);
	unsigned anneeSortie  = lireUint16(f);
	string developpeur    = lireString(f);
	unsigned nConcepteurs = lireUint8(f);
	//TODO: Compl�ter la fonction (�quivalent de lireJeu du TD2).
	
	shared_ptr<Jeu> jeu = make_shared<Jeu>(titre, anneeSortie, developpeur);

	
	for (unsigned int i = 0; i < nConcepteurs; i++) {
		shared_ptr<Concepteur> concepteur = lireConcepteur(lj, f);
		jeu->getListeConcepteurs().ajouterElement(concepteur);
	}

	cout << "J: " << titre << endl;  //TODO: Enlever cet affichage temporaire servant � voir que le code fourni lit bien les jeux.
	return jeu;
}


Liste<Jeu> creerListeJeux(const string& nomFichier)
{
	ifstream f(nomFichier, ios::binary);
	f.exceptions(ios::failbit);
	int nElements = lireUint16(f);
	//TODO: Compl�ter la fonction.
	Liste<Jeu> listeJeux;
	for ([[maybe_unused]] int i : iter::range(nElements)) {
		shared_ptr<Jeu> jeu = lireJeu(f, listeJeux);
		listeJeux.ajouterElement(jeu);
	}
	return listeJeux;
}


