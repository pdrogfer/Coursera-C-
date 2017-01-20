#include <iostream>
#include <string>
using namespace std;

class Souris
{
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
    private:
        double poids;
        int age;
        string couleur;
        int esperance_vie;
        bool clonee;
    public:
        Souris(double weight, string color, int old = 0, int life_exp = 36)
            : poids(weight), couleur(color), age(old), esperance_vie(life_exp) {
                cout << "Une nouvelle souris !;" << endl;
            } 
        Souris(const Souris& souris)
            : esperance_vie(souris.esperance_vie * (4/5)) {
                cout << "Clonage d'un souris !;" << endl;
            }
        ~Souris() {
            // delete poids;
            // delete age;
            // delete couleur; 
            // delete esperance_vie;
            // delete clonee;
            cout << "Fin d'une souris...;" << endl;
        }
        void afficher() {
            if(clonee) {
            cout << "Une souris " << couleur << ", clonee, " << "de " << age << " mois et pesant " << poids << " grammes" << endl;
            }  else {
            cout << "Une souris " << couleur << "de " << age << " mois et pesant " << poids << " grammes" << endl;
            }
        }
        void viellir() {
            age += 1;
            if (clonee) {
                if (age > esperance_vie / 2) {
                    couleur = "green";
                }
            }
        }
        void evolue() {
            age = esperance_vie;
        }
        
  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

}; // fin de la classe Souris

int main()
{
  Souris s1(50.0, "blanche", 2);
  Souris s2(45.0, "grise");
  Souris s3(s2);
  // ... un tableau peut-être...
  s1.afficher();
  s2.afficher();
  s3.afficher();
  s1.evolue();
  s2.evolue();
  s3.evolue();
  s1.afficher();
  s2.afficher();
  s3.afficher();
  return 0;
}
