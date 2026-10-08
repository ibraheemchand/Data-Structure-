#include <iostream> 
using namespace std;

struct bestCount
{
    int FreqNum;
    int freqNumCount;
};


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


    bestCount FrequencyCheck(stack s1){
        node* temp = s1.head;
        int bestcount=0;
        
        int targetElement =0;
        int count = 0;
        bestCount b;
        while (!s1.isEmpty())
        {
            count=0;
          
            targetElement = s1.pop();
            temp = s1.head;
            while (temp!=nullptr)
            {
                if (targetElement == temp->data)
                {
                    count++;
                }
                
                
                temp = temp->nextPtr;
            }
            
            if (count> bestcount)
            {
                bestcount = count;
                b.FreqNum=targetElement;
                b.freqNumCount= count;
            }

            
            
            

            
        }
            return b;


    }

};



int main(){

   stack s1;
   s1.push(1);
   s1.push(2);
   s1.push(3);
   s1.push(4);
   s1.push(5);
   s1.push(4);
   s1.push(6);

   bestCount b1 =  s1.FrequencyCheck(s1);


    cout << "the most Frequent element is " << b1.FreqNum << " was found " << b1.freqNumCount << " times "<<endl;


    


    return 0;
}