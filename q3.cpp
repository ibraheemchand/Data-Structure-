#include <iostream>
#include <stack>
using namespace std;

class node {
public:
    int data;
    node* nextPtr;

public:
    node(int data) {
        this->data = data;
        this->nextPtr = nullptr;
    }
    node(int data, node* ptr) {
        this->data = data;
        this->nextPtr = ptr;
    }
    ~node() {
    }
};


class stack {
public:
    node* head;

    stack() {
        this->head = nullptr;
    }

    void push(int num) {
        node* new_node = new node(num);
        new_node->nextPtr = head;
        this->head = new_node;
    }

    int pop() {
        if (this->head == nullptr) {
            cout << "Stack is empty." << endl;
            return -1; // Indicate stack is empty
        }
        int popData = this->head->data;
        node* temp = this->head;
        this->head = this->head->nextPtr;
        delete temp;
        return popData;
    }

    bool isEmpty() {
        return (this->head == nullptr);
    }

    int topElement() {
        return (this->head->data);
    }

    ~stack() {
        node* temp = this->head;
        while (temp != nullptr) {
            node* t = temp;
            temp = temp->nextPtr;
            delete t;
        }
    }
};

int main() {
    stack source;
    stack auxillary;
    stack destination;

    // Initial configuration
    for (int i = 5; i >= 1; --i) {
        source.push(i);
    }

    cout << "Initial configuration:" << endl;
    cout << "Source: ";
    while (!source.isEmpty()) {
        cout << source.topElement() << " ";
        source.pop();
    }
    cout << endl;
    cout << "Auxiliary: " << endl;
    cout << "Destination: " << endl;

    // Function to print the current state of stacks
    void printStacks(stack source, stack auxillary, stack destination) {
        cout << "Source: ";
        while (!source.isEmpty()) {
            cout << source.topElement() << " ";
            source.pop();
        }
        cout << endl;
        cout << "Auxiliary: ";
        while (!auxillary.isEmpty()) {
            cout << auxillary.topElement() << " ";
            auxillary.pop();
        }
        cout << endl;
        cout << "Destination: ";
        while (!destination.isEmpty()) {
            cout << destination.topElement() << " ";
            destination.pop();
        }
        cout << endl;
        cout << endl;
    }

    // Recursive function to solve Tower of Hanoi
    void solveTowerOfHanoi(int n, stack source, stack auxillary, stack destination) {
        if (n == 1) {
            destination.push(source.pop());
            cout << "Move disk 1 from Source to Destination" << endl;
            printStacks(source, auxillary, destination);
        } else {
            solveTowerOfHanoi(n-1, source, destination, auxillary);
            destination.push(source.pop());
            cout << "Move disk " << n << " from Source to Destination" << endl;
            printStacks(source, auxillary, destination);
            solveTowerOfHanoi(n-1, auxillary, source, destination);
        }
    }

    // Solve Tower of Hanoi
    solveTowerOfHanoi(5, source, auxillary, destination);

    return 0;
}
