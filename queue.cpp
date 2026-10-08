#include <iostream>
using namespace std;

class queue
{
public:
int size =6;
int arr[6];
int front ;
int rear ;
int count;
    queue(){
        front = rear = -1;    //initailixing front 
    };

    ~queue();
    

    void Enqueue(int n){
        if (isfull())
        {
            cout << "Queue Full" << endl;
        }
        else{
            rear = (rear+1)%size;
            arr[rear]=n;
            count++;
        }
        
    }

    int Dequeue(){
     
    }

    bool isEmpty(){

    }

    bool isfull(){

    }

};



int main(){

    return 0;
}