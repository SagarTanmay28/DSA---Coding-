#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string toBinary(int n){
    string res ="";
    while(n>0){
        if(n%2==1) res += "1";
        else res += "0";
        n /= 2;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    int n;
    cin >> n;
    cout << toBinary(n);
}