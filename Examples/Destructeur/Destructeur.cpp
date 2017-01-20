#include <iostream>

using namespace std;

class Rectangle {
    private: 
        double* hauteur;
        double* largeur;
    public:
        Rectangle() : hauteur(new double(20.0)), largeur(new double(30.0)) {}
        /* destructor overriden, use it to delete variables that live 
         * in the instance. Destructors don't take parameters.
         */
        ~Rectangle() {
            delete hauteur;
            delete largeur;
            cout << "Boom!" << endl;
        }
};
int main() {
    {
    Rectangle r;
    cout << "working" << endl;

    }
    return 0;
}
