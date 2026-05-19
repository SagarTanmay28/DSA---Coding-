#include<iostream>
#include<string>
using namespace std;
int main(){
    string s ="abcdef";
             //012345

    cout<<s.substr(4)<<endl;
    cout<<s.substr(2,4)<<endl; // very important -> idx , size
    cout<<s.substr(2,3)<<endl;
    cout<<s.substr(0,5)<<endl; //doubt {Explanation :: 0 is Starting Point and 5 is the Size }
    cout<<s.substr(0,6);       //doubt Cleared 

}