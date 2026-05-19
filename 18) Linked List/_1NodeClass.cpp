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
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);

    // forming ll;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    
    cout<<(*(a.next)).val<<endl; // b's Value 
    cout<<(a.next)->val<<endl; // b's Value  // (a.next)->val = b.val
    cout<<(b.next)->val<<endl; // c's value 
    cout<<(c.next)->val<<endl; // d's value

    cout<<((a.next)->next)->val<<endl; // c's value
    cout<<(*((*((*(a.next)).next)).next)).val<<endl; // 40
    cout<<(((a.next)->next)->next)->val<<endl<<endl; // 40

    // For printing all values
    Node temp = a;
    while(1){
        cout<<temp.val<<" ";
        if(temp.next==NULL) break;
        temp = *(temp.next);
    }
}