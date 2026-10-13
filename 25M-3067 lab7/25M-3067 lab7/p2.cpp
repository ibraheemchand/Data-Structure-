#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
 int data;
 node* leftChild;
 node* RightChild;
    node(int data){
        this->data = data;
        this->leftChild = NULL;
        this->RightChild = NULL;
    };
    ~node();
};

class tree
{
public:
 node* root ;


    tree(){

    };
    ~tree();

    void insertRight(node* n , int data ){
        n->leftChild = NULL;
        n->RightChild = new node(data);
    }
    void insertLeft(node* n ,int data){
        n->RightChild = NULL;
        n->leftChild = new node(data);
    }
   
};
    int index = -1;
 node* BuildTree(vector<int> preOrder){
    index++;
    if (preOrder[index]==-1)
    {
     return NULL;
    }
     node* root = new node(preOrder[index]);
     root->leftChild=BuildTree(preOrder);
     root->RightChild=BuildTree(preOrder);

     return root;

    }


    node* PrintTree(node* root){
        if (root == NULL)
        {
            return NULL;
        }
        
        cout << root->data << " ";
        PrintTree(root->leftChild); // left child
        PrintTree(root->RightChild); // right child
    }

int main(){
vector<int> preOrder = {60, 55 ,45 ,-1,-1 ,57 ,-1 ,-1 ,100 ,67,-1,-1 ,107 ,-1 , -1};
tree t;
t.root = BuildTree(preOrder);

PrintTree(t.root);

t.insertLeft(t.root->RightChild->RightChild, 101);
t.insertRight(t.root->leftChild->RightChild, 59);
PrintTree(t.root);

return 0;
}