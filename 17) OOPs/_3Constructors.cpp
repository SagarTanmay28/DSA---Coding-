#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Student{ // Student is a new data type 
public:
    string name;
    int rno;
    float gpa;

    Student(){ // Default Constructor   //  Student s2;
      
    }
    Student(int r){  // Parameterised Constructor //  Student s4;
        rno = r;
    }

    // ye 2 parameter ka bhi constructor bana sakte hai yaha but niche bhi 2 hi attribute hone chaiye s1 ke aage 
    Student(string s, int r){ // Parameterised Constructor  // Student s3;
       name = s;
       rno = r;
    }

    Student(string s, int r, float g){ // Parameterised Constructor  // Student s1;
       name = s;
       rno = r;
       gpa = g; 
    }

    Student(float g, int r,string s){ // Parameterised Constructor  // Student s5;
       name = s;
       rno = r;
       gpa = g; 
    }
    
   

};

void print(Student c){
     cout<<c.name<<" "<<c.rno<<" "<<c.gpa<<" "<<endl;
}
int main(){
    Student s1("MS Dhoni",95,8.4); // yaat ji order aahe tich order vari constructor madhe asli pahije 
    print(s1);
    

    Student s2;
    s2.name = "Virat Kohli";
    s2.rno = 18;
    s2.gpa = 8.6;

    Student s3("Rohit Sharma",45);

    Student s4(8); 

    Student s5(8.6,15,"Sachin");

    Student s6 = s1; // Deep Copy; 
    s6.name = "Sunil";
    
    Student s7(s1); // Copy Constructor - Deep Copy;
    s7.name = "Raina";  
   

    // NOTE**:: 1) s1 sathi constructor banvlo aani khali s2 madhe error ala WHY?
            //  2) apan samja constructor nahi banvla tar aadhich default constructor asto to disat nahi 
            //  3) but aapan s1 sathi constructor banavtoy tar s2 sathi aaplyala default constructor banvaylach pahije 

    // NOTE :: Without Default Constructor 
    // we can write 
    // Student s1("MS Dhoni",95,8.4);
    // s1.gpa = 8.2;
}