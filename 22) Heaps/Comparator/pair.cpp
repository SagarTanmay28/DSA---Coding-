#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
    if(p1.first == p2.first){
        if(p1.second > p2.second) return true;
        return false;
    }
    if(p1.first > p2.first) return true;
    return false;
}
int main(){
    vector<pair<int,int>> v = {{2,3},{2,4},{3,1}};
    sort(v.begin(),v.end(),cmp);

    for(auto &p : v) cout << p.first << " " << p.second << "::";
}