#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    int max = INT64_MIN;
    for(int i=0;i<5;i++){
        if(max<arr[i]) max = arr[i];
    }
    int smax = INT64_MIN;
    for(int i=0;i<5;i++){
        if(arr[i]!=max && smax<arr[i]) smax = arr[i];
    }

    cout<<max<<endl;
    cout<<smax;

}