#include <iostream>
using namespace std;

class Thing {
	public:
	Thing() : thisone(12){};
	int getThisone() { return thisone; }
	private:
	int thisone;
};
int main() {
	Thing th;
	cout << th.getThisone() << endl;
	cout << "Hello there" << endl;
	return 0;
}
