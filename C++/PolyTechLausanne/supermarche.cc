#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Article {
public:
	Article(string const& article, double prix, bool solde = false)
	: nom_(article), prixUnitaire_(prix), solde_(solde)
	{}
	
	double prixUnitaire() const {
		return prixUnitaire_;
	}
	string nom() const {
		return nom_;
	}
	bool enSolde() const {
		return solde_;
	}
	/*void afficher() const {
		cout << nom_ << " : " prixUnitaire_ << " Euros ";
		if( solde_ ) cout << "(en action)" << endl;
	}*/
	
private:
	const string nom_;
	double prixUnitaire_;
	bool solde_;
};

// ======================================================================
class Achat {
public:
	Achat (Article const& article, unsigned int quantite = 1) 
	: article_(article), quantite_(quantite)
	{}
	
	double prixTotal () const {
		double prixTotal(article_.prixUnitaire() * quantite_);
		if(article_.enSolde()) prixTotal *= 0.5;
		return prixTotal;
	}
	
	void afficher() const {
		cout << article_.nom() << " : " 
			 << article_.prixUnitaire() << " x " 
			 << quantite_ << " = " << prixTotal() << " F";
		
		if (article_.enSolde()) cout << " (en action)" << endl;
		else cout << endl;
	}
	
	unsigned int quantite() const {
		return quantite_;
	}
	
private:
	const Article article_;
	const unsigned int quantite_;
};

// ======================================================================
class Caddie {
public:
	void remplir(Article const& article, unsigned int quantite = 1) {
		achats_.push_back(Achat(article, quantite));
	}
	
	double prixTotal() const {
		double prixTotal(0.0);
		for(const auto & achat : achats_){
			achat.afficher();
			prixTotal += achat.prixTotal();
		}
		return prixTotal;
	}
private:
	vector <Achat> achats_;
};

// ======================================================================
class Caisse {
public:
	Caisse(): total_(0.0) {}
	
	void afficher() const {
		cout << total_ << " F" << endl;
	}
	void scanner(Caddie const& caddie) {
		double montant(caddie.prixTotal());
		total_ += montant;
		cout << "-----" << endl;
		cout << "Total à payer : " 
		     << montant << " F." << endl;
		//cout << "========================================" << endl;
	}
private:
	double total_;
};

// ======================================================================
int main()
{
  // Les articles vendus dans le supermarché
  Article choufleur ("Chou-fleur extra"      ,  3.50 );
  Article roman     ("Les malheurs de Sophie", 16.50, true );
  Article camembert ("Cremeux 100%MG"        ,  5.80 );
  Article cdrom     ("C++ en trois jours"    , 48.50 );
  Article boisson   ("Petit-lait"            ,  2.50, true);
  Article petitspois("Pois surgeles"         ,  4.35 );
  Article poisson   ("Sardines"              ,  6.50 );
  Article biscuits  ("Cookies de grand-mere" ,  3.20 );
  Article poires    ("Poires Williams"       ,  4.80 );
  Article cafe      ("100% Arabica"          ,  6.90, true);
  Article pain      ("Pain d'epautre"        ,  6.90 );

  // Les caddies du supermarché, disons 3 ici
  vector<Caddie> caddies(3);

  // Les caisses du supermarché, disons 2
  vector<Caisse> caisses(2);

  // Les clients font leurs achats :
  // le second argument de la méthode remplir correspond à une quantité

  // remplissage du 1er caddie
  caddies[0].remplir(choufleur, 2);
  caddies[0].remplir(cdrom       );
  caddies[0].remplir(biscuits , 4);
  caddies[0].remplir(boisson  , 6);
  caddies[0].remplir(poisson  , 2);

  // remplissage du 2eme caddie
  caddies[1].remplir(roman        );
  caddies[1].remplir(camembert    );
  caddies[1].remplir(petitspois, 2);
  caddies[1].remplir(poires    , 2);

  // remplissage du 3eme caddie
  caddies[2].remplir(cafe     , 2);
  caddies[2].remplir(pain        );
  caddies[2].remplir(camembert, 2);

  // Les clients passent à la caisse :
  caisses[0].scanner(caddies[0]);
  cout << "=========================================" << endl;
  caisses[0].scanner(caddies[1]);
  cout << "=========================================" << endl;
  caisses[1].scanner(caddies[2]);
  cout << "=========================================" << endl;

  // Affichage du résultat des caisses
  cout << "Résultats du jour :" << endl;
  for (size_t i(0); i < caisses.size(); ++i) {
    cout << "Caisse " << i+1 << " : " ;
    caisses[i].afficher();
    cout << endl;
  }

  return 0;
}
