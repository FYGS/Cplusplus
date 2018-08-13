#include <iostream>

using namespace std;

int main()
{
	int age(23);
	cout << "Votre age : ";
	cin >> age;
	
	// Calcul annee naissance
	int annee(1994);
	annee = 2018 - age;
	
	// Affichage
	cout << "Vous etes ne(e) en : " << annee << endl;
	
	return 0;
}
