#include <iostream>
using namespace std;

class Array {
public:
	int size;
	int capacity;
	int* arr;
	Array(int c) {
		size = 0;
		capacity = c;
		arr = new int[capacity];
	}
	void SearchInArray(int number) {
		cout << "Find " << number << " at place:" << endl;
		for (int i = 0; i < size; i++)
			if (arr[i] == number)
				cout << i << endl;
	}
	int* InsertIntoArrayEnd(int number) {
		cout << "InsertIntoArrayEnd " << number << endl;
		if (size == capacity) {
			capacity *= 2;
			int* newarr = new int[capacity];
			for (int i = 0; i < size; i++) {
				newarr[i] = arr[i];
			}
			newarr[size] = number;
			size++;
			delete[] arr;
			return newarr;
		}
		else {
			arr[size] = number;
			size++;
			return arr;
		}
	}
	int* InsertIntoArrayStart(int number) {
		cout << "InsertIntoArrayStart " << number << endl;
		if (size == capacity) {
			capacity *= 2;
			int* newarr = new int[capacity];
			newarr[0] = number;
			for (int i = 0; i < size; i++) {
				newarr[i+1] = arr[i];
			}
			size++;
			delete[] arr;
			return newarr;
		}
		else {
			for (int i = size - 1; i >= 0; i--) {
				arr[i + 1] = arr[i];
			}
			arr[0] = number;
			size++;
			return arr;
		}
	}
	int* InsertIntoArray(int number, int index) {
		cout << "InsertIntoArray " << number << " at place " << index << endl;
		if (size == capacity) {
			capacity *= 2;
			int* newarr = new int[capacity];
			newarr[index] = number;
			for (int i = index; i < size; i++) {
				newarr[i + 1] = arr[i];
			}
			size++;
			delete[] arr;
			return newarr;
		}
		else {
			for (int i = size - 1; i >= index; i--) {
				arr[i + 1] = arr[i];
			}
			arr[index] = number;
			size++;
			return arr;
		}
	}
	void PrintArray() {
		cout << "Array: ";
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl << "Capacity = " << capacity << endl;
	}
	void DeleteFromArrayEnd() {
		cout << "DeleteFromArrayEnd ";
		if (size == 0)
			cout << "arrayempty" << endl;
		else {
			cout << arr[size - 1] << endl;
			size--;
		}
	}
	void DeleteFromArrayStart() {
		cout << "DeleteFromArrayStart ";
		if (size == 0)
			cout << "arrayempty" << endl;
		else {
			cout << arr[0] << endl;
			for (int i = 1; i < size; i++)
				arr[i - 1] = arr[i];
			size--;
		}
	}
	void DeleteFromArray(int index) {
		cout << "DeleteFromArray by index " << index << endl;
		if (index >= size)
			cout << "out of range" << endl;
		else {
			for (int i = index; i < size; i++)
				arr[i] = arr[i + 1];
			size--;
		}
	}
	void DeleteFromArrayByNum(int number) {
		cout << "DeleteFromArrayByNum " << number << endl;
		int i;
		for (i = 0; i < size; i++)
			if (arr[i] == number)
				break;
		for (int j = i; j < size - 1; j++)
			arr[j] = arr[j + 1];
		size--;
	}
};


int main() {
	Array Arr(1);
	Arr.arr = Arr.InsertIntoArrayEnd(20);
	Arr.PrintArray();
	Arr.arr = Arr.InsertIntoArrayEnd(10);
	Arr.PrintArray();
	Arr.arr = Arr.InsertIntoArrayEnd(5);
	Arr.arr = Arr.InsertIntoArrayStart(10);
	Arr.arr = Arr.InsertIntoArrayEnd(0);
	Arr.PrintArray();
	Arr.arr = Arr.InsertIntoArrayStart(1);
	Arr.PrintArray();
	Arr.SearchInArray(3);
	Arr.SearchInArray(10);
	Arr.SearchInArray(0);
	Arr.DeleteFromArrayEnd();
	Arr.PrintArray();
	Arr.DeleteFromArrayByNum(20);
	Arr.PrintArray();
	Arr.DeleteFromArrayStart();
	Arr.DeleteFromArrayStart();
	Arr.PrintArray();
	Arr.InsertIntoArray(999, 1);
	Arr.PrintArray();
	Arr.DeleteFromArray(1);
	Arr.DeleteFromArray(100);
	Arr.DeleteFromArray(0);
	Arr.PrintArray();
	Arr.DeleteFromArrayStart();
	Arr.DeleteFromArrayStart();
	Arr.DeleteFromArrayEnd();
	Arr.DeleteFromArray(0);
	Arr.PrintArray();
	return 0;
}