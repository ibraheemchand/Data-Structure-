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






	/*bool isPalandrome(list l) {
		node* temp = l.head;
		bool Loop = true;
		int count = 0;
		int mid;
		while (temp != NULL || Loop)
		{

			count++;
			if (temp->nextPtr == NULL) {


				Loop = false;
				mid = count / 2;


			}

			else {
				temp = temp->nextPtr;
			}


		}

		temp = l.head;
		node* head2 = NULL;
		for (int i = 0; i < mid; i++)
		{
			if (i== mid-1)
			{
				head2 = temp->nextPtr;
			}
			if (i == mid - 2)
			{
				temp->nextPtr= NULL;
			}

			temp = temp->nextPtr;
		}


		node* prev = NULL;
		node* curr = head2;
		node* next = NULL;

		while (true) {
			next = curr->nextPtr;
			curr->nextPtr = prev;



			if ()
			{

			}
		}


	}*/



	bool isPalandromeCheck() {
		node* temp = this->head;
		
		int count = 0;
		bool pal=true;

		while (temp != NULL )
		{

			count++;
			temp = temp->nextPtr;
			


		}



		int* arr = new int[count];
			temp = this->head;



		for (int i = 0; i < count; i++)
		{
			arr[i] = temp->data;
			temp = temp->nextPtr;
		}



		int nn = count - 1;
		for (int i = 0; i < nn; i++, nn--)
		{
			if (arr[i] != arr[nn]) {
				pal = false;
				break;
			}
			
			
		}
		
		return pal;
	}

};

int main() {
	list l(1);
	l.insertAtEnd(2);
	l.insertAtEnd(3);
	l.insertAtEnd(2);
	l.insertAtEnd(1);

	l.display();



	list l2(1);
	l2.insertAtEnd(2);
	l2.insertAtEnd(3);
	l2.insertAtEnd(4);
	l2.insertAtEnd(5);
	l2.display();


	bool check = l.isPalandromeCheck();

	if (check) {
		cout << "This is Not a palandrome " << endl;
	}
	else {
		cout << "This is a palandrome " << endl;
	}

	check = l2.isPalandromeCheck();
	if (check) {
		cout << "This is Not a palandrome " << endl;
	}
	else {
		cout << "This is a palandrome " << endl;
	}
	
	return 0;
}