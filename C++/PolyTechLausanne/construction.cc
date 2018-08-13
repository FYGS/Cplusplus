#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  Brique (const Forme& f, const Couleur& c)
  : forme(f), couleur(c)
  {}

  ostream& afficher (ostream& sortie) const;


};

// Prototypes
ostream& operator<<(ostream& , Brique const&);

// Définitions
ostream& Brique::afficher (ostream& sortie) const {

  //sortie << "(" << forme;
  if(couleur != "") sortie << "(" << forme << ", " << couleur << ") "; // ou encore !couleur.empty()
  //sortie << ") ";
  else sortie << forme;

  return sortie;
}

ostream& operator<<(ostream& sortie, Brique const& b) {

  return b.afficher(sortie);
}


class Construction
{
  friend class Grader;
public:
  Construction (Brique b)
  : contenu(1, vector < vector <Brique > > (1,vector<Brique> (1, b)))
  {}

  ostream& afficher (ostream& sortie) const;

  Construction& operator^=(Construction const& );
  Construction& operator-=(Construction const& );
  Construction& operator+=(Construction const& );

private:
  vector<vector<vector<Brique> > > contenu; // 3D

};

// Prototypes
ostream& operator<<(ostream& , Construction const&);
const Construction operator^(Construction, Construction const& );
const Construction operator-(Construction, Construction const& );
const Construction operator+(Construction, Construction const&);

const Construction operator*(unsigned int n, Construction const& a);
const Construction operator/(unsigned int n, Construction const& a);
const Construction operator%(unsigned int n, Construction const& a);

// Définitions
ostream& Construction::afficher (ostream& sortie) const {

    size_t i(0), j(0), k(0);
    if(contenu.empty()) return sortie;
    else {
      for(i = contenu.size()-1; i >= 0 and i <= contenu.size() -1; --i) {
        sortie << "Couche " << i << " : " << endl;
        for(j = 0; j < contenu[i].size(); ++j) {
          for(k = 0; k < contenu[i][j].size(); ++k) {
            sortie << contenu[i][j][k];
        }
        sortie << endl;
      }
      //contenu.afficher(sortie);
      /*for(j=0; j < contenu.size()-1; j++) {
        for(k=0; k < contenu.size()-1; k++) {

        }
      }*/
      //sortie << endl;
    }

    return sortie;
    }
    

}

ostream& operator<<(ostream& sortie, Construction const& c) {
  return c.afficher(sortie);
}

const Construction operator^(Construction c, Construction const& autre) {
  return c ^= autre; // Utilise ^= deja défini
}

Construction& Construction::operator^=(Construction const& autre) {
  // Ajouer une brique sur une autre en hauteur
  size_t i(0), hauteur(0);

  // Recupérer la hauteur de la construction
  hauteur = autre.contenu.size();
  for(; i < hauteur; i++) {
    contenu.push_back(autre.contenu[i]); // Ajouter en hauteur uniquement
  }

  return *this;
}

Construction& Construction::operator-=(Construction const& autre) {
  // Ajouer une brique sur une autre en profondeur
  size_t i(0), j(0);
  size_t profondeur(0);

  if (autre.contenu.size() >= contenu.size()) // Seulement si la hauteur à ajouter est plus grande
  {
    // Recupérer la profondeur de la construction
  for (; i < autre.contenu.size(); ++i)
  {
    profondeur = autre.contenu[i].size();
    for (; j < profondeur; ++j)
    {
      contenu[i].push_back(autre.contenu[i][j]);  // Ajouter en profondeur uniquement
    }
  }
  }
  return *this;
}
const Construction operator-(Construction c, Construction const& autre) {
  return c -= autre;
}
Construction& Construction::operator+=(Construction const& autre) {
  // Ajouer une brique sur une autre en largeur
  size_t i(0), j(0), k(0);
  size_t largeur(0), profondeur(0);

  // Récupérer profondeur et largeur
  for (; i < autre.contenu.size(); ++i)
  {
    if (autre.contenu.size() >= contenu.size())
    {
      profondeur = autre.contenu[i].size();
    if (profondeur >= contenu[i].size()) // profondeur2 >= profondeur1
    {
      for (; j < profondeur; ++j)
    {
      largeur = autre.contenu[i][j].size();
      for (; k < largeur; ++k)
      {
        contenu[i][j].push_back(autre.contenu[i][j][k]);
      }
    }
    }
    }
  }

  return *this;
}
const Construction operator+(Construction c, Construction const& autre) {
  return c += autre;
}


const Construction operator*(unsigned int n, Construction const& a)
{
  unsigned int i(0);
  Construction b(a);
  for (; i < n; ++i)
  {
     b += a;
  }
  return b;
}

const Construction operator/(unsigned int n, Construction const& a)
{
  unsigned int i(0);
  Construction b(a);
  for (; i < n; ++i)
  {
    b ^= a;
  }
  return b;
}

const Construction operator%(unsigned int n, Construction const& a)
{
  unsigned int i(0);
  Construction b(a);
  for (; i < n; ++i)
  {
    b -= a;
  }
  return b;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;

  return 0;
}
