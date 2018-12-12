#include <iostream>

using namespace std;

int main() {
	short int a = -32001, b = -32001;
	while (a < -32000 || a > 32000)
		cin >> a;
	while (b < -32000 || b > 32000)
		cin >> b;
	cout << a + b;
	return 0;
}