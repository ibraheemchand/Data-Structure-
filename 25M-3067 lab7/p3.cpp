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

node* root = BuildTree(preOrder);

PrintTree(root);

}