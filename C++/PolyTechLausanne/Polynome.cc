#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef size_t Degre;

class Polynome {
public:
    // Combinaison du constructeur par défaut
    // et du prologement des réels dans l'anneau des polynomes (1 argument)
	Polynome (double coeff = 0.0, Degre degre = 0)
	: polynome_(degre+1, 0.0) {
		polynome_[degre] = coeff; //p(3.0, 2) => 3X^2
	} 
	
	Degre degre() const { return polynome_.size() - 1; }
	void afficher_coef(ostream& sortie, Degre puissance, bool signe = true) const;
	
private:
	vector <double> polynome_;
	
};

ostream& operator<<(ostream& sortie, const Polynome& p);

int main() {
	Polynome p(3.2, 4);
	cout << "p=" << p << endl;
	return 0;
}

void Polynome::afficher_coef(ostream& sortie, Degre puissance, bool signe) const {
		double const c(polynome_[puissance]); // le coef de plus haut degré
		if(c != 0.0) {
			// signe == positif
			if(signe and (c > 0.0)) sortie << "+";
			sortie << c;
			if(puissance > 1)
				sortie << "*X^" << puissance;
			else if( puissance == 1) sortie << "*X";
		}
		else if(degre() == 0) { sortie << 0; }
}
	
ostream& operator<<(ostream& sortie, const Polynome& p) {
	// Pas de signe + devant le coef de plus haut degré
	Degre i(p.degre());
	p.afficher_coef(sortie, i, false);
	
	// Les autres coefs oui!
	// de N à 0 : +a*X^i
	if(i > 0) {
		for(i--; i > 0; i--) p.afficher_coef(sortie, i);
		p.afficher_coef(sortie, 0); // affiche le coef de rang 0
	}
	return sortie;
}
