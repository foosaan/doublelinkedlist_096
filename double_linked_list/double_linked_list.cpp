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
	
}