                 1
              2     3
            4   5  6  7

Preorder  -> 1 2 4 5 3 6 7
Inorder   -> 4 2 5 1 6 3 7
Postorder -> 4 5 2 6 7 3 1




#include<iostream>
#include<climits>
using namespace std;
class Node{
public: 
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
// PRE ORDER 
void preorder(Node* root){
    if(root == NULL) return; // base case 
    cout << root->val << " "; // kaam 
    preorder(root->left); // call 1
    preorder(root->right); // call 2
}

// IN ORDER 
void inorder(Node* root){
    if(root == NULL) return; // base case 
    inorder(root->left); // call 1
    cout << root->val << " "; // kaam 
    inorder(root->right); // call 2
}

// POST ORDER
void postorder(Node* root){
    if(root == NULL) return; // base case 
    postorder(root->left); // call 1
    postorder(root->right); // call 2
    cout << root->val << " "; // kaam 
}


int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    preorder(a);
    cout << endl;
    inorder(a);
    cout << endl;
    postorder(a);
    cout << endl;
}
