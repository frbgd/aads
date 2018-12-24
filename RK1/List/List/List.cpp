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
	if (temp->pNext != nullptr)
		temp->pNext->pPrev = temp;
	lst->pNext = temp;
}

void DeleteFromEnd(List *lst) {
	cout << "DeleteFromEnd ";
	if (lst == nullptr)
		cout << "emptylist" << endl;
	else if (lst->pNext == nullptr && lst->pPrev == nullptr) {
		cout << "Last element!" << endl;
	}
	else {
		List *p;
		for (p = lst; p->pNext != nullptr; p = p->pNext);
		cout << p->field << endl;
		if (p->pPrev != nullptr)
			p->pPrev->pNext = nullptr;
		delete p;
	}
}

List* DeleteFromStart(List *lst) {
	cout << "DeleteFromStart ";
	if (lst == nullptr) {
		cout << "emptylist" << endl;
		return lst;
	}
	else if (lst->pNext == nullptr && lst->pPrev == nullptr) {
		cout << "Last element!" << endl;
		return lst;
	}
	else {
		cout << lst->field << endl;
		List *temp;
		temp = lst->pNext;
		temp->pPrev = nullptr;
		delete lst;
		return temp;
	}
}

List* DeleteByNum(List* lst, int number) {
	cout << "DeleteByNumber " << number << endl;
	if (lst->pNext == nullptr && lst->pPrev == nullptr) {
		cout << "Last Element!" << endl;
		return lst;
	}
	else {
		List *p;
		for (p = lst; p->pNext != nullptr; p = p->pNext) {
			if (p->field == number) {
				if (p->pPrev == nullptr) {
					p = p->pNext;
					p->pPrev = nullptr;
					delete lst;
					return p;
				}
				else {
					if (p->pPrev != nullptr)
						p->pPrev->pNext = p->pNext;
					if (p->pNext != nullptr)
						p->pNext->pPrev = p->pPrev;
					delete p;
					break;
					return lst;
				}
			}
		}
		return lst;
	}
}

List* DeleteElement(List* lst) {
	cout << "DeleteElement ";
	if (lst == nullptr) {
		cout << "nullptr" << endl;
		return lst;
	}
	else if (lst->pNext == nullptr && lst->pPrev == nullptr) {
		cout << "Last Element!" << endl;
		return lst;
	}
	else if (lst->pPrev == nullptr) {
		cout << lst->field << endl;
		List *next = lst->pNext;
		next->pPrev = nullptr;
		delete lst;
		return next;
	}
	else {
		cout << lst->field << endl;
		List *next = lst->pNext;
		if (lst->pNext != nullptr)
			next->pPrev = lst->pPrev;
		delete lst;
		return next;
	}
}

List* Swap(List *head, List *lst1, List *lst2) {
	cout << "Swap " << lst1->field << " and " << lst2->field << endl;
	List *prev1, *prev2, *next1, *next2;
	prev1 = lst1->pPrev;
	next1 = lst1->pNext;
	prev2 = lst2->pPrev;
	next2 = lst2->pNext;
	if (lst2 == next1) {
		lst2->pNext = lst1;
		lst2->pPrev = prev1;
		lst1->pNext = next2;
		lst1->pPrev = lst2;
		next2->pPrev = lst1;
		if (lst1 != head)
			prev1->pNext = lst2;
	}
	else if (lst1 == next2) {
		lst1->pNext = lst2;
		lst1->pPrev = prev2;
		lst2->pNext = next1;
		lst2->pPrev = lst1;
		next1->pPrev = lst2;
		if (lst2 != head)
			prev2->pNext = lst1;
	}
	else {
		if (lst1 != head)
			prev1->pNext = lst2;
		lst2->pNext = next1;
		if (lst2 != head)
			prev2->pNext = lst1;
		lst1->pNext = next2;
		lst2->pPrev = prev1;
		if (next2 != nullptr)
			next2->pPrev = lst1;
		lst1->pPrev = prev2;
		if (next1 != nullptr)
			next1->pPrev = lst2;
	}
	if (lst1 == head)
		return(lst2);
	if (lst2 == head)
		return lst1;
	return head;
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
	L->pNext->pNext->pNext = DeleteElement(L->pNext->pNext->pNext);
	Print(L);
	L = DeleteFromStart(L);
	Print(L);
	InsertIntoEnd(L, 11);
	Print(L);
	L = DeleteByNum(L, 55);
	Print(L);
	L = DeleteByNum(L, 555);
	Print(L);
	L->pNext->pNext = DeleteElement(L->pNext->pNext);
	L = DeleteElement(L);
	Print(L);
	InsertIntoEnd(L, 200);
	Print(L);
	L = DeleteByNum(L, 11);
	Print(L);
	L = InsertIntoStart(L, 11);
	L = InsertIntoStart(L, 12);
	L = InsertIntoStart(L, 34);
	L = InsertIntoStart(L, 55);
	L = InsertIntoStart(L, 777);
	Print(L);
	L = Swap(L, L, L->pNext);
	Print(L);
	L = Swap(L, L->pNext->pNext->pNext, L);
	Print(L);
	L = Swap(L, L->pNext, L->pNext->pNext->pNext->pNext->pNext);
	Print(L);
	return 0;
}