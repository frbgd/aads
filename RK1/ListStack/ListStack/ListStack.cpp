#include<iostream>
using namespace std;

class List {
public:
	int field;
	List *pNext;
	List *pPrev;
};

class Stack {
public:
	List *st;
	List *top;
	Stack(int number) {
		cout << "Initializing list with first value = " << number << endl;
		st = new List;
		st->field = number;
		st->pNext = nullptr;
		st->pPrev = nullptr;
		top = st;
	}
	void Push(int number) {
		cout << "push " << number << endl;
		List *temp = new List();
		temp->field = number;
		temp->pNext = nullptr;
		temp->pPrev = top;
		top->pNext = temp;
		top = top->pNext;
	}
	void Pop() {
		cout << "pop ";
		if (st->pNext == nullptr && st->pPrev == nullptr) {
			cout << "Last element!" << endl;
		}
		else {
			cout << top->field << endl;
			top = top->pPrev;
			top->pNext = nullptr;
		}
	}
	void Print() {
		cout << "List: ";
		for (List* p = st; p != nullptr; p = p->pNext)
			cout << p->field << " ";
		cout << endl;
		cout << "top: " << top->field << endl;
	}
};

int main() {
	Stack S(5);
	S.Print();
	S.Push(10);
	S.Print();
	S.Pop();
	S.Print();
	S.Push(7);
	S.Print();
	S.Push(100500);
	S.Print();
	S.Push(999);
	S.Print();
	S.Pop();
	S.Print();
	return 0;
}