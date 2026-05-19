#include<iostream>
using namespace std;
class Node{ // DLL Node
public:
      int val;
      Node* next;
      Node* prev; // extra for DLL
      Node(int val){
          this->val = val;
          this->next = NULL;
          this->prev = NULL; // extra for DLL
      }
};


class DLL{  // User Defined Data Structure 
public: 
    Node* head;
    Node* tail;
    int size;
    DLL(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtTail(int val){
        Node* temp = new Node(val);
        if(size==0) head = tail = temp; // Case - 1 
        else{
            tail->next = temp;
            temp->prev = tail; // extra 
            tail = temp;
        }
        size++;
    }

     void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size==0) head = tail = temp; // Case - 1 
        else{
           temp->next = head;
           head->prev = temp; // extra
           head = temp;
        }
        size++;
    }

    void insertAtIdx(int idx, int val){
      if(idx<0 || idx>size) cout<<"Invalid Index"<<endl;
      else if(idx==0) insertAtHead(val);
      else if(idx==size) insertAtTail(val);
      else{
        Node* t = new Node(val);
        Node* temp = head;
        for(int i=1;i<=idx-1;i++){
            temp = temp->next;
        }
        t->next = temp->next;   // IMP 
        temp->next = t;         // IMP
        t->prev = temp;         // VIMP
        t->next->prev = t;      // VIMP
        size++;
      }

    }

    int getAtIdx(int idx){
        if(idx<0 || idx>=size){
            cout<< "Invalid Index";
            return -1;
        }
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else{
            Node* temp = head;
            for(int i=1;i<=idx;i++){
                temp = temp->next;
            }
            return temp->val;
        }
    }

    void deleteAtHead(){
        if(size==0){
            cout<<"List is Empty";
        }
        head = head->next;
        size--;
    }

    void deleteAtTail(){
        if(size==0){
            cout<<" list is Empty";
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
    }

    void deleteAtidx(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid Index";
            return;
        }
        else if(idx==0) return deleteAtHead();
        else if(idx==size-1) return deleteAtTail();
        else{
            Node* temp = head;
            for(int i=1;i<=idx-1;i++){
                temp = temp->next;
            }
            temp->next = temp->next->next; // IMP 
            size--;
        }
    }

    void display(){ // Node* head paranthesis madhe takat nahiyet karan tyach access aahe madhe aslyamule
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};


int main(){
    DLL list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.display();
    list.insertAtTail(40);
    list.display();
    list.insertAtHead(50);
    list.display();
    list.insertAtIdx(2,60);
    list.display();
    
}