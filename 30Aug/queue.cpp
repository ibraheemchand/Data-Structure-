#include <iostream>
using namespace std;

class node
{
  
public:
  int* n ;
  node(int x){
    n  = new  int;
    *n=x;
}
node(){
    n = NULL;
}

};

class queue
{

public:
node* front  ;
node* back ;

    queue(){
        front = back = NULL;
    }

    ~queue();

void push (int n){
   if (front == back && front!=NULL)
   {
    back = new node(n) ;

   }
   else if (front == back && front==NULL)
   {
    back = new node() ;
    *back = n;
    front = new node() ;
    *front = n;
    }
    else
    back = new node(n);
   
    
}

void pop (){
int *temp = new int ;
temp =  front->n;
front->n=(front->n)+1;
delete temp; 


}

int Front (){
 return *(front->n);
}

bool isEmpty(node x){
    if (x.n == NULL)
    {
        return 1;
    }
    
    return 0;
}
};




int main(){

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    int count = 0; 
    for (int i = 0; i < 3; i++)
    {
        cout << q.Front();
        count ++;
    }
        cout << count ;

 for (int i = 0; i < 3; i++)
    {
         q.pop();
        
    }


    return 0 ;
}