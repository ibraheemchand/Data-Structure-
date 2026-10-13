#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <cctype>
using namespace std;
class Node {
public:
    char data;
    Node *next;

    Node(char data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    void push(char data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    char peek() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return head->data;
    }

    void pop() {
        if (!isEmpty()) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    char top() {
        return head->data;
    }
};

char precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return !std::isspace(c) && (c == '+' || c == '-' || c == '*' || c == '/');
}

std::string infixToPrefix(std::string infix) {
    std::stack<char> s;
    LinkedList linkedList;
    std::string prefix;

    for (int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];

        if (std::isspace(c)) continue;

        if (isOperator(c)) {
            linkedList.push(c);
        } else {
            std::string operand(1, c);
            while (!linkedList.isEmpty() && isOperator(linkedList.peek())) {
                operand += linkedList.peek();
                linkedList.pop();
            }
            s.push(operand + ' ');
        }
    }

    while (!linkedList.isEmpty()) {
        s.push(linkedList.peek());
        linkedList.pop();
    }

    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    return prefix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(std::cin, infix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix <<endl;

    return 0;
}