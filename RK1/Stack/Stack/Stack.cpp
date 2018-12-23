#include <iostream>
using namespace std;

class Stack {
public:
	int size;
	int top;
	int* st;
	Stack(int size) {
		this->size = size;
		top = 0;
		st = new int[this->size];
	}
	void Push(int number) {
		cout << "push " << number << endl;
		if (top != size) {
			st[top] = number;
			top++;
		}
		else {
			cout << "stackoverflow" << endl;
		}
	}
	void Pop(){
		cout << "pop ";
		if (top != 0) {
			top--;
			cout << st[top] << endl;
		}
		else {
			cout << "stackempty" << endl;
		}
	}
	void Print() {
		cout << "stack: ";
		for (int i = 0; i < top; i++)
			cout << st[i] << " ";
		cout << endl;
	}
};

int main() {
	Stack St(5);
	St.Print();
	St.Push(5);
	St.Print();
	St.Push(10);
	St.Push(1);
	St.Push(2);
	St.Push(999);
	St.Print();
	St.Push(999);
	St.Pop();
	St.Pop();
	St.Print();
	St.Pop();
	St.Pop();
	St.Print();
	St.Pop();
	St.Pop();
	St.Pop();
	St.Print();
	return 0;
}