#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



    
int main(){
    // Q. Array is of n+1 integers and contains n integers 
    // from 1 to n 
    int n;
    cout<<"Enter no of integers - ";
    cin>>n;

    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    // Best Approach by using Maths ::

    
    int sum1 = 0;
    for(int i=0;i<n;i++){
        sum1 += nums[i];
    }
    int sum2 = (n-1)*(n-1+1)/2;
    cout<< sum1-sum2;

}

    
    
