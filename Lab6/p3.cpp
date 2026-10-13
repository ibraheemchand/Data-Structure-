#include <iostream>
using namespace std;
class node
{
public:
int data;
node* nextptr;

    node(int n){
        this->nextptr = NULL;
        this->data = n;
    };
    node(){
        this->nextptr = NULL;
    };
    ~node();
};


class Queue
{
public:
    node* front;
    node* back;
    

    Queue(){
       front= NULL;
        back = NULL;
    };
    void Enqueue(int n){
        if (front == NULL && back == NULL)
        {
            node* nn = new node(n); 
            front = back = nn;
        }
        else{
            node* nn = new node(n);
            nn->nextptr = front;
            front = nn;

        }

        
    }
    int dequeue(){
        node* temp= front;
        int nnn= front->data;
        if (front != back)
        {
            front = front->nextptr;
            delete temp;
        }
        
        else if  (front == back ){
            delete temp;
            front = NULL;
            back = NULL;

        }
        
       

        return nnn;
    }

    bool isEmpty(){
        if(front==NULL){
            return false;
        }
        else{
            return true;
        }
    }

    void Sort(Queue q1){
        Queue q2 = q1;
    }
    
    ~Queue();
};




int main(){

    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);

    

}
