#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m;
    cout<<"Enter no of Rows - ";
    cin>>m;
    int n;
    cout<<"Enter no of Columns - ";
    cin>>n;

    int arr[m][n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;      
        
    }
    cout<<endl;
   // transpose in same matrix 
   for(int i=0;i<m;i++){
    for(int j=i+1;j<n;j++){
        // swapping 
        int temp = arr[i][j];
        arr[i][j] = arr[j][i];
        arr[j][i] = temp;
    }
   }

   // print 
   for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
   }
}