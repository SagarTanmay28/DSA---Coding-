#include<iostream>
using namespace std;
void print(){
    cout<<"MSDHONI";
}
int sum(int a, int b){
    return a+b;
}
int main(){
    // Void 
    print();
    // Int
    int s = sum(2,7);
    cout<<endl<<s;
}