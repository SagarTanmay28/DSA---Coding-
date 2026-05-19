#include<iostream>
using namespace std;
// private -> We cant print , We cant use , We cant change 
// for Security reasons we use private like unique one that is permanent (Aadhar Card); 

// We do not want the user to change a particular class member but 
// we want that user to print it -> for this we will use Getter

class Student{
public:
    int rno;
    string name;
// private:    // aani khali s1.marks la error yeil karan s1.marks is in private but all above is in public  
    float marks;

    void display(){
        cout<<name<<" "<<marks<<" "<<rno<<endl;
    }
};

int main(){
    Student s1;
    s1.rno = 78;
    s1.name = "MS Dhoni";
    s1.marks = 96;
    s1.display();
}