#include<iostream>
using namespace std;
void printN1(int n){
    // base case
    if(n==0) return;
    cout<<n<<endl;
    return printN1(n-1);
}
int main(){
    printN1(6);
}