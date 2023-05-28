#include "Jeu.hpp"

Jeu::Jeu() {
	// Contructeur de Liste devrait etre deja appele?
	//listeConcepteurs_ = {};
	titre_ = "";
	anneeSortie_ = 0;
	developpeur_ = "";
}

Jeu::Jeu(string titre, unsigned annneSortie, string developpeur) {
	titre_ = titre;
	anneeSortie_ = annneSortie;
	developpeur_ = developpeur;
}



// Besoin de destructeur?
Jeu::~Jeu() {

}





// Essaies pour fonction trouverConcepteur()

//template <typename Conteneur, typename PredicatUnaire>
//auto trouver_si2(const Conteneur& valeurs, const PredicatUnaire& critere)
//{
//	auto iter = std::ranges::find_if(valeurs, critere);
//	return (iter != valeurs.end()) ? *it : nullptr;
//	// Return: reference à smartPtr
//}
//
//template <typename Container, typename Predicate>
//auto findElement(const Container& container, Predicate pred)
//{
//	auto it = std::ranges::find_if(container, pred);
//	return (it != container.end()) ? &(*it) : nullptr;
//}