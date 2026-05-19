#include<iostream>
#include<vector>
using namespace std;

 int transpose( int arr ,int m, int n){
    int arr[m][n];
      for(int i=0;i<m;i++){
        for(int j=i+1;j<n;j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
            return arr[i][j];
          
        }
        
      }

}
int main(){
    int m;
    cout<<"Enter No of Rows - ";
    cin>>m;
    int n;
    cout<<"Enter No of Columns - ";
    cin>>n;

    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    transpose(arr[m][n],m,n);
}