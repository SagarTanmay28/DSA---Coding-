#include<iostream>
#include<queue>
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

// Construction 
Node* construct(int arr[],int n){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;

    while(q.size()>0 && j<n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i] != INT_MIN) l = new Node(arr[i]);
        else l = NULL;
        if(arr[j] != INT_MIN) r = new Node(arr[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i += 2;
        j += 2;
    }
    return root;
}

// Level Order using Queue;  1 2 3 4 5 6 7 
void levelOrderQueue(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size() > 0){
        Node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left != NULL) q.push(temp->left);  // left
        if(temp->right != NULL) q.push(temp->right);// right
    }
}


int main(){
    // Construct
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    // level Order Traversal
    levelOrderQueue(root);

    
}
