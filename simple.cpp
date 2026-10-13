#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *left;
    node *right;

    node(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class tree
{
    node *root;

public:

    tree()
    {
        root = NULL;
    }

    // INSERT
    // First LEFT, then RIGHT
    void insert(int val)
    {
        node *New = new node(val);

        if (root == NULL)
        {
            root = New;
            return;
        }

        node *current = root;

        while (true)
        {
            // First check LEFT
            if (current->left == NULL)
            {
                current->left = New;
                return;
            }

            // Then check RIGHT
            if (current->right == NULL)
            {
                current->right = New;
                return;
            }

            // Both are occupied
            current = current->left;
        }
    }

    // INORDER
    // Left -> Root -> Right
    void inorder(node *current)
    {
        if (current == NULL)
            return;

        inorder(current->left);

        cout << current->value << " ";

        inorder(current->right);
    }

    void inorder()
    {
        inorder(root);
    }

    // PREORDER
    // Root -> Left -> Right
    void preorder(node *current)
    {
        if (current == NULL)
            return;

        cout << current->value << " ";

        preorder(current->left);

        preorder(current->right);
    }

    void preorder()
    {
        preorder(root);
    }

    // POSTORDER
    // Left -> Right -> Root
    void postorder(node *current)
    {
        if (current == NULL)
            return;

        postorder(current->left);

        postorder(current->right);

        cout << current->value << " ";
    }

    void postorder()
    {
        postorder(root);
    }

    // FIND NODE
    node *find(node *current, int val)
    {
        if (current == NULL)
            return NULL;

        if (current->value == val)
            return current;

        node *temp = find(current->left, val);

        if (temp != NULL)
            return temp;

        return find(current->right, val);
    }

    // FIND DEEPEST NODE
    void deepest(node *current, node *&deep, node *&parent)
    {
        if (current == NULL)
            return;

        if (current->left != NULL)
        {
            deep = current->left;
            parent = current;
            deepest(current->left, deep, parent);
        }

        if (current->right != NULL)
        {
            deep = current->right;
            parent = current;
            deepest(current->right, deep, parent);
        }
    }

    // DELETE
    void Delete(int val)
    {
        if (root == NULL)
            return;

        node *current = find(root, val);

        if (current == NULL)
        {
            cout << "Value not found" << endl;
            return;
        }

        // If root is the only node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return;
        }

        node *deep = root;
        node *parent = NULL;

        deepest(root, deep, parent);

        // Copy deepest node value
        current->value = deep->value;

        // Remove deepest node
        if (parent->left == deep)
            parent->left = NULL;

        else
            parent->right = NULL;

        delete deep;
    }

    // DISPLAY NUMBER OF NODES
    void display()
    {
        int num = 0;

        count(root, num);

        cout << "Number of nodes: " << num << endl;
    }

    void count(node *current, int &num)
    {
        if (current == NULL)
            return;

        num++;

        count(current->left, num);
        count(current->right, num);
    }

    // DESTRUCTOR
    ~tree()
    {
        destroy(root);
    }

    void destroy(node *current)
    {
        if (current == NULL)
            return;

        destroy(current->left);
        destroy(current->right);

        delete current;
    }
};

int main()
{
    tree t;

    // INSERTION
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);

    cout << "Inorder:" << endl;
    t.inorder();

    cout << "\n\nPreorder:" << endl;
    t.preorder();

    cout << "\n\nPostorder:" << endl;
    t.postorder();

    cout << "\n\nNumber of nodes:" << endl;
    t.display();

    // DELETE
    cout << "\nDeleting 30..." << endl;
    t.Delete(30);

    cout << "\nInorder after deletion:" << endl;
    t.inorder();

    cout << "\n\nNumber of nodes after deletion:" << endl;
    t.display();

    return 0;
}