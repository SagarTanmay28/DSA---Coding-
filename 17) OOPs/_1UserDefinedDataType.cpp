#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Student{ // Student is a new data type 
public:
    string name;
    int rno;
    float gpa;
};
class Car{ // Car is a New Data Type 
public:
    string name;
    int price;
    int seats;
    string type;
};
void print(Car c){
     cout<<c.name<<" "<<c.price<<" "<<c.seats<<" "<<c.type<<endl;
}
int main(){
    Student s1;
    s1.name = "MS Dhoni";
    s1.rno = 95; // input pan gheu shakto -> cin>>s1.rno;
    s1.gpa = 8.4;

    Student s2;
    s2.name = "Virat Kohli";
    s2.rno = 18;
    s2.gpa = 8.6;
    
    // Lenghty Method to Print 
    cout<<s1.name<<" "<<s1.gpa<<" "<<s1.rno<<endl;
    cout<<s2.name<<" "<<s2.gpa<<" "<<s2.rno<<endl;

    Car c1;
    c1.name = "Honda City";
    c1.price = 1500000;
    c1.seats = 5;
    c1.type = "Sedan";

    Car c2;
    c2.name = "Maruti Swift";
    c2.price = 700000;
    c2.seats = 5;
    c2.type = "Hatchback";

    Car c3;
    c3.name = "Toyota Fortuner";
    c3.price = 3600000;
    c3.seats = 8;
    c3.type = "SUV";
    
    // Efficient Method to Print 
    print(c1);
    print(c2);
    print(c3);


}
    //Pascal case is a programming naming convention that capitalizes the first letter of each word in a variable name
    // Given a sentence having lowercase characters, the task is to convert it to Camel Case. In Camel Case, words are joined without spaces, the first word keeps its original case, and each subsequent word starts with an uppercase letter.

    // Examples: 

    // Input: “i got intern at geeksforgeeks”
    // Output: “iGotInternAtGeeksforgeeks”


    // Input: “here comes the garden”
    // Output: “hereComesTheGarden”


