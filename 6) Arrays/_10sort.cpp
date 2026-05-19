#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[] = {26,2,16,16,5,5,26,2,5,20,20,5,2,20,2,2,20,2,16,20,16,17,16,2,16,20,26,16};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(begin(arr),end(arr));
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        // 2 2 2 2 2 2 2 5 5 5 5 16 16 16 16 16 16 16 17 20 20 20 20 20 20 26 26 26 
        // count = 6 
        // v[] = {7,4,7,1,6,3}
        // v[] = {1,3,4,6,7,7}
    }
    }