#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    
    // input 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // Output
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;


    // VIMP 

    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<size;
}