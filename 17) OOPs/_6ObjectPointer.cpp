// a->b means (*a).b 
#include<iostream>
using namespace std;
class Cricketer{
public: 
    string name;
    int runs;
    float avg;

    Cricketer(string name, int runs, float avg){
        this->name = name;  
        this->runs = runs;
        this->avg = avg;
    }  
   
};

void change(Cricketer* c){
    (*c).avg = 88.2; //instead of writing this write c1->avg 
}

 

int main(){
    Cricketer c1("MS Dhoni",11000,47.2);
    Cricketer c2("Virat Kohli",25000,55.2);

    Cricketer* p1 = &c1;
    cout<<(*p1).runs<<endl; // c1.runs
    cout<<c1.avg<<endl;
    (*p1).avg = 77.5; // c1.avg = 77.5
    cout<<c1.avg<<endl;

    cout<<endl;
    
    // Instead of (*p1).avg use p1->avg
    Cricketer* p2 = &c2;
    cout<<p2->runs<<endl; // c1.runs
    cout<<c2.avg<<endl;
    p2->avg = 77.5; // c1.avg = 77.5
    cout<<c2.avg<<endl;

    cout<<endl;


    // Pointer Uses 
    cout<<c2.avg<<endl;
    change(&c2);
    cout<<c2.avg<<endl;

   
}