#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int toDecimal(string n){
    int size = n.size();
    int p2 = 1;
    int num = 0;
    for(int i=size-1;i>=0;i--){
        if(n[i]==1) num = num + p2;
        p2 = p2 * 2;
    }
    return num;
}

int main(){
    string n;
    cin >> n;
    cout << toDecimal(n);
}