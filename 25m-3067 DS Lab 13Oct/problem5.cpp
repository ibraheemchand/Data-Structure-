#include <iostream>
using namespace std;

class node {
public:
    char data;
    node* leftChild;
    node* rightChild;
    node(char c)  {
        this->data = c;
        leftChild = rightChild = NULL;
    }
    ~node() {}
};

class tree {
public:
    node* root;

    tree()  {
        root = NULL;
    }

    bool treeIsEmpty() {
        return (root == NULL);
    }

    void insertIntree(char c) {
        if (root == NULL) {
            root = new node(c);
        } else {
            insertIntreeHelper(root, c);
        }
    }

    void insertIntreeHelper(node* r, char c) {
        if (r->data < c) {
            if (r->rightChild == NULL) {
                r->rightChild = new node(c);
            } else {
                insertIntreeHelper(r->rightChild, c);
            }
        } else {
            if (r->leftChild == NULL) {
                r->leftChild = new node(c);
            } else {
                insertIntreeHelper(r->leftChild, c);
            }
        }
    }

    void rangeSearch(char low, char high) {
        node* searchRange = root;
        char found = -1;
        while (searchRange != NULL) {
            if (searchRange->data >= low && searchRange->data <= high) {
                cout << searchRange->data << " ";
                found = 1;
            }
            if (searchRange->data < low) {
                searchRange = searchRange->rightChild;
            } else if (searchRange->data > high) {
                searchRange = searchRange->leftChild;
            } else {
                return;
            }
        }
        if (found == 0) {
            cout << "No products in the range [" << low << ", " << high << "]" << endl;
        }
    }

    bool treeIsEmpty() {
        return root == NULL;
    }

    int NodeCounter(node* r) {
        if (root == NULL) {
            return 0;
        }
        return 1 + NodeCounter(r->leftChild) + NodeCounter(r->rightChild);
    }

    int noofLeaf(node* r) {
        if (root == NULL) {
            return 0;
        }
        if (r->leftChild == NULL && r->rightChild == NULL) {
            return 1;
        }
        return noofLeaf(r->leftChild) + noofLeaf(r->rightChild);
    }

    void PreOrder(node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << " ";
        PreOrder(root->leftChild);
        PreOrder(root->rightChild);
    }

    void PostOrder(node* root) {
        if (root == NULL) {
            return;
        }
        PostOrder(root->leftChild);
        PostOrder(root->rightChild);
        cout << root->data << " ";
    }

    void Inorder(node* root) {
        if (root == NULL) {
            return;
        }
        Inorder(root->leftChild);
        cout << root->data << " ";
        Inorder(root->rightChild);
    }

    node* del(node* root) {
        if (root == NULL) {
            return NULL;
        }
        node* remp = root;
        root = del(root->leftChild);
        root = del(root->rightChild);
        delete remp;
        return root;
    }

    ~tree() {
        del(root);
    }
};

int main() {
    tree t;
    t.insertIntree('a');
    t.insertIntree('b');
    t.insertIntree('c');
    t.insertIntree('d');
    t.insertIntree('e');

    cout << "PreOrder traversal of the tree: ";
    t.PreOrder(t.root);
    cout << endl;

    cout << "PostOrder traversal of the tree: ";
    t.PostOrder(t.root);
    cout << endl;

    cout << "Inorder traversal of the tree: ";
    t.Inorder(t.root);
    cout << endl;

    cout << "Is tree Empty? " << t.treeIsEmpty() << endl;

    char low = 'a', high = 'e';
    cout << "Range of prices: " << low << " to " << high << endl;
    t.rangeSearch(low, high);

    cout << "Number of Nodes in the tree: " << t.NodeCounter(t.root) << endl;
    cout << "Number of Leaf Nodes in the tree: " << t.noofLeaf(t.root) << endl;

    return 0;
}