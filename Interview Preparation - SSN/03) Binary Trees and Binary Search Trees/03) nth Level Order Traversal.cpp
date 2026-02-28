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
// Level
int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}

// nth Level Order Traversal
void nthLevel(Node* root, int curr, int level){
    if(root == NULL) return;
    if(curr == level){
        cout << root->val << " ";
        return;
    }
    nthLevel(root->left,curr+1,level); // left
    nthLevel(root->right,curr+1,level); // right 
    // ** left right -> 1 2 3 4 5 6 7
    // ** right left -> 1 3 2 7 6 5 4
}

// Level Order
void levelOrder(Node* root){
    int n = levels(root);
    for(int i=1;i<=n;i++){
        nthLevel(root,1,i);   
    }
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

    levelOrder(a);
}
