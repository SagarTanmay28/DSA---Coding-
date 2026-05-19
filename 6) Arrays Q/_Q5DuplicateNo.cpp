#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    // Q. Array is of n+1 integers and contains n integers 
    // from 1 to n 
    int n;
    cout<<"Enter No of Elements - ";
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

    // Duplicate 

    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        if(v[nums[i]] == 0) v[nums[i]]=1;
        else {
            cout<<nums[i];
            break;
        }

        
    }
}