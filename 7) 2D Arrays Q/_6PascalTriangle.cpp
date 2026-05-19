#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int numRows;
    cout<<"numRows - ";
    cin>>numRows;

    vector< vector<int> > v;
    for(int i=0;i<numRows;i++){
        vector<int>a(i+1);
        v.push_back(a);

        for(int j=0;j<=i;j++){
            if(i==j || j==0) v[i][j] = 1;
            else v[i][j] = v[i-1][j] + v[i-1][j-1];
        }
    }

    for(int i=0;i<numRows;i++){
        for(int j=0;j<=i;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}