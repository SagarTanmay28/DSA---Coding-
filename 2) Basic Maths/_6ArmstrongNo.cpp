#include<iostream>
#include<algorithm>
using namespace std;
bool Armstrong(int N){
    int sum = 0;
    int N1 = N;
    while(N>0){
        int r = (N%10);
        sum += r*r*r;
        N /= 10;
    }
    return sum==N1;
}
int main(){
    int N = 153;
    cout << Armstrong(N);
}