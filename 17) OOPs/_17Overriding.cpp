#include<iostream>
#include<vector>
using namespace std;
class Scooty{ // Parent Class 
public: 
   int topSpeed;
   float mileage;


 virtual void sound(){ // without virtual Output -> Vroom Vroom  with virtual Output -> Dhroom Dhroom 
    cout<< "Vroom Vroom"<<endl;
   }

private:
   int bootSpace;

};
class Bike : public Scooty{ // Child Class/Derived Class  
public:
   int gears;

   void sound(){
    cout<< "Dhroom Dhroom"<<endl;
   }
};

int main(){
    Scooty* s = new Scooty(); // Object Pointer
    Bike* b = new Bike(); // Object Pointer

    Scooty* k = new Bike(); // Object Pointer
    
    s->sound();
    b->sound();
    k->sound();

    vector<Scooty*> v;
}