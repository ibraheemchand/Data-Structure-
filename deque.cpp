#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Deque class using Doubly Linked List
class Deque {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Check if deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Get size
    int getSize() {
        return size;
    }

    // Insert at front
    void pushFront(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
        cout << val << " inserted at front\n";
    }

    // Insert at rear
    void pushRear(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
        cout << val << " inserted at rear\n";
    }

    // Delete from front
    void popFront() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from front.\n";
            return;
        }
        Node* temp = front;
        cout << temp->data << " deleted from front\n";
        
        if (front == rear) {
            // Only one element
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        size--;
    }

    // Delete from rear
    void popRear() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from rear.\n";
            return;
        }
        Node* temp = rear;
        cout << temp->data << " deleted from rear\n";
        
        if (front == rear) {
            // Only one element
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
        size--;
    }

    // Peek front
    int peekFront() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return -1;
        }
        return front->data;
    }

    // Peek rear
    int peekRear() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return -1;
        }
        return rear->data;
    }

    // Display deque from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }
        cout << "Deque (front -> rear): ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " <-> ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Destructor to free memory
    ~Deque() {
        while (!isEmpty()) {
            popFront();
        }
    }
};

// ---- MAIN ----
int main() {
    Deque dq;

    cout << "=== Deque using Linked List ===\n\n";

    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushRear(30);
    dq.pushFront(5);
    dq.pushFront(1);

    cout << "\n";
    dq.display();

    cout << "\nFront element: " << dq.peekFront() << "\n";
    cout << "Rear element:  " << dq.peekRear() << "\n";
    cout << "Size:          " << dq.getSize() << "\n";

    cout << "\n";
    dq.popFront();
    dq.popRear();

    cout << "\n";
    dq.display();

    cout << "\nFront element: " << dq.peekFront() << "\n";
    cout << "Rear element:  " << dq.peekRear() << "\n";
    cout << "Size:          " << dq.getSize() << "\n";

    return 0;
}