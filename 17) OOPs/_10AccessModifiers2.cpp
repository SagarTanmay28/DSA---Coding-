#include<iostream>
using namespace std;
class Student{
public:
    int rno;
    string name;

    Student(int rno, string name, float marks){ // if we put constructor in private then error will come 
        this->rno = rno;
        this->name = name;
        this->marks = marks;
    }
    void display(){
        cout<<"Roll NO -> "<<rno<<endl;
        cout<<"Name -> "<<name<<endl;
        cout<<"Marks -> "<<marks<<endl;
    }
    int getMarks(){ // getter
        return marks;
    }
    int setMarks(int m){ // setter
        return m;
    }

private:
    float marks;
};
int main(){
    Student s1(78,"DHONI",95);// This will pass in above constructor and 
    // in above class we can access marks but we cant change,print,use
    s1.name = "RAINA";
    // s1.marks = 94; // Error 
    // cout<<s1.marks: // Error

    // What if we wanted to print marks ??  -> Make Display function in public:
    s1.display();

    cout<<endl;

    cout<<s1.getMarks()<<endl;
    cout<<s1.setMarks(98)<<endl;

    
}