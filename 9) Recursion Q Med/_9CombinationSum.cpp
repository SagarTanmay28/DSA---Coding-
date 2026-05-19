#include<iostream>
#include<vector>
using namespace std;

void combinations(vector<int>& candidates, vector<int> v, vector<vector<int>>& ans, int target, int idx){
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(target < 0) return;

    for(int i=idx;i<candidates.size();i++){
        v.push_back(candidates[i]);
        combinations(candidates,v,ans,target - candidates[i],i);
        v.pop_back();
    }
}
int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans;
    vector<int> v;
    combinations(candidates,v,ans,target,0);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++) cout << ans[i][j];
        cout << endl;
    }
}