#include <iostream>

using namespace std;

int main()
{
	const int BASE(4); // Nombre de convives de base
	double fromage(800.0); // quantité de fromage en grammes
	double eau(2.0); // quantité d'eau en dl
	double ail(2.0); // quantité de gousses d'ail
	double pain(400.0); // quantité de pain en grammes
	
	// L'utilisateur définit ses paramètres
	int nbConvives(BASE);
	cout << "Entrez le nombre de personne(s) conviees a la fondue : ";
	cin >> nbConvives;
	
	// Adaptation des nouvelles quantités
	double ratio = nbConvives;
	ratio = ratio / BASE;
	fromage *= ratio; // fromage = fromage * nbConvives / BASE;
	eau *= ratio;
	ail *= ratio;
	pain *= ratio;
	
	// Affichage recette
	cout << "Pour faire une fondue fribourgeoise pour "
	     << nbConvives
	     << " personnes, il vous faut : " << endl
	     << "- "
	     << fromage << " gr de Vacherin fribourgeois " << endl
	     << "- "
	     << eau << " dl d'eau " << endl
	     << "- "
	     << ail << " gousse(s) d'ail " << endl
	     << "- "
	     << pain << " gr de pain " << endl
	     << "- du poivre a volonte" << endl;
	
	return 0;
}
