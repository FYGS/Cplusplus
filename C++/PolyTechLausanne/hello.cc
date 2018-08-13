#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "Hello world" << endl;
	
	int n(4); // Initialisation
	int n_carre; // la variable contient n'importe quoi en mémoire
	
	n_carre = n * n; // Affectation
	double x(1.0);
	
	const double vitesse_de_la_lumiere(300000); // Cette valeur ne pourra plus changer
	
	cout << "La variable n contient " << n << "." << endl;
	cout << "Le carre de n est " << n_carre << "." << endl;
	cout << "Entrer n : " << endl;
	cin >> n;
	
	cout << "La variable n contient " << n << "." << endl;
	cout << "Le carre de n est " << n_carre << "." << endl;
	return 0;
}
