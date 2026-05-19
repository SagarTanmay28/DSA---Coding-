#include<iostream>
#include<vector>
using namespace std;
int main(){
   
    int n;
    cout<<"Enter No of Rows/Columns - ";
    cin>>n;

    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    
}