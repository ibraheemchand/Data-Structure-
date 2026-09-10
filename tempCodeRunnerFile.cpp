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


    void ValDel(int value){
        node* tempp = this->head;
		bool Loop = true;
        node* prev = this->head;
		while (tempp != NULL)
		{

			if (tempp == this->head && tempp->data ==value ) //delete 1st node
			{
				this->head = tempp->nextPtr;
				delete tempp;
				tempp = this->head;
				continue;
			}
			

			if(tempp->data == value){
                prev->nextPtr = tempp->nextPtr;
                delete tempp;
				tempp = prev->nextPtr;
				continue;

            }


			if (tempp->nextPtr == NULL) {

				cout << endl;

				break;
			}

			prev = tempp;
			tempp = tempp->nextPtr;
            
			
		}
    }







};

int main() {
	list l(1);
	l.insertAtEnd(2);
	l.insertAtEnd(3);
	l.insertAtEnd(2);
	l.insertAtEnd(1);

	l.display();


	l.ValDel(3);
	l.display();

	
	return 0;
}