#include<iostream>
using namespace std;
int main(){

    int m;
    cout<<"Enter no of rows - ";
    cin>>m;

    int n;
    cout<<"Enter no of columns - ";
    cin>>n;

    int matrix1[m][n];
    int matrix2[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix1[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix2[i][j];
        }
       
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
     

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          matrix1[i][j] = matrix1[i][j] + matrix2[i][j]; 
          cout<<matrix1[i][j]<<" ";
            
        }
        cout<<endl;

    }



}