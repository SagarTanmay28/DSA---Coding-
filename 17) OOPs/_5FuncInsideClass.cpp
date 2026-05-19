#include<iostream>
using namespace std;
class Cricketer{
public: 
    string name;
    int runs;

    Cricketer(string name, int runs){
        this->name = name;  
        this->runs = runs;
    }
    void print(int runs){
       // cout<<name<<" "<<runs<<endl; he ka use nahi kel ?
       // because in print function we can pass anything so if we pass int runs 
       // then runs will change but original runs are different one 
       cout<<this->name<<" "<<this->runs<<endl;
       cout<<runs<<endl;
       
    }
    int matches(){
        return runs/101;
    }
    
   
};

 

int main(){
    Cricketer c1("MS Dhoni",11000);
    Cricketer c2("Virat Kohli",25000);

    c1.print(5);
    c2.print(7);
    cout<<c1.matches()<<endl;
}