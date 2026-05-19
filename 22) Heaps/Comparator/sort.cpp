#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    if(a > b) return true;
    return false;
}
int main(){
    vector<int> v = {5,3,4,1,2};
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<v.size();i++) cout << v[i] << " ";
}