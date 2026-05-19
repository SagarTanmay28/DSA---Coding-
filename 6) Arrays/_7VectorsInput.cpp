#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    // size is not mentioned so we cant use v.size() here
    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    for(int i=0;i<5;i++){
        cout<<v[i]<<" "<<endl;
    }

    vector<int> v1(5);
    for(int i=0;i<5;i++){
        cout<<v1[i]<<" ";
    }
}