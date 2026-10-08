#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear, capacity, count;

public:
    // Constructor
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear  = -1;
        count = 0;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }

    // Enqueue: O(1)
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;  // wrap around
        arr[rear] = x;
        count++;
    }

    // Dequeue: O(1)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity; // wrap around
        count--;
        return val;
    }

    // Peek front: O(1)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Peek rear: O(1)
    int peekRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == capacity; }
    int size()     { return count; }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();             // Queue: 10 20 30 40

    cout << "Dequeue: " << q.dequeue() << endl;  // 10
    cout << "Dequeue: " << q.dequeue() << endl;  // 20

    q.enqueue(50);
    q.enqueue(60);           // reuses freed space ✅
    q.display();             // Queue: 30 40 50 60

    cout << "Front: "  << q.peek()     << endl;  // 30
    cout << "Rear: "   << q.peekRear() << endl;  // 60
    cout << "Size: "   << q.size()     << endl;  // 4
    cout << "Full?: "  << q.isFull()   << endl;  // 0
    cout << "Empty?: " << q.isEmpty()  << endl;  // 0

    return 0;
}