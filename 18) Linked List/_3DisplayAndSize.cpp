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

void display(Node* head){ // with temp   T.C = O(n) & S.C = O(1);
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<< " ";
        temp = temp->next;
    }
}

void display2(Node* head){ // without temp  T.C = O(n) & S.C = O(1);
    while(head != NULL){
        cout<< head->val << " ";
        head = head->next;
    }
}

void display3(Node* head){ // using recursion   T.C = O(n) & S.C = O(n);
    if(head==NULL) return; // base case 
    cout<< head->val << " "; // kaam
    display3(head->next); // call
}

void display4(Node* head){ // Reverse using recursion   T.C = O(n) & S.C = O(n);
    if(head==NULL) return; // base case
    display4(head->next); // call 
    cout<< head->val << " "; // kaam 
}

int size(Node* head){ // to find size
    Node* temp = head;
    int n = 0;
    while(temp != NULL){
        n++;
        temp = temp->next;
       
    }
    return n;
}

void insertAtEnd(Node* head, int val){
    Node* t = new Node(val);
    while(head->next != NULL) head = head->next;
    head->next = t;
}
 
int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    a->next = b;
    b->next = c;
    c->next = d;

    display(a); // with temp 
    cout<<endl;
    cout<<size(a)<<endl;

    display2(a); // witout temp
    cout<<endl;
    
    display3(a); //  using recursion 
    cout<<endl; 

    display4(a); // Reverse using recursion 
    cout<<endl;  

    insertAtEnd(a,80);  // you dont have access of tail here 
    display(a);
}