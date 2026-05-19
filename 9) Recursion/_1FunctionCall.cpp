#include<iostream>
using namespace std;
void greet(){
    cout<<"Good Morning"<<endl;
    cout<<"How are you"<<endl;
}
int product(int a,int b){
    return a*b;
}

int main(){
    int a = 6;
    int b = 8;
    cout<<a<<" "<<b<<endl;
    cout<<product(a,b);
    
}