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



	bool boolScearchFOUND(list l, int targetcode) {

		node *temp = (l.head);
		bool Loop = true;
		while (temp != NULL || Loop)
		{
			if (temp->courseCode == targetcode)
			{
				return false;
			}


			if (temp->nextPtr == NULL) {
				Loop = false;
				return true;
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





};

int main() {
	int cc;
	string cn = "";
	int choice = 0;



	cout << " Add the Product code (like :101)" << endl;
	cin >> cc;
	cin.ignore();
	cout << "Enter The Product Name" << endl;
	cin >> cn;
	cin.ignore();
	list l1(cc, cn);



	while (true)
	{
		cout << "1: Enter Next  Product \n 2: Display \n 3: End the Program" << endl;
		cin >> choice;
		cin.ignore();
		if (1 == choice)
		{
			cout << " Add the product code (like :101)" << endl;
			cin >> cc;
			cin.ignore();
			cout << "Enter The product Name" << endl;
			cin >> cn;
			cin.ignore();

			if (l1.boolScearchFOUND(l1, cc))
			{
				l1.insertAtEnd(l1, cc, cn);
			}


		}



		if (2 == choice) {
			l1.display(l1);
		}


		if (3 == choice) {
			break;
		}

	}



	return 0;
}