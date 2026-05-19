#include<iostream>
#include<string>
#include<vector>
using namespace std;

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

void change1(Car c){ // Pass by Value 
    c.name = "Audi A8";
}
void change2(Car& c){ // Pass by Reference 
    c.name = "Audi A8";
}
int main(){
   
    Car c1;
    c1.name = "Honda City";
    c1.price = 1500000;
    c1.seats = 5;
    c1.type = "Sedan";

    print(c1);
    change1(c1);
    print(c1);

    cout<<endl;

    print(c1);
    change2(c1);
    print(c1);
   
}