#include <iostream>
using namespace std;

class DynamicArry
{
public:




    int* data;      
    int size;       
    int capacity;


    DynamicArry(int capac){
        if (capac > 0)
        this->capacity = capac;
        else
        this->capacity = 1;
        data= new int[capacity];
        size = 0;
    }
     DynamicArry(DynamicArry& other) {
        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~DynamicArry(){   
        delete[] data;
    }

     void resize() {
        
       int newCapacity;

        if (capacity == 0)
        newCapacity = 1;


        else
        newCapacity = capacity * 2;


        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    int search(int value)  {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) 
            {
                return i;
            }
        }
        return -1;
    }



    void insert(int value) {
        if (size == capacity) {
            resize(); 
        }
        data[size] = value;
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false; 
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        return true;
    }
     void display(){
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "] \n size of array = " << size << "\n And the capacity = " << capacity <<  endl;
    }
};

int main(){
    
    DynamicArry arr(3);

    arr.insert(91);
    arr.insert(92);
    arr.insert(93);
    arr.insert(94);
    arr.insert(95);

    arr.display();


    cout << "Searching for 95: index = " << arr.search(95) << endl;
    cout << "Searching for 99: index = " << arr.search(99) << endl;


    cout << "Removing element at 3rd index (94) " << endl;
    bool ok = arr.remove(3);
    if (ok)
    {
        cout << "SuccessFully Removed ! " << endl;
    }
     arr.display();


    cout << "Performing copy using copy constructor" << endl;
    DynamicArry copyArr(arr);
    copyArr.insert(100);
    cout << "Original array : ";
    arr.display();
    cout << "Copied array :     ";
    copyArr.display();
}