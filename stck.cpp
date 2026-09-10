#include <iostream>
using namespace std;

class stack
{
int top;
int* arr;

public:
    stack(int num){
        arr = new int[num];           //array based implementation
        this->top = -1;

    };

    void push(int num){
        this->top++;
       arr[top]=num;
    }

   void pop(){
        if ( this->top >= 0 )
        {
            int xxx = arr[ this->top];
             this->top--;
        }
    

    }

    bool Top(int& t){
        if (t=arr[ this->top])
        {
           return true;
        }
        else false;
        
    }

    void MakeNull(){
        this->top = -1;
    }

    bool isEmpty(){
        if ( this->top==-1)
        {
            return true;
        }
        else return false;
        
    }
  
    ~stack(){
        delete[] arr;
    };





};




int main(){

    int numm=0;
    stack s1(5);
    bool th;
    s1.push(5);


    
    th = s1.Top(numm);
    cout << "Top element " << numm << endl;

    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);

    th= s1.Top(numm);
    cout << "Top element " << numm << endl;

    s1.pop();
    s1.pop();
    s1.pop();


    th = s1.Top(numm);
    cout << "Top element " << numm << endl;


   

    return 0 ;
}