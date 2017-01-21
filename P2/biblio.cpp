#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
class Auteur {
    private:
        string nom;
        bool prix;
    public:
        Auteur(string n, bool p=false)
            : nom(n), prix(p) {}
        string getNom() {
            return nom;
        }
        bool getPrix() {
            return prix;
        }
};
class Oeuvre {
    private:
        string titre;
        Auteur& auteur;
        string langue;
    public:
        Oeuvre(string t, Auteur& a, string l) 
            : titre(t), auteur(a), langue(l) {}
        Oeuvre(const Oeuvre& o) = delete;
        ~Oeuvre() {
            cout << "L'oeuvre \"" << titre << ", " << auteur.getNom() << ", en " << langue << "\" n'est plus disponible." << endl;
        }
        string getTitre() {
            return titre;
        }
        Auteur& getAuteur() {
            return auteur;
        }
        string getLangue() {
            return langue;
        }
        void affiche() {
            cout << titre << ", " << auteur.getNom() << ", en" << langue << endl;
        }
};
class Exemplaire {
    private:
        Oeuvre& oeuvre_ref;
    public:
        Exemplaire(Oeuvre& o_ref) 
            : oeuvre_ref(o_ref) {
                cout << "Nouvel exemplaire de : " << oeuvre_ref.getTitre() << ", " << oeuvre_ref.getAuteur().getNom() << ", en" << oeuvre_ref.getLangue() << endl;
        }
        Exemplaire(const Exemplaire& exemplaire) 
            : oeuvre_ref(exemplaire.oeuvre_ref) {
                cout << "Copie d'un exemplaire de : " << oeuvre_ref.getTitre() << ", " << oeuvre_ref.getAuteur().getNom() << ", en" << oeuvre_ref.getLangue() << endl;
            }
        ~Exemplaire() {
            cout << "Un exemplaire de : \"" << oeuvre_ref.getTitre() << ", " << oeuvre_ref.getAuteur().getNom() << ", en" << oeuvre_ref.getLangue() << "\" a été jeté !"<< endl;
        }
        const Oeuvre& getOeuvre() {
            return oeuvre_ref;
        }
        void affiche() {
            cout << "Exemplaire de : " << oeuvre_ref.getTitre() << ", " << oeuvre_ref.getAuteur().getNom() << ", en" << oeuvre_ref.getLangue();
            
        }

};
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables"           , a1, "français" ),
         o2("L'Homme qui rit"          , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro"      , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
