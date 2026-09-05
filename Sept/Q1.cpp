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





};

int main() {
	int cc;
	string cn = "";
	int choice = 0;



	cout << " Add the Course code (like :2001)" << endl;
	cin >> cc;
	cin.ignore();
	cout << "Enter The course Name" << endl;
	cin >> cn;
	cin.ignore();
	list l1(cc, cn);



	while (true)
	{
		cout << "Enter where you wana insert \n 1:Front \n 2:Back \n 3: Scearch \n 4:Display \n 5: End the program  " << endl;
		cin >> choice;
		cin.ignore();
		if (1 == choice)
		{
			cout << " Add the Course code (like :2001)" << endl;
			cin >> cc;
			cin.ignore();
			cout << "Enter The course Name" << endl;
			cin >> cn;
			cin.ignore();


			l1.insertAtBegining(cc, cn);
		}

		if (2 == choice)
		{
			cout << " Add the Course code (like :2001)" << endl;
			cin >> cc;
			cin.ignore();
			cout << "Enter The course Name" << endl;
			cin >> cn;
			cin.ignore();


			l1.insertAtEnd(l1, cc, cn);
		}

		if (3 == choice) {
			int cc;
			cout << "Enter the course code you wanna scearch " << endl;
			cin >> cc;
			l1.scearch(l1, cc);
		}


		if (4 == choice) {
			l1.display(l1);
		}


		if (5 == choice) {
			break;
		}

	}


	return 0;
}