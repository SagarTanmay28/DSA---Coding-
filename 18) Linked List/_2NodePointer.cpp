#include<iostream>
using namespace std;
class Node{ // Linked List Node 
public: 
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    a->next = b;
    b->next = c;
    c->next = d;

    cout<< a->val <<endl;
    cout<< b->val <<endl;
    cout<< c->val <<endl;
    cout<< d->val <<endl;
    cout<<endl;

    // Easy traversal Using Pointers 
    Node* temp = a;
    while(temp != NULL){
        cout<< temp->val <<" ";
        temp = temp->next;
    }
    cout<<endl;

    // Benefit of Pointer
    cout<< (*a).val << " ";
    cout<< a->next->val << " ";
    cout<< a->next->next->val << " ";
    cout<< a->next->next->next->val << " "; 



}