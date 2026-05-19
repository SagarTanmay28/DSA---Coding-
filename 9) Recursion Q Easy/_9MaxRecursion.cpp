#include<iostream>
#include<algorithm>
using namespace std;
int maxInArray(int arr[],int n, int idx){
    if(idx==n) return INT_FAST8_MIN;
    return max(arr[idx],maxInArray(arr,n,idx+1));
}
int main(){
    int arr[] = {2,3,5,7,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxInArray(arr,n,0);
}