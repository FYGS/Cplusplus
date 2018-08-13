#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
// Classe Patient
class Patient {
public:
	void init(double poids, double taille){
		if(poids < 0.0) 
			poids =0.0;
		else 
			masse = poids;
		if(taille < 0.0) 
			taille = 0.0;
		else
			hauteur = taille;
	}
	void afficher() const {
		cout << "Patient : " <<  masse << " kg pour " 
		<< hauteur << " m" << endl;
	}
	double poids() const {
		return masse;
	}
	double taille() const {
		return hauteur;
	}
	double imc() const {
		if(hauteur == 0.0){
			return 0.0;
		}
		else{
			return masse / (hauteur * hauteur);
		}
	}
private:
	double masse;
	double hauteur;
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
