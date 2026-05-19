#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter no of rows - ";
    cin>>m;

    int n;
    cout<<"Enter no of columns - ";
    cin>>n;

    int matrix[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
     cout<<endl;

     // Store the Transform :
     int t[n][m];
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            t[i][j] = matrix[j][i];
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
     }
}