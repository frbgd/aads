#include<iostream>
using namespace std;

class List {
public:
	int field;
	List *pNext;
	List *pPrev;
};

List * init(int a) {
	cout << "Initializing list with first value = " << a << endl;
	List *lst = new List;
	lst->field = a;
	lst->pNext = nullptr;
	lst->pPrev = nullptr;
	return lst;
}

void InsertIntoEnd(List* lst, int number) {
	cout << "InsertIntoEnd " << number << endl;
	List *temp = new List();
	temp->field = number;
	temp->pNext = nullptr;
	List *p;
	for (p = lst; p->pNext != nullptr; p = p->pNext);
	temp->pPrev = p;
	p->pNext = temp;
}


class HashTable {
public:
	int size;
	List** arr;
	HashTable(int n) {
		size = n;
		arr = new List*[size];
		for (int i = 0; i < size; i++) {
			arr[i] = new List();
			arr[i] = nullptr;
		}
	}
	void Insert(int number) {
		int index = number % size;
		if (arr[index] == nullptr)
			arr[index] = init(number);
		else {
			InsertIntoEnd(arr[index], number);
		}
	}
	void Print() {
		for (int i = 0; i < size; i++) {
			cout << i << ": ";
			for (List* p = arr[i]; p != nullptr; p = p->pNext)
				cout << p->field << " ";
			cout << endl;
		}
	}
};

int main() {
	HashTable HT(3);
	HT.Insert(1);
	HT.Print();
	HT.Insert(2);
	HT.Print(); HT.Insert(3);
	HT.Print(); HT.Insert(4);
	HT.Print(); HT.Insert(5);
	HT.Print(); HT.Insert(6);
	HT.Print(); HT.Insert(7);
	HT.Print(); HT.Insert(8);
	HT.Print(); HT.Insert(9);
	HT.Print(); HT.Insert(10);
	HT.Print(); HT.Insert(11);
	HT.Print(); HT.Insert(12);
	HT.Print();
	return 0;
}