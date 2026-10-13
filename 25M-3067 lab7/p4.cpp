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


    node* PreOrder(node* root){
        if (root == NULL)
        {
            return NULL;
        }
        
        cout << root->data << " ";
        PreOrder(root->leftChild); // left child
        PreOrder(root->RightChild); // right child
    }
    node* PostOrder(node* root){
        if (root == NULL)
        {
            return NULL;
        }
        
        
        PostOrder(root->leftChild); // left child
        PostOrder(root->RightChild); // right child
        cout << root->data << " ";
    }
    node* Inorder(node* root){
        if (root == NULL)
        {
            return NULL;
        }
        
        
        Inorder(root->leftChild); // left child
        cout << root->data << " ";
        Inorder(root->RightChild); // right child
        
    }

int main(){
vector<int> preOrder = {60, 55 ,45 ,-1,-1 ,57 ,-1 ,59,-1,-1 ,100 ,67,-1,-1 ,107 ,101 , -1 ,-1 ,-1};
tree t;
t.root = BuildTree(preOrder);

cout << "Pre order "<<PreOrder(t.root);
cout << endl;
cout << " InOrder "<<Inorder(t.root);
cout << endl;
cout << " Postorder "<<PostOrder(t.root);
cout << endl;

}