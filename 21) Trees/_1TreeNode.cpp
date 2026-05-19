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

void displayTree(Node* root){
    if(root == NULL) return;
    cout << root->val << " ";
    displayTree(root->left);
    displayTree(root->right);
}

int sum(Node* root){
    if(root == NULL) return 0;
    return root->val + sum(root->left) + sum(root->right); 
}

int size(Node* root){
    if(root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}

int maxi(Node* root){
    if(root == NULL) return INT_MIN;
    int LMax = maxi(root->left);
    int RMax = maxi(root->right);
    return max(root->val,max(LMax,RMax));
}

int mini(Node* root){
    if(root == NULL) return INT_MAX;
    int LMin = mini(root->left);
    int RMin = mini(root->right);
    return min(root->val,min(LMin,RMin));
}

int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left),levels(root->right));
}

int height(Node* root){
    if(root == NULL) return 0;
   int levels =  1 + max(height(root->left),height(root->right));
   return levels - 1;
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

    // Display 
    displayTree(a); // here " a " is the root Node
    cout << endl;
    cout << sum(a)<<endl;
    cout << size(a)<<endl;
    cout << maxi(a)<<endl;
    cout << mini(a)<<endl;
    cout << levels(a)<<endl;
    //cout << height(a)<<endl;

}