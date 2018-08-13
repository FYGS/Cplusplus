#include <iostream>
//#include <cmath>

using namespace std;

int main()
{
	double poids(74.5);
	double taille(1.75);
	
	// Demander le poids et la taille à l'utilisateur
	cout << "Veuillez indiquer votre poids (en kg) : "
	     << endl;
	cin >> poids;
	
	cout << "Veuillez entrer votre taille (en m) :"
	     << endl;
	cin >> taille;
	
	// Calcul IMC
	double imc(poids / (taille * taille));
	
	// Affichage
	cout << "Pour "   << poids
		 << " kg et " << taille
		 << " m, l'IMC est de " << imc
		 << endl;
	
	
	return 0;
}

