#include <iostream>
#include <cmath>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
class Tirelire {
public:
	void vider();
	void secouer() const;
	void afficher() const;
	void puiser(double montant);
	void remplir(double montant);
	
	bool montant_suffisant(double, double&);
	double calculerSolde(double budget);
	double getMontant() const{
		return montant_;
	}
private:
	double montant_;
};

void Tirelire::afficher() const{
	cout << "Vous ";
	if(montant_ == 0.0)
		cout << "etes sans le sou." << endl;
	else
		cout << "avez : " << montant_ 
		<< " euros dans votre tirelire." << endl;
}
void Tirelire::secouer() const{
	if(montant_ != 0.0)
		cout << "Bing bing" << endl;
}
void Tirelire::remplir(double montant){
	if(montant > 0.0)
		montant_ += montant;
}
void Tirelire::vider(){
	if(montant_ != 0.0)
		montant_ = 0.0;
}
void Tirelire::puiser(double montant){
	if(montant > 0.0 and montant <= montant_)
		montant_ -= montant;
}
bool Tirelire::montant_suffisant(double budget, double& solde){
	if(montant_ > budget){
		if(budget > 0.0)
			solde = montant_ - budget; // Tirelire::puiser(budget);
		return true;
	}
	else{
		if(budget > 0.0)
			solde = abs(montant_ - budget); //abs(Tirelire::puiser(budget)); 
		return false;
	}
	if(budget <= 0.0){
		montant_ = solde;
		return true;
	} 
	
}
double Tirelire::calculerSolde(double budget){
	if(budget > 0.0)
		return montant_ - budget;
	else
		return montant_;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Tirelire piggy;

  piggy.vider();
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(20.0);
  piggy.secouer();
  piggy.afficher();

  piggy.remplir(550.0);
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(10.0);
  piggy.puiser(5.0);
  piggy.afficher();

  cout << endl;

  // le budget de vos vacances de rève.
  double budget;

  cout << "Donnez le budget de vos vacances : ";
  cin >> budget;

  // ce qui resterait dans la tirelire après les
  // vacances
  double solde(0.0);

  if (piggy.montant_suffisant(budget, solde)) {
    cout << "Vous êtes assez riche pour partir en vacances !"
         << endl
         << "Il vous restera " << solde << " euros"
         << " à la rentrée." << endl << endl;
    piggy.puiser(budget);
  } else {
    cout << "Il vous manque " << solde << " euros"
         << " pour partir en vacances !" << endl << endl;
  }
  return 0;
}
