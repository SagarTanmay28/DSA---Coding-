#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){ // in place of i<=n-1 we write sqrt
        if(n%i==0) return false;
    }
    return true;

}
int main(){
    int n;
    cin>>n;
    cout<<isPrime(n);
}