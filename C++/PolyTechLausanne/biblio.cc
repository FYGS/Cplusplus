#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
 /***************** Auteur ************************/
class Auteur {
public:
	Auteur (string const& nom, bool prime = false)
	: nom_(nom), prime_(prime)
	{}
	
	Auteur (Auteur const&) = delete; // Copie impossible
	
	const string getNom() const {
		return nom_;
	}
	
	bool getPrix() const {
		return prime_;
	}
	
private:
	const string nom_;
	bool prime_;
};

/***************** Oeuvre ************************/
size_t nb_oeuvre(0); // Variable globale

class Oeuvre {
	
	
	
public:
	Oeuvre (string const& titre, Auteur const& auteur, string langue)
	: titre_(titre), auteur_(auteur), langue_(langue)
	{
		++nb_oeuvre;
	}
	Oeuvre (Oeuvre const&) = delete; // Copie impossible !
	~Oeuvre () {
		cout << "L'oeuvre \"" << titre_ << ", " << auteur_.getNom() << ", en " << langue_ << "\" n'est plus disponible." << endl;
		--nb_oeuvre;
	}
	
	const string getTitre() const {
		return titre_;
	}
	const Auteur& getAuteur() const {
		return auteur_;
	}
	string getLangue() const {
		return langue_;
	}
	
	void afficher() const {
		cout << titre_ << ", " << auteur_.getNom() << ", en " << langue_ << endl;
	}
private:
	const string titre_;
	const Auteur& auteur_;
	string langue_;
};

/***************** Exemplaire ************************/
class Exemplaire {
public:
	Exemplaire (Oeuvre& oeuvre)
	: oeuvre_(oeuvre)
	{
		cout << "Nouvel exemplaire de : " << oeuvre_.getTitre() << ", " << (oeuvre_.getAuteur()).getNom() << ", en " << oeuvre_.getLangue() << endl;
	}
	
	Exemplaire (Exemplaire const& autre)
	: oeuvre_(autre.oeuvre_)
	{
		cout << "Copie d'un exemplaire de : " << oeuvre_.getTitre() << ", " << (oeuvre_.getAuteur()).getNom() << " en " << oeuvre_.getLangue() << endl;
	}
	
	~Exemplaire () {
		cout << "Un exemplaire de : " << oeuvre_.getTitre() << ", " << (oeuvre_.getAuteur()).getNom() << " en " << oeuvre_.getLangue() << " a été jeté !" << endl;
	}
	
	Oeuvre& getOeuvre () const {
		return oeuvre_;
	}
	
	void afficher() const {
		cout << "Exemplaire de : " << oeuvre_.getTitre() << ", " << (oeuvre_.getAuteur()).getNom() << ", en " << oeuvre_.getLangue() << endl;
	}
	
private:
	Oeuvre& oeuvre_;
};

/***************** Bibliotheque ************************/
class Bibliotheque {
public:
	Bibliotheque (string const& nom) 
	: nom_(nom)
	{
		cout << "La bibliotheque " << nom_ << " est ouverte !" << endl;
	}
	~Bibliotheque () {
		cout << "La bibliotheque " << nom_ << " ferme ses portes, et détruit ses exemplaires" << endl;
	}
	
	const string getNom() const {
		return nom_;
	}
	
	void stocker(Oeuvre& oeuvre, unsigned int n = 1) {
		unsigned int i = 0;
		while(i < n) {
		    Exemplaire expl = Exemplaire(oeuvre);
			exemplaires_.push_back(&expl);
			i++;
		}
	}
	
	void lister_exemplaires(string langue = "") {
		for(const auto& exempl : exemplaires_) {
			/* Si la langue est indiquée, 
			afficher uniquement les oeuvres correspondantes*/
			
			if((exempl->getOeuvre()).getLangue() == langue) {
				exempl->afficher();
		    }
		    else {
				exempl->afficher();	
			}
		}
	}
	size_t compter_exemplaires(Oeuvre& oeuvre) const {
		return nb_oeuvre;
	}
	void afficher_auteurs(bool aPrix = false) const {
		for(const auto& exempl : exemplaires_) {
			if(aPrix and ((exempl->getOeuvre()).getAuteur()).getPrix()) {
				cout << ((exempl->getOeuvre()).getAuteur()).getNom() << endl;
		    }
			else
				cout << ((exempl->getOeuvre()).getAuteur()).getNom() << endl;
			
		}
		
	}
	
private:
	const string nom_;
	vector <Exemplaire*> exemplaires_;
};

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les MisÃ©rables"           , a1, "franÃ§ais" ),
         o2("L'Homme qui rit"          , a1, "franÃ§ais" ),
         o3("Le Comte de Monte-Cristo" , a2, "franÃ§ais" ),
         o4("Zazie dans le mÃ©tro"      , a3, "franÃ§ais" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothÃ¨que " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs Ã  succÃ¨s sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
