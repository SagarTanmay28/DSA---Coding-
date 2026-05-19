#include<iostream>
using namespace std;
class Cricketer{
public: 
    string name;
    int runs;

    Cricketer(string name, int runs){
        this->name = name;   // (this) is for same variable name 
        this->runs = runs;
    }
    //  Cricketer(string name, int runs){
    //     name = name;            // Garbage value yetay asa lihil ki 
    //     runs = runs;
    //  }
   
};

 void print(Cricketer c){
        cout<<c.name<<" "<<c.runs<<endl;
    }

int main(){
    Cricketer c1("MS Dhoni",11000);
    Cricketer c2("Virat Kohli",25000);

    print(c1);
    print(c2);
}