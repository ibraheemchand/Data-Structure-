#include <iostream>
#include <string>
using namespace std;

class node {
public:
	node* nextPtr;
	int data;

	node() {
		this->nextPtr = NULL;
		this->data = 0;

	}

	node(node* a, int n) {
		this->nextPtr = a;
		this->data = n;
	}
	node(int n) {
		this->nextPtr = NULL;
		this->data = n;
	}

};






class list {
public:
	node* head;


	list(int num) {
		node* n = new node(num);
		this->head = n;

	}


	void insertAtBegining(int num) {
		node* n = new node(this->head, num);
		this->head = n;

	}

	void insertAtEnd(int num) {
		node* temp = this->head;
		bool Loop = true;
		while (temp != NULL || Loop)
		{
			if (temp->nextPtr == NULL) {
				node* n = new node(num);
				temp->nextPtr = n;

				Loop = false;
				break;
			}

			else {
				temp = temp->nextPtr;
			}
		}

	}

	void scearch(list l, int targetcode) {

		node* temp = (l.head);
		bool Loop = true;
		while (temp != NULL || Loop)
		{
			if (temp->data == targetcode)
			{
				cout << "SuccessFully Found ! \n The course " << temp->data << endl;
			}


			if (temp->nextPtr == NULL) {
				Loop = false;
				cout << "Unfortunately Not Found !!!!!" << endl;
				break;
			}

			else {
				temp = temp->nextPtr;
			}
		}
	}

	void display() {
		node* tempp = this->head;
		bool Loop = true;
		while (tempp != NULL || Loop)
		{

			cout << tempp->data << "  ";
			if (tempp->nextPtr == NULL) {

				Loop = false;
				cout << endl;

				break;
			}

			else {
				tempp = tempp->nextPtr;
			}
		}

	}


	void displayCircular() {
		node* tempp = this->head;
		bool Loop = true;
		while (tempp != NULL || Loop)
		{

			cout << tempp->data << "  ";
			if (tempp->nextPtr == this->head) {

				Loop = false;
				cout << endl;

				break;
			}

			else {
				tempp = tempp->nextPtr;
			}
		}

	}


	int displayCircularSize() {
		node* tempp = this->head;
		bool Loop = true;
		int size = 0;
		while (tempp != NULL || Loop)
		{

			size++;
			if (tempp->nextPtr == this->head) {

				Loop = false;
				cout << endl;
				return size;
				break;
			}

			else {
				tempp = tempp->nextPtr;
			}
		}

	}


	void make_it_Circular() {
		node* tempp = this->head;
		bool Loop = true;
		while (tempp != NULL || Loop)
		{

			
			if (tempp->nextPtr == NULL) {

				tempp->nextPtr = head;
				break;
			}

			else {
				tempp = tempp->nextPtr;
			}
		}
	}



};





int main() {
	list l(1);
	l.insertAtEnd(2);
	l.insertAtEnd(3);
	l.insertAtEnd(4);
	l.insertAtEnd(5);
	l.insertAtEnd(6);

	l.display();

	l.make_it_Circular();
	l.displayCircular();

	int N=l.displayCircularSize();
	int K = 3;
	int wieLoop=0;
	node* temp = l.head;
	node* prev = NULL;
	while (temp!=temp->nextPtr) {
		
		if (wieLoop%3++)
		{	
			prev->nextPtr = temp->nextPtr;
			node* todel = temp;
			delete todel;

		}
		prev = temp;
		temp = temp->nextPtr;
		wieLoop++;

	}

	return 0;
}