#include<iostream>
using namespace std;
int pow(int a , int b){
    if(a==0 && b==0){
        cout<<"Not Defined";
        return -100;
    }
    if(a==0) return 0;
    if(b==0) return 1;
    return a*pow(a,b-1);
    // Time Complexity = O(b);
    // Space Complexity = O(b); stack frames 

}

int main(){
    cout<<pow(2,10);
}