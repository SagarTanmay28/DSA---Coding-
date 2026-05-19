#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void combinations(vector<int>& candidates, vector<int> v, vector<vector<int>>& ans, int target, int idx){
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(target < 0) return;

    for(int i=idx;i<candidates.size();i++){
        // Skip duplicates at the same recursive level
        if(i > idx && candidates[i] == candidates[i - 1]) continue;

        if(v.size() == 0 || v[v.size()-1] != candidates[i] ) v.push_back(candidates[i]);
        combinations(candidates,v,ans,target - candidates[i],i+1); // to avoid reuse 
        v.pop_back();
    }
}
int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    sort(candidates.begin(),candidates.end());
    int target = 8;
    vector<vector<int>> ans;
    vector<int> v;
    combinations(candidates,v,ans,target,0);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++) cout << ans[i][j]<< "";
        cout << endl;
    }
}