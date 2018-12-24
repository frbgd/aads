#include<iostream>
using namespace std;

class List {
public:
	int field;
	List *pNext;
	List *pPrev;
};

class Queue {
public:
	List* qe;
	List* tail;
	Queue(int number) {
		cout << "Initializing list with first value = " << number << endl;
		qe = new List;
		qe->field = number;
		qe->pNext = nullptr;
		qe->pPrev = nullptr;
		tail = qe;
	}
	void Enqueue(int number) {
		cout << "enq " << number << endl;
		List *temp = new List();
		temp->field = number;
		temp->pNext = nullptr;
		temp->pPrev = tail;
		tail->pNext = temp;
		tail = tail->pNext;
	}
	void Dequeue() {
		cout << "deq ";
		if (qe->pNext == nullptr && qe->pPrev == nullptr) {
			cout << "Last element!" << endl;
		}
		else {
			cout << qe->field << endl;
			qe = qe->pNext;
			qe->pPrev = nullptr;
		}
	}
	void Print() {
		cout << "List: ";
		for (List* p = qe; p != nullptr; p = p->pNext)
			cout << p->field << " ";
		cout << endl;
		cout << "head: " << qe->field << endl;
		cout << "tail: " << tail->field << endl;
	}
};

int main() {
	Queue S(5);
	S.Print();
	S.Enqueue(10);
	S.Print();
	S.Dequeue();
	S.Print();
	S.Enqueue(7);
	S.Print();
	S.Enqueue(100500);
	S.Print();
	S.Enqueue(999);
	S.Print();
	S.Dequeue();
	S.Print();
	return 0;
}