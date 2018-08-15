#include <iostream>
#include <string>
#include <cmath>

#define BONUS

using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;
  

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	Flacon (const string& n, double v, double p)
	: nom(n), volume(v), pH(p)
	{}
	
	ostream& etiquette (ostream& sortie) const;
	Flacon& operator +=(const Flacon& );
	
	Flacon operator +(const Flacon& f2) const;
	
	string get_nom() const { return nom; }
	double get_volume() const { return volume; }
	double get_pH() const { return pH; }
	
	void set_nom(string n) { nom = n; }
	void set_volume(double v) { volume = v; }
	void set_pH(double p) { pH = p; }

};

ostream& operator <<(ostream& sortie, const Flacon& f);


ostream& operator <<(ostream& sortie, const Flacon& f) {
	return f.etiquette(sortie);
}

ostream& Flacon::etiquette (ostream& sortie) const {
	sortie << nom << " : " << volume << " ml, pH " << pH ; //<< endl;
	return sortie;
}

Flacon& Flacon::operator +=(const Flacon& f2) {
	double pH_melange(-log10( ( get_volume() * pow( 10.0, -get_pH() ) + f2.get_volume() * pow( 10.0, -f2.get_pH() ) ) / ( get_volume() + f2.get_volume() )  )) ;
	
	set_nom(get_nom() + " + " + f2.get_nom());
	set_volume(get_volume() + f2.get_volume());
	set_pH(pH_melange);
	
	return *this;
}

Flacon Flacon::operator +(const Flacon& f2) const {
	return Flacon(*this) += f2;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
