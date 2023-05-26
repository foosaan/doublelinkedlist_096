#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class doublelinkedlist {
private:
	Node* START = NULL;
public:
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

void doublelinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student :";
	cin >> nim;
	cout << "\nEnter the name of the student :";
	cin >> nm;

	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim; //step 2
	newNode->name = nm; //step2

	/*insert a node in the begining of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) { //check if data null
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //step 3
		if (START != NULL)
			START->prev = newNode; //step 4
		newNode->prev = NULL; //step 5
		START = newNode; //step6
		return;

	}
	/*intersting a node between two nodes in the list*/
	Node* current = START; //1.a
	Node* previous = NULL; //1.b
	while (current->next != NULL && current->next->noMhs < nim); //1.c
	{
		previous = current; //1.d
		current = current->next; //1.e
	}
	if (current->next != NULL && nim == current->next->noMhs)
	{
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}
	newNode->next = current->next; //step 4
	newNode->prev = current; // step 5
	if (current->next != NULL)
		current->next->prev = newNode; //step 6
	current->next = newNode; //step 7
}
bool doublelinkedlist::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL; // 1.a
	*previous = START; // 1.b
	while (*current != NULL && (*current)->noMhs != rollNo) // 1.c
	{
		*previous = *current; //1.d
		*current = (*current)->next; //1.e
	}
	return (*current != NULL);
}

bool doublelinkedlist::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		previous->next->prev = previous; //step2
	if (previous != NULL)
		previous->next = current->next; //step3
	else
		START = current->next;

	delete current; //step4
	return true;
}
bool doublelinkedlist::listEmpty() {
	return (START == NULL);
}

void doublelinkedlist::traverse() {
	if (listEmpty())
		cout << "\nlist is empty" << endl;
	else {
		cout << "\nRecord in ascedding order of roll number are : " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

