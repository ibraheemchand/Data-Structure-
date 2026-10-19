#include <iostream>
using namespace std;




class node
{
public:
     int data;
     node* leftChild;
     node* rightChild;
    node(int val){
        this->data = val;
        this->leftChild= NULL;
        this->rightChild = NULL;
    };
    ~node(){};
};

void Inorder(node* root){

    if (root == NULL)
    {
       return ;
    }

    Inorder(root->leftChild);
    cout << root->data << "  ";
    Inorder(root->rightChild);
}



node* Insert(node* root , int val){
 if (root == NULL)
 {
   return new node(val);
 }

 else if (root->data < val)  //for greater values
 {
   root->rightChild =  Insert(root->rightChild , val);
 }
 else if (root->data > val)  //for smaller values
 {
    root->leftChild =  Insert(root->leftChild , val);
 }
  return root;
 
}

node* BuildBst( int arr[] , int arrSize){
    node* root = NULL; 
    for (int i = 0; i < arrSize; i++)
    {
      root = Insert(root , arr[i]);
    }
    return root ;

}


bool Scearch(node* root , int val){ //0(height)
 if (root == NULL)
 {
   return false;
 }

 else if (root->data == val)
 {
    return true;
 }
 

 else if (root->data < val)  //for greater values
 {
   Scearch(root->rightChild , val);
 }
 else if (root->data > val)  //for smaller values
 {
    Scearch(root->leftChild , val);
 }
 
 
}

int main(){
int arr[6]={3,2,1,5,6,4};

node* root = BuildBst(arr , 6);

cout << endl;

Inorder(root);

cout << endl;
cout << endl;
if (Scearch(root , 3))
{
   cout << "IS found" << endl;
}
else{
    cout << "NOt Found " << endl;
}

return 0;


}