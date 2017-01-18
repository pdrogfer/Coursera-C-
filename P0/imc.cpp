#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
class Patient {
private:
	double mon_poids;
	double ma_taille;
public:
	void init(double p, double t) {
		if (p > 0) {
			mon_poids = p;
		}
		else {
			mon_poids = 0.0;
		}
		if (t > 0) {
			ma_taille = t;
		}
		else {
			ma_taille = 0.0;
		}
	}
	void afficher() {
		cout << "Patient : " << mon_poids << " kg pour " << ma_taille << " m\n";
	}

	double poids() {
		return mon_poids;
	}

	double taille() {
		return ma_taille;
	}

	double imc() {
		if (ma_taille == 0) {
			return 0;
		}
		else {
			return mon_poids / (ma_taille * ma_taille);
		}
	}
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
