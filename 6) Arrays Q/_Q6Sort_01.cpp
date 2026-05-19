#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sort(vector<int> &v){
    int n = v.size();
    int noz = 0;
    int noo = 0;
    for(int i=0;i<n;i++){
        if(v[i]==0) noz++;
        else noo++;
    }
    for(int i=0;i<n;i++){
        if(i<noz) v[i]=0;
        else v[i]=1;
    }
   
}
int main(){
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);


    sort(v);
    int n = v.size();
    for(int i=0;i<n;i++){
        cout<<v[i];
    }
     
}