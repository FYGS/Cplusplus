#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Compte {
public:
   // Constructeurs ~ Destructeur
	Compte(string const& nom, double taux):
	intitule_(nom), solde_(0.0), taux_(taux)
	{}
	/*Compte(Compte const& autre):
	intitule_(autre.intitule_), solde_(0.0), taux_(autre.taux_)
	{}
	~Compte() {}*/
	
	// Accesseurs
	const string& nom() const {
		return intitule_;
	}
	double solde() const {
		return solde_;
	}
	
	// Operations compte
	void crediter(double credit) {
		if(credit < 0.0) credit = 0.0;
		else solde_ += credit;
	}
	void debiter(double debit) {
		if(debit < 0.0) debit = 0.0;
		else solde_ -= debit;
	}
	void boucler() {
		crediter(solde_ * taux_);
	}
	void afficher() const {
		cout << "   Compte " << intitule_ << " : " << solde_ << " francs" << endl;
	}
	ostream& afficher(ostream& sortie) const {
		sortie << "   Compte " << intitule_ << " : " << solde_ << " francs" << endl;
		return sortie;
	}
	
private:
	const string intitule_;
	double solde_;
	double taux_;
};
ostream& operator<<(ostream& sortie, Compte const& autre) {
	return autre.afficher(sortie);
}

class Client {
public:
	Client(string const& nom, string const& ville, bool homme = true, double taux = 0.01):
	nom_(nom)
	// Tout client a au moins 1 CC
	, ville_(ville), homme_(homme), comptes_(1, Compte("courant", taux))
	{}
	
	//~Client() {}
	
	// Operations comptes
	void ouvrirUnCompte(const string& nom, double taux) {
		comptes_.push_back(Compte(nom, taux));
	}
	/*void supprimerUnCompte(const string& nom) {
		for(unsigned i = 0; i < comptes_.size(); ++i) {
			if(comptes_[i].nom_ == nom) {
				comptes_.erase(i);
			}
				
		}
	}*/
	
	void afficher() const {
		cout << "Client";
		if(not homme_) cout << 'e';
		 
		 cout << " " << nom_ << " de " << ville_ << endl;
		// Affichage des comptes du client
		for(const auto & compte : comptes_) {
			compte.afficher();
		}
	}
	ostream& afficher(ostream& sortie) const {
		sortie << "Client";
		if(not homme_) sortie << 'e';
		 
		 sortie << " " << nom_ << " de " << ville_ << endl;
		// Affichage des comptes du client
		for(const auto & compte : comptes_) {
			compte.afficher(sortie);
		}
		return sortie;
	}
	
	void boucler() {
		for(auto & compte : comptes_) {
			compte.boucler();
		}
	}
	void crediter(const string& nom, double credit) {
		for(auto& compte : comptes_) {
			if(compte.nom() == nom) {
				compte.crediter(credit);
				return;
			}
		}
	}
	void debiter(const string& nom, double debit) {
		for(auto& compte : comptes_) {
			if(compte.nom() == nom) {
				compte.debiter(debit);
				return;
			}
		}
	}
private:
	const string nom_;
	const bool homme_;
	string ville_;
	vector <Compte> comptes_;
};
ostream& operator<<(ostream& sortie, Client const& autre) {
	return autre.afficher(sortie);
}

class Banque {
public:
	void ajoutClient(Client& client) {
		clients_.push_back(&client);
	}
	void boucler() {
		for(auto& client : clients_) {
			client->boucler();
		}
	}
	void afficher() const {
		for(auto& client : clients_) {
			client->afficher();
		}
	}
	ostream& afficher(ostream& sortie) const {
		for(auto& client : clients_) {
			client->afficher(sortie);
		}
		return sortie;
	}
	
private:
	vector <Client*> clients_;
};
ostream& operator<<(ostream& sortie, Banque const& autre) {
	return autre.afficher(sortie);
}
// ============================================================================
int main() 
{
	Banque postale;
	
	Client fernand("Fernand", "Paris");
	postale.ajoutClient(fernand);
	fernand.crediter("courant", 100000.0);
	fernand.ouvrirUnCompte("epargne", 0.03);
	fernand.crediter("epargne", 3000000.0);
	
	Client rama("Rama", "Casa", false);
	postale.ajoutClient(rama);
	rama.crediter("courant", 10000.0);
	rama.ouvrirUnCompte("epargne", 0.03);
	rama.crediter("epargne", 300000.0);
	
	cout << "Données avant le bouclement des comptes :\n" << postale << endl;
	//postale.afficher();
	postale.boucler();
	cout << "Données apres le bouclement des comptes :\n" << postale << endl;
	//postale.afficher();
	
	return 0;
}
