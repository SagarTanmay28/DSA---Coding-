#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector< vector<int> > pascal(int rowIndex){
    int m = rowIndex;
     vector< vector<int> > v;
    for(int i=0;i<m;i++){
        vector<int> a(i+1);
        v.push_back(a);
    
    // v[0], v[1], v[2] 
    //  1     2     3    
    for(int j=0;j<=i;j++){
        if(i==j || j==0 ) v[i][j] = 1;
        else v[i][j] = v[i-1][j] + v[i-1][j-1];  
    }

    }

    return v;

    

}
int main(){

    vector< vector<int> > v = pascal(5);

    for(int j=0;j<v.size();j++){
        cout<<v[4][j]<<" ";
    }

    

   
}