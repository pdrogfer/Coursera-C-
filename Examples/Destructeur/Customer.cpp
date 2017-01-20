#include <iostream>

using namespace std;

class Customer {
    private:
        int id;
        double* money;
    public:
        Customer() = default;
        Customer(int id1, double* money1)
            : id(id1), money(money1)
        {}
        Customer(Customer const& _other) = default;
        ~Customer() {
            cout << "Id: " << id << " destroyed" << std::endl;
            *money = 0;
        }
        double getMoney() { return *money; }
        void addMoney(double amount) {
            *money += amount;
        }
        void display() { 
            cout << "Id: " << id << ", amount = " << *money << endl; 
        }
};

int main() {
    double money = 200.0;
    Customer c1;
    {
        Customer c2(2, &money);
        c1 = c2;
        c2.addMoney(100.0);
        c2.display();
    }
    if ( c1.getMoney() >= 200.0 ) {
        cout << "Has 200" << endl;
    }
    else {
        cout << "No 200" << endl;
    }
    c1.display();
    return 0;
}
