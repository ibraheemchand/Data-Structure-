#include <iostream>
using namespace std;

class node
{
public:

    int data;
    node* nextPtr;
    node(int n){
        this->data = n;
        this->nextPtr=NULL;
    };
    ~node(){

    };
};

class linkedList
{

public:
node* head;
int count ;

    linkedList(){
       this->count = 0;
       this->head= NULL;
    }

    
    linkedList(int nn){
        node* n = new node(nn);
        this->head = n;                 // insert 1st node
        count = 1;

    };

    bool isEmpty(){
        if (this->head)
        {                           // check this list is this empty
            return true;
        }
        else return false;
        
    }

    void insertAtEnd(int nn){
        if (this->head != NULL)
        {
            node* temp = this->head;
        while (temp->nextPtr != NULL)
        {
            temp= temp->nextPtr;
        }

        node* n = new node(nn);
        temp->nextPtr = n;
        this->count ++;
        }

        else{
            this->head = new node(nn);
            count++;
        }
        
    }

    void insertAtBegining(int nn){
        if (this->head != NULL)
        {
         node* n = new node(nn);
        n->nextPtr = this->head;
        this->head= n;
        this->count ++;        }

        else{
            this->head=new node(nn);  
            count++;
        }
        

    }

    void deleteInLinkedList(){
        node* temp = this->head;
        this->head=temp->nextPtr;
        delete temp;
        this->count--;
    }

    bool scearch(int tar){
        node* temp = this->head;
        while (temp != NULL)
        {   if (temp->data == tar)
        {
            return true;
        }
        

            temp = temp->nextPtr;
        }

        return false;
        
    }
    void print(){
        node* temp = this->head;
        while (temp != NULL)
        {   
        
            cout << temp->data << "  ";
            temp = temp->nextPtr;
        }

       
        
    }

    void reverse(){
       node* pre =NULL;
       node* curr = this->head;
        node* next = this->head;

        while (next != NULL)
        {
            next=curr->nextPtr;
            curr->nextPtr= pre;
            pre = curr;
            curr = next;
        }
        this->head = pre;
        
    }
    ~linkedList(){
        node* temp = this->head;
        while (temp)
        {
            temp = this->head;
            head = temp->nextPtr;
            delete temp;
   
        }
        
    };
};




int main(){

    linkedList l;
    l.insertAtBegining(3);
    l.insertAtBegining(2);
    l.insertAtBegining(1);
    l.insertAtEnd(4);
    l.insertAtEnd(5);

    l.reverse();
    l.print();
    cout <<endl;
    cout << "list Having " << l.count << " elements ";

    
  
    return 0;
}