#include "Concepteur.hpp"
#include "Liste.hpp"
#include "Jeu.hpp"
#include <memory>

using namespace std;


std::shared_ptr<Concepteur> chercherConcepteur(Liste<Jeu>& listeJeux, string nom)
{
    for (unsigned int i = 0; i < listeJeux.size(); i++)
    {
        shared_ptr<Jeu> ptrJeu = listeJeux[i];
        unsigned int nbreConcepteurs = ptrJeu->getListeConcepteurs().size();
        //
        for (unsigned int j = 0; j < nbreConcepteurs; j++)
        {
            shared_ptr<Concepteur> ptrConcepteur = ptrJeu->getListeConcepteurs()[j];
            if (ptrConcepteur->getNom() == nom)
            {
                return ptrConcepteur;
            }
        }
    }
    return nullptr;
}