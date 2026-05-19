#include<iostream>
using namespace std;
int ans(int& sum, int a, int b){
    if( a >= b) return sum;

    if(a % 2 != 0) sum += a;
    ans(sum,a+1,b);
}
int main(){
    int a = 2;
    int b = 11;
    int sum = 0;
    cout << ans(sum,a,b);
}