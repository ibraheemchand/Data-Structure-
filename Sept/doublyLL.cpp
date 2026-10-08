#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to prevent memory leaks
    ~DoublyLinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    // 1. Insertion at the beginning (Head)
    void insertFront(T val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // 2. Insertion at the end (Tail)
    void insertBack(T val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // 3. Remove from front (Head)
    bool removeFront() {
        if (head == nullptr) return false;

        Node* temp = head;
        if (head == tail) { // Only one element
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        return true;
    }

    // 4. Remove from end (Tail)
    bool removeBack() {
        if (tail == nullptr) return false;

        Node* temp = tail;
        if (head == tail) { // Only one element
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        return true;
    }

    // 5. Remove first occurrence of a specific value
    bool removeValue(T val) {
        Node* curr = head;

        // Search for the node with the value
        while (curr != nullptr && curr->data != val) {
            curr = curr->next;
        }

        if (curr == nullptr) return false; // Value not found

        if (curr == head) {
            return removeFront();
        }
        if (curr == tail) {
            return removeBack();
        }

        // Unlink middle node
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        return true;
    }

    // Display list forward
    void display() const {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " <-> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList<int> dll;

    // Insertion examples
    dll.insertBack(10);
    dll.insertBack(20);
    dll.insertFront(5);
    dll.insertBack(30);
    std::cout << "Initial list: ";
    dll.display(); // Output: 5 <-> 10 <-> 20 <-> 30 <-> NULL

    // Removal examples
    dll.removeFront();
    std::cout << "After removing front: ";
    dll.display(); // Output: 10 <-> 20 <-> 30 <-> NULL

    dll.removeValue(20);
    std::cout << "After removing 20: ";
    dll.display(); // Output: 10 <-> 30 <-> NULL

    dll.removeBack();
    std::cout << "After removing back: ";
    dll.display(); // Output: 10 <-> NULL

    return 0;
}