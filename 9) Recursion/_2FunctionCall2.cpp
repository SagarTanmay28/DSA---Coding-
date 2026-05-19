#include<iostream>
using namespace std;
// void sun(){
//     cout<<"Hello"<<endl;
//     sun();
// } Its Infinite Loop 
void gun(){
    cout<<"Hello Mummy"<<endl;
    return;
}
void fun(){
    cout<<"Hello Papa"<<endl;
    gun();
    return;
}

int main(){
    fun();
   
}