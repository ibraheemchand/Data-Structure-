#include <iostream>
#include <string>
using namespace std;

class node {
public:
    char data;
    node* nextPtr;

    node(char data) {
        this->data = data;
        this->nextPtr = NULL;
    }

    node(char data, node* ptr) {
        this->data = data;
        this->nextPtr = ptr;
    }

    ~node() {}
};

class stack {
public:
    node* head;

    stack() {
        this->head = NULL;
    }

    void push(char num) {
        if (this->head == NULL) {
            this->head = new node(num);
        } else {
            node* n = new node(num, this->head);
            this->head = n;
        }
    }

    char pop() {
        if (this->head == NULL) {
            return '\0'; // Assuming an invalid state
        }
        char popData = this->head->data;
        node* temp = this->head;
        this->head = this->head->nextPtr;
        delete temp;
        return popData;
    }

    bool isEmpty() {
        return this->head == NULL;
    }

    char topElement() {
        if (this->head == NULL) {
            return '\0'; 
        }
        return this->head->data;
    }

    ~stack() {
        node* temp = this->head;
        while (temp != NULL) {
            node* t = temp;
            temp = temp->nextPtr;
            delete t;
        }
    }
};

bool isValidDelimiters(string& s) {
    stack s1;
    bool isValid = true;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            s1.push(s[i]);
        } 
        else if (s[i] == '}' || s[i] == ')' || s[i] == ']') 
        {
            if (s1.isEmpty()) {
                isValid = false;
                break;
            }
            char top = s1.topElement();
            if ((s[i] == '}' && top != '{') || (s[i] == ')' && top != '(') || (s[i] == ']' && top != '['))
            {
                isValid = false;
                break;
            }
            s1.pop();
        }
    }

    if (isValid && !s1.isEmpty())
    {
       return true;
    }
    
    else{
        return false;
    }
}

int main() {
    string s = "{[(2 + 3])}";
    if (isValidDelimiters(s)) {


        cout << "This is Valid Delimiters" << endl;
    } 
    
    else {
        cout << "This is not Valid Delimiters" << endl;
    }
    return 0;
}