#include <iostream>
#include <string>
using namespace std;

class Souris
{
  /*****************************************************
    ComplÃ©ter le code Ã  partir d'ici
  *******************************************************/
public:
	Souris (double poids, string const& couleur, unsigned int age = 0, const unsigned int esperance_vie = 36)
	: poids_(poids), couleur_(couleur), age_(age), esperance_vie_(esperance_vie)
	{
		cout << "Une nouvelle souris !" << endl;
	}
	Souris (Souris const& autre)
	: poids_(autre.poids_), couleur_(autre.couleur_), age_(autre.age_), esperance_vie_(4/5 * esperance_vie_)
	{
		cout << "Clonage d'une souris !" << endl;
		cloonee_ = true;
	}
	~Souris() {
		cout << "Fin d'une souris..." << endl;
	}
	
	void afficher() const {
		cout << "Une souris " << couleur_ ;
		if(estClonee()) cout << " , clonee, ";
		cout << " de " << age_ << " mois et pesant " << poids_ << " grammes" << endl;
	}
	
	const bool estClonee() const {
		return cloonee_;
	}
	
	void vieillir(unsigned int age = 1) {
		age_ +=  age;
		if(estClonee() and age_ > (esperance_vie_ / 2)) {
			couleur_ = "verte";
		}
	}
	void evolue() {
		 vieillir(esperance_vie_ - age_);
	}
	
	
private:
	double poids_;
	string couleur_;
	unsigned int age_;
	const unsigned int esperance_vie_;
	bool cloonee_ = false;
  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-Ãªtre...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();
  return 0;
}
