#include<iostream>
#include<vector>
using namespace std;

int sqrt(int x){
    int lo = 1;
    int hi = x;
    int ans;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int m = mid;
        if(m*m <= x){
            ans = m;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return ans;
}

int main(){
   int x;
   cin>>x;
   cout<<sqrt(x);
}
    