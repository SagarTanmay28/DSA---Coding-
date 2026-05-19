#include<iostream>
#include<vector>
using namespace std;

void change(vector<int> a){
     a[0] = 100;
     for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }    // jar he cout khali ast vari nast tar samech vector print hotay 100 yet nahi 
    // because vectors are pass by value 
    cout<<endl;
}
int main(){
    vector<int> v;
    v.push_back(9);
    v.push_back(10);
    v.push_back(6);
    v.push_back(1);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    change(v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
     

}