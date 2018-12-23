#include <cstdlib>
#include <iostream>
using namespace std;

void InsertIntoArray(int* arr, int index, int number, int size) 
{
	for (int i = size - 1; i >= index; i--)
		arr[i + 1] = arr[i];
	arr[index] = number;
}

void DeleteFromArray(int* arr, int number, int size) 
{
	int i;
	for (i = 0; i < 10; i++) 
	{
		if (arr[i] == number)
			break;
	}
	for(int j = i; j< size; j++)
	{
		arr[j] = arr[j + 1];
	}
}

int main() 
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;
	int b;
	cin >> b;
	for (int i = 0; i < 10; i++) 
	{
		if (a[i] == b)
			cout << "Match " << b << " in " << i << " position" << endl;
	}
	int c, d;
	cin >> c;
	cin >> d;
	InsertIntoArray(a, d, c, 10);
	for (auto i : a)
		cout << i << " ";
	cout << endl;
	DeleteFromArray(a, c, 10);
	for (auto i : a)
		cout << i << " ";
	return 0;
}