#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Prefix Sum
    for(int i=1;i<n;i++){
        arr[i] += arr[i-1];
    }
    // Print 
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}