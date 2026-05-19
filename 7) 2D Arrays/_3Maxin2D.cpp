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

    int max = INT_FAST8_MIN;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]>max) max = matrix[i][j];
        }
    }
    cout<<max;


}
