#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> v;
    //INPUT
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    
    for( int i=0,j=v.size()-1; i<=j; i++,j--){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    } 

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }  
}