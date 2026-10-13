#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val)  {this->data; 
        this->next=nullptr;
    }
};


class Queue {
public:
    Node* front;
    Node* rear;

    Queue(){front = NULL;
    rear= NULL;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout <<"Queue is empty";
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return val;
    }

    int peek() {
        if (isEmpty()) {
           cout<< "Queue is empty";
        }
        return front->data;
    }

    void printQueue() {
        Node* temp = front;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


void sortQueue(Queue& q) {
    if (q.isEmpty()) return;

    Queue sortedQueue;
    while (!q.isEmpty()) {
        int minElement = q.dequeue();
        while (!q.isEmpty()) {
            int currentElement = q.peek();
            if (currentElement < minElement) {
                minElement = currentElement;
            }
            q.dequeue();
        }
        sortedQueue.enqueue(minElement);
    }

    
    while (!sortedQueue.isEmpty()) {
        q.enqueue(sortedQueue.dequeue());
    }
}

int main() {
    Queue q;
    int elements[] = {40, 10, 20, 30, 50};
    int n = sizeof(elements) / sizeof(elements[0]);

    
    for (int i = 0; i < n; i++) {
        q.enqueue(elements[i]);
    }

    std::cout << "Original Queue: ";
    q.printQueue();

    
    sortQueue(q);

    std::cout << "Sorted Queue: ";
    q.printQueue();

    return 0;
}
