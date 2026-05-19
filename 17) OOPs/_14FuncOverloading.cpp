// Polymorphism 

#include<iostream>
using namespace std;
class Loading{
public:
   
    void sum(string a, string b){
        cout<<a+b<<endl;
    }
    void sum(int a, int b){
        cout<<a+b<<endl;
    }
    void sum(int a, int b, int c){
        cout<<a+b+c<<endl;
    }
    int sum(int a, int b, int c, int d){
        cout<<a+b+c+d<<endl;
    }
    // int sum(int a, int b){ Error karan 2 parameter same zale 
    // return type different/same asle tari chalel 
    //     cout<<a+b<<endl;
    // }
};