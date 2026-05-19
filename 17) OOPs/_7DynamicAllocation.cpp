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


int main(){
    Cricketer c1("MS Dhoni",11000,47.2);
    Cricketer* c2 = new Cricketer("Virat Kohli",25000,55.2);

    int* ptr = new int(326); // Memory Allocate in Runtime 
               // here it is stored in heap memory 
    cout<<*ptr<<endl<<endl;

    cout<<c1.name<<" "<<c1.runs<<endl;
    cout<<(*c2).name<<" "<<(*c2).runs<<endl;
    cout<<c2->name<<" "<<c2->runs<<endl;



    //  int* arr = new int[5]; // Dynamic Array 
    // arr[0] = 5; // No need of * here in array 
    // arr[3] = 4;
    // cout<<arr[0];



   
}