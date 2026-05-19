#include<iostream>
using namespace std;
int pow(int x,int n){
    if(x==0 && n==0) return -100;
    if(n==0) return 1;
    if(n==1) return x;
    
    int ans = pow(x,n/2);
    if(n%2==0) return ans*ans;
    else return ans*ans*x;
}
int main(){
    cout<<pow(2,10);
}