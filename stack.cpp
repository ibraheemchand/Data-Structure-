#include <iostream> 
using namespace std;

class  node
{public:
int data ;
node* nextPtr;

public:
    node(int data){
    this->data = data;
    this->nextPtr = NULL;
    };
    node(int data, node* ptr){
    this->data = data;
    this->nextPtr = ptr;
    };
    ~node(){};
};


class stack
{
public:

node* head;

    stack(){
    this->head = NULL;
    };



    void push(int num){
        if (this->head == NULL)
        {
         node* n = new node(num); 
         this->head = n;  
        }
        if (this->head != NULL){
            node* n = new node(num , this->head);
            this->head = n;

        }
    }

    int pop(){
        node* temp = this->head;
        int popData=this->head->data;
        this->head= head->nextPtr;
        delete temp;
        return popData;
    }

    bool isEmpty(){
        if (this->head == NULL)
        {
            return true;
        }
        if (this->head != NULL)
        {
            return false;
        }
        
        
    }

    int topElement(){
        return (this->head->data);
    }

    ~stack(){
        node* temp = this->head;
        while (temp!= NULL)
        {
            node* t= temp;
            temp = temp->nextPtr;
            delete t;
        }
        
    };
};



int main(){

    stack s1;
    s1.push(5);
    cout << s1.topElement() << endl;
    s1.push(4);
    cout << s1.topElement() << endl;
    s1.push(3);
    cout << s1.topElement() << endl;
    s1.push(2);
    cout << s1.topElement() << endl;
    s1.push(1);
     cout << s1.topElement() << endl;

     cout <<endl ;
    s1.pop();
    cout << s1.topElement() << endl;
    s1.pop();
    cout << s1.topElement() << endl;
    s1.pop();
     cout << s1.topElement() << endl;


    


    return 0;
}