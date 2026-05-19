#include<iostream>
using namespace std;

int power(int a,int b){
    if(a==0) return 0;
    int p = 1;
    for(int i=1;i<=b;i++){
        p *= a;
    }
    return p;
    // Time Complexity = O(b);
    // Space Complexity = O(1); 
    // Actually iterative is better than recursion in this 
}
int main(){
    cout<<power(3,4);
}