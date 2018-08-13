#include <iostream>
#include <string>
using namespace std;

class Fleur {
public:
	Fleur(const string n, const string c):
	nom(n), couleur(c)
	{
		cout << nom << " fraichement cueillie" << endl;
	}
	Fleur(Fleur const& autre):
	nom(autre.nom), couleur(autre.couleur)
	{
		cout << "Fragile corolle taillee" << endl;
	}
	void eclore() const {
		cout << " veine de " << couleur << endl;
	}
	~Fleur () {
		cout << "qu'un simple souffle..." << endl;
	}
private:
	const string nom;
	const string couleur;

};

int main ()
{
Fleur f1("Violette", "bleu");
Fleur f2(f1);
cout << "dans un cristal ";
f2.eclore();
cout << "Donne un poème un peu fleur bleue" << endl
<< "ne laissant plus ";
return 0;
}
