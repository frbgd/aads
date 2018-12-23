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

void Print(List* lst) {
	cout << "List: ";
	for (List* p = lst; p != nullptr; p = p->pNext)
		cout << p->field << " ";
	cout << endl;
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

List* InsertIntoStart(List* lst, int number) {
	cout << "InsertIntoStart " << number << endl;
	List *temp = new List();
	temp->field = number;
	temp->pNext = lst;
	temp->pPrev = nullptr;
	lst->pPrev = temp;
	return temp;
}
void Insert(List* lst, int number) {
	cout << "Insert " << number << endl;
	List *temp = new List();
	temp->field = number;
	temp->pNext = lst->pNext;
	temp->pPrev = lst;
	lst->pNext->pPrev = temp;
	lst->pNext = temp;
}

int main() {
	List * L = init(5);
	Print(L);
	InsertIntoEnd(L, 10);
	Print(L);
	L = InsertIntoStart(L, 11);
	Print(L);
	Insert(L->pNext, 555);
	Print(L);
	return 0;
}