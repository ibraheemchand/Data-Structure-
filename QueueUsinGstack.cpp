#include <iostream> 
using namespace std;

class  node{
    public:
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
        else if (this->head != NULL){
            node* n = new node(num , this->head);
            this->head = n;

        }
    }

    int pop(){
        if (!isEmpty())
        {
           node* temp = this->head;
            int popData=this->head->data;
            this->head= head->nextPtr;
         delete temp;
            return popData;
        }
        
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
       if (this->head == NULL)
       {
         return -1;
       }
       
        return (this->head->data);
    }

    int Quee(stack& s1){
        stack s2;
        while (!s1.isEmpty())
        {
           s2.push(s1.topElement());
           s1.pop();
        }
        int x = s2.topElement();
        s2.pop();

        while (!s2.isEmpty())
        {
            s1.push(s2.topElement());
            s2.pop();
        }
        
        return x;
        
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
 s1.push(1);   
 s1.push(2);   
 s1.push(3);   
 s1.push(4);   
 s1.push(5);   

 while (!s1.isEmpty())
 {
    cout << s1.Quee(s1) ;
    cout << " ";
 }
 
 

    return 0;
}