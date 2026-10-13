#include <iostream>
using namespace std;
int l;
class node
{
public:
    int data;
    node* leftChild ;
    node* rightChild;
    node(char c){
        this->data = c;
        leftChild = rightChild = NULL;
    };
    ~node(){

    };
};

class tree
{public:
    node* root ;


    tree(){
        this->root = NULL;
    }

    bool treeIsEmpty(){
        if (root == NULL)
        {
           return true;
        }
        else{
            return false;
        }
        
    }

    void insertIntree(char c){
        if (root == NULL)
        {
            node* n = new node(c);
            n->leftChild=NULL;
            n->rightChild = NULL;

        }

        else{
            node* temp = root;
            while (true)
            {
                
                 if (temp->data < c  && temp->rightChild ==NULL)
                {
                    node* n = new node(c);
                    temp->rightChild= n;
                    break;

                }
                 else if(temp->data < c  && temp->rightChild !=NULL){             //right child
                    temp  =temp->rightChild;

                }
                

                else if (temp->data > c && temp->leftChild == NULL )
                {
                    node* n = new node(c);
                    temp->leftChild = n;
                    break;
                }
                else if (temp->data > c && temp->leftChild != NULL )        //left child
                {
                    temp = temp->leftChild;
                }
                
                
            }
            
        }


        
    }




     node* noOFnodes(node* r, int &a){
        if (root == NULL)
        {
            return NULL;
        }
        
        a++;
        noOFnodes(r->leftChild , a); // left child
        noOFnodes(r->rightChild , a); // right child
    }


    int NodeCounter(node* r){
        int a =  0;
        node* x = noOFnodes(r, a);
        return a;
    }

     node* Leafs(node* r, int &a){      //leafNOdes- counter 
        if (root == NULL)
        {
            return NULL;
        }
        
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            a++;
        }
        
        Leafs(r->leftChild , a); // left child
        Leafs(r->rightChild , a); // right child
    }


    int noofLeaf(node* r){
        int a =  0;
       node* x = Leafs(r, a);
        return a;
    }

     node* srch(node* root, bool &isFound , int n){
        if (root == NULL)
        {
            return NULL;
        }
        
        if (root->data == n)
        {
            isFound = true;
        }
        
        srch(root->leftChild ,isFound , n); // left child
        srch(root->rightChild , isFound , n); // right child
    }

    bool IsFoundinTree(char c){
        bool isF = false;
        int cc = int(c);
        node* x = srch(this->root , isF ,cc );
        return isF;

    }

    node* PreOrder(node* root){
        if (root == NULL)
        {
            return NULL;
        }
        
        cout << root->data << " ";
        PreOrder(root->leftChild); // left child
        PreOrder(root->rightChild); // right child
    }
    node* PostOrder(node* root){
        if (root == NULL)
        {
            return NULL;
        }
        
        
        PostOrder(root->leftChild); // left child
        PostOrder(root->rightChild); // right child
        cout << root->data << " ";
    }
    node* Inorder(node* root){
        if (root == NULL)
        {
            return NULL;
        }
        
        
        Inorder(root->leftChild); // left child
        cout << root->data << " ";
        Inorder(root->rightChild); // right child
        
    }

        node* del(node* root){
        if (root == NULL)
        {
            return NULL;
        }
        
        
        del(root->leftChild); // left child
        del(root->rightChild); // right child

        node* remp = root;
        delete remp;
    }; 
    node* mirror(node* root){
        if(root->leftChild == NULL && root->rightChild ==NULL ){
            return NULL;
        }
        mirror(root->leftChild);
        mirror(root->rightChild);

        swap(root->leftChild, root->rightChild);
    }
    ~tree(){
        node* root = del(root);
    }

    
};


int main(){
tree t;
t.insertIntree('f');
t.insertIntree('d');
t.insertIntree('p');
node* x = t.PreOrder(t.root);
node* x = t.PostOrder(t.root);
node* x = t.Inorder(t.root);

cout <<"is tree Empty " << t.treeIsEmpty() << endl;

if (t.IsFoundinTree('d'))
{
   cout << "Is Found in tree " << endl;
}
else{
    cout << "Is not Found in tree " << endl;
}

cout<< "The no of leaf Nodes "<<t.noofLeaf(t.root);
cout<< "The no of Nodes "<<t.NodeCounter(t.root);


t.Inorder(t.root);

t.mirror(t.root);
t.Inorder(t.root);
    return 0;
}