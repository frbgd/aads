#include<iostream>
using namespace std;

class Queue {
public:
	int length;
	int tail;
	int head;
	int* qe;
	bool inverse;
	Queue(int l) {
		length = l;
		tail = 0;
		head = 0;
		inverse = false;
		qe = new int[length];
	}
	void Enqueue(int number) {
		cout << "enq " << number << endl;
		if (tail == head && inverse)
			cout << "queueoverflow" << endl;
		else {
			qe[tail] = number;
			if (tail == length - 1)
			{
				tail = 0;
				inverse = true;
			}
			else 
				tail++;
		}
	}
	void Dequeue() {
		cout << "deq ";
		if (tail == head && !inverse)
			cout << "queueempty" << endl;
		else {
			cout << qe[head] << endl;
			if (head == length - 1) {
				head = 0;
				inverse = false;
			}
			else
				head++;
		}
	}
	void Print() {
		int i = head;
		do{
			if (tail == head && !inverse) {
				cout << "queueempty";
				break;
			}
			if (i != length - 1) {
				cout << qe[i] << " ";
				i++;
			}
			else {
				cout << qe[i] << " ";
				i = 0;
			}
		}while (i != tail);
		cout << endl;
	}
};

int main() {
	Queue Q(5);
	Q.Print();
	Q.Enqueue(1);
	Q.Print();
	Q.Enqueue(3);
	Q.Print();
	Q.Dequeue();
	Q.Print();
	Q.Enqueue(2);
	Q.Enqueue(99);
	Q.Enqueue(100);
	Q.Print();
	Q.Enqueue(100500);
	Q.Print();
	Q.Enqueue(1);
	Q.Print();
	Q.Dequeue();
	Q.Dequeue();
	Q.Dequeue();
	Q.Dequeue();
	Q.Print();
	Q.Dequeue();
	Q.Dequeue();
	Q.Print();
	return 0;
}