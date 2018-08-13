#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Complexe {
public:
	Complexe (const double r = 0.0, const double i = 0.0)
	: reelle_(r), imaginaire_(i)
	{}
	~Complexe () {}
	
	bool operator== (Complexe const& autre) const;
	Complexe& operator+= (Complexe const& autre);
	Complexe& operator-=(Complexe const& autre);
	Complexe& operator*=(Complexe const& autre);
	Complexe& operator/=(Complexe const& autre);
	
	Complexe operator+(Complexe const& autre) const;
	Complexe operator-(Complexe const& autre) const;
	Complexe operator*(Complexe const& autre) const;
	Complexe operator/(Complexe const& autre) const;
	
	ostream& afficher(ostream& sortie) const {
		sortie << "(" << reelle_ << ", " << imaginaire_ << ")";
		return sortie;
	}
	
	double getReelle() const {
		return reelle_;
	}
	double getImaginaire() const {
		return imaginaire_;
	}
	
private:
	double reelle_;
	double imaginaire_;
	
	void set_reelle(double x) { reelle_ = x; }
	void set_imaginaire(double y) { imaginaire_ = y; }
};

const Complexe operator+(const double, Complexe const& autre);
const Complexe operator-(const double, Complexe const& autre);
const Complexe operator*(const double, Complexe const& autre);
const Complexe operator/(const double, Complexe const& autre);

ostream& operator <<(ostream& sortie, Complexe const& autre);

int main()
{
	Complexe defaut;
	Complexe zero(0.0, 0.0);
	Complexe un(1.0, 0.0);
	Complexe i(0.0, 1.0);
	Complexe j;

	cout << zero << " ==? " << defaut;
		if (zero == defaut) cout << " oui" << endl;
		else cout << " non" << endl;
	cout << zero << " ==? " << i;
		if (zero == i) cout << " oui" << endl;
		else cout << " non" << endl;
	j = un + i;

cout << un << " + " << i << " = " << j << endl;
Complexe trois(un);
trois += un;
trois += 1.0;
cout << un << " + " << un << " + 1.0 = " << trois << endl;
Complexe deux(trois);
deux -= un;
cout << trois << " - " << un << " = " << deux << endl;
trois = 1.0 + deux;
cout << "1.0 + " << deux << " = " << trois << endl;
Complexe z(i*i);
cout << i << " * " << i << " = " << z << endl;
cout << z << " / " << i << " = " << z/i << " = ";
cout << (z/=i) << endl;
Complexe k(2.0,-3.0);
z = k;
z *= 2.0;
z *= i;
cout << k << " * 2.0 * " << i << " = " << z << endl;
z = 2.0 * k * i / 1.0;
cout << " 2.0 * " << k << " * " << i << " / 1 = " << z << endl;

	return 0;
}


bool Complexe::operator==(Complexe const& autre) const {
	return (getReelle() == autre.getReelle()) and (getImaginaire() == autre.getImaginaire());
}
Complexe& Complexe::operator+=(Complexe const& autre) {
	set_reelle(getReelle() + autre.getReelle()); // Usage de += en fonction de + (A définir)
	set_imaginaire(getImaginaire() + autre.getImaginaire());
	return *this;
}
Complexe& Complexe::operator-=(Complexe const& autre) {
	set_reelle(getReelle() - autre.getReelle()); // Usage de -= en fonction de - (A définir)
	set_imaginaire(getImaginaire() - autre.getImaginaire());
	return *this;
}
Complexe& Complexe::operator*=(Complexe const& autre) {
	const double val_reelle(getReelle()); // sauvegarde de la partie réelle
	
	set_reelle((getReelle() * autre.getReelle()) - (getImaginaire() * autre.getImaginaire())); // Usage de *= en fonction de * (A définir)
	set_imaginaire((val_reelle * autre.getImaginaire()) + (getImaginaire() * autre.getReelle()));
	return *this;
}
Complexe& Complexe::operator/=(Complexe const& autre) {
	const double val_reelle(getReelle()); // sauvegarde de la partie réelle
	const double denominateur( autre.getReelle() * autre.getReelle() + autre.getImaginaire() * autre.getImaginaire() );
	
	set_reelle( (getReelle() * autre.getReelle() + getImaginaire() * autre.getImaginaire()) / denominateur );
	set_imaginaire( (getReelle() * autre.getImaginaire() - val_reelle * autre.getImaginaire()) / denominateur );
	return *this;
}

Complexe Complexe::operator+(Complexe const& autre) const {
	return Complexe(*this) += autre;
}
Complexe Complexe::operator-(Complexe const& autre) const {
	return Complexe(*this) -= autre;
}
Complexe Complexe::operator*(Complexe const& autre) const {
	return Complexe(*this) *= autre;
}
Complexe Complexe::operator/(Complexe const& autre) const {
	return Complexe(*this) /= autre;
}


const Complexe operator+(const double d, Complexe const& autre) {
	return Complexe(d) + autre;
}
const Complexe operator-(const double d, Complexe const& autre) {
	return Complexe(d) - autre;
}
const Complexe operator*(const double d, Complexe const& autre) {
	return Complexe(d) * autre;
}
const Complexe operator/(const double d, Complexe const& autre) {
	return Complexe(d) / autre;
}

ostream& operator <<(ostream& sortie, Complexe const& autre) {
	return autre.afficher(sortie);
}



