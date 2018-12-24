#include <iostream>
using namespace std;

class HastTable {
public:
	int size;
	int *arr;
	HastTable(int n) {
		size = n;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = NULL;
	}
	void Insert(int number) {
		int index = number % size;
		cout << "Insert " << number << " into " << index << " place; ";
		for (int i = 0; i < size; i++) {
			if (!arr[index + i]) {
				cout << "in " << index + i << " place insereted" << endl;
				arr[index + i] = number;
				break;
			}
			cout << "place loaded" << endl;
		}
	}
	void Print() {
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};

int main() {
	HastTable HT(11);
	HT.Insert(11);
	HT.Print();
	HT.Insert(43);
	HT.Print(); HT.Insert(346);
	HT.Print(); HT.Insert(1123);
	HT.Print(); HT.Insert(777);
	HT.Print(); HT.Insert(13451);
	HT.Print(); HT.Insert(1);
	HT.Print(); HT.Insert(12);
	HT.Print(); HT.Insert(555);
	HT.Print(); HT.Insert(777);
	HT.Print(); HT.Insert(1488);
	HT.Print(); HT.Insert(1234567890);
	HT.Print(); HT.Insert(5);
	HT.Print(); HT.Insert(0);
	HT.Print(); HT.Insert(78);
	HT.Print(); HT.Insert(12);
	HT.Print(); HT.Insert(32);
	HT.Print(); HT.Insert(44);
	HT.Print(); HT.Insert(41);
	HT.Print();
	return 0;
}