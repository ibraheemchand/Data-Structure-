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

    // INSERT NODE
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
            if (val < current->value)
            {
                if (current->left == NULL)
                {
                    current->left = New;
                    return;
                }

                current = current->left;
            }
            else
            {
                if (current->right == NULL)
                {
                    current->right = New;
                    return;
                }

                current = current->right;
            }
        }
    }

    // INORDER
    // Left -> Root -> Right
    void inorder(node *current)
    {
        if (current == NULL)
            return;

        inorder(current->left);

        cout << current->value << endl;

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

        cout << current->value << endl;

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

        cout << current->value << endl;
    }

    void postorder()
    {
        postorder(root);
    }

    // FIND SMALLEST NODE
    node *findMin(node *current)
    {
        while (current->left != NULL)
        {
            current = current->left;
        }

        return current;
    }

    // DELETE NODE
    node *Delete(node *current, int val)
    {
        if (current == NULL)
            return NULL;

        if (val < current->value)
        {
            current->left = Delete(current->left, val);
        }
        else if (val > current->value)
        {
            current->right = Delete(current->right, val);
        }
        else
        {
            // CASE 1: No child
            if (current->left == NULL && current->right == NULL)
            {
                delete current;
                return NULL;
            }

            // CASE 2: Only right child
            if (current->left == NULL)
            {
                node *temp = current->right;

                delete current;

                return temp;
            }

            // CASE 3: Only left child
            if (current->right == NULL)
            {
                node *temp = current->left;

                delete current;

                return temp;
            }

            // CASE 4: Two children
            node *temp = findMin(current->right);

            current->value = temp->value;

            current->right = Delete(current->right, temp->value);
        }

        return current;
    }

    void Delete(int val)
    {
        root = Delete(root, val);
    }

    // DESTRUCTOR
    ~tree()
    {
        DeleteAll(root);
    }

    void DeleteAll(node *current)
    {
        if (current == NULL)
            return;

        DeleteAll(current->left);
        DeleteAll(current->right);

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

    cout << "\nPreorder:" << endl;
    t.preorder();

    cout << "\nPostorder:" << endl;
    t.postorder();

    // DELETION
    t.Delete(30);

    cout << "\nAfter deleting 30:" << endl;

    cout << "Inorder:" << endl;
    t.inorder();

    return 0;
}