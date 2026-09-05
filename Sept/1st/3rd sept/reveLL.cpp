#include <iostream>
#include <string>
using namespace std;

class node {
public:
	node* nextPtr;
	int courseCode;
	string courseName;

	node() {
		this->nextPtr = NULL;
		courseCode = 00;
		courseName = "";
	}

	node(node* a, int cc, string cn) {
		this->nextPtr = a;
		courseCode = cc;
		courseName = cn;
	}
	node(int cc, string cn) {
		this->nextPtr = NULL;
		courseCode = cc;
		courseName = cn;
	}

};






class list {
public:
	node* head;


	list(int cc, string cn) {
		node *n = new node(cc, cn);
		this->head = n;

	}


	void insertAtBegining(int cc, string cn) {
		node *n = new node(this->head, cc, cn);
		this->head = n;

	}

	void insertAtEnd(list& l, int cc, string cn) {
		node *temp = l.head;
		bool Loop = true;
		while (temp != NULL || Loop)
		{
			if (temp->nextPtr == NULL) {
				node *n = new node(cc, cn);
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

		node *temp = (l.head);
		bool Loop = true;
		while (temp != NULL || Loop)
		{
			if (temp->courseCode == targetcode)
			{
				cout << "SuccessFully Found ! \n The course " << temp->courseCode << " -- " << temp->courseName << endl;
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

	void display(list l) {
		node *temp = l.head;
		bool Loop = true;
		while (temp != NULL || Loop)
		{

			cout << " The course " << temp->courseCode << " -- " << temp->courseName << endl;
			if (temp->nextPtr == NULL) {

				Loop = false;
				break;
			}

			else {
				temp = temp->nextPtr;
			}
		}
	}


	void displayOnlyIntegers(list l) {
		node *temp = l.head;
		bool Loop = true;
		while (temp != NULL || Loop)
		{

			cout << temp->courseCode <<" "  ;
			if (temp->nextPtr == NULL) {
				cout << endl;
				Loop = false;
				break;
			}

			else {
				temp = temp->nextPtr;
			}
		}

	}
















	
};







int main() {
	int cc;
	string cn = "";
	

list l(5,"");

l.insertAtBegining(4,"");
l.insertAtBegining(3,"");
l.insertAtBegining(2,"");
l.insertAtBegining(1,"");






l.displayOnlyIntegers(l);

	


	return 0;
}