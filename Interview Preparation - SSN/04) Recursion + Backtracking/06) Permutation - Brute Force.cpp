// String
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void permutation(string ans, string original){
    if(original.size() == 0){
        cout << ans << endl;
        return;
    }

    for(int i=0;i<original.size();i++){
        char ch = original[i];
        string left = original.substr(0,i);
        string right = original.substr(i+1);
        permutation(ans+ch,left+right);
    }
}

int main(){
    string s = "abc";
    permutation("",s);
}

// Array 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> add(vector<int> nums, int idx){
    vector<int> ans;
    // 1 2 3 4 5
    // 0 1 2 3 4
    for(int i=0;i<idx;i++) ans.push_back(nums[i]);
    for(int i=idx+1;i<nums.size();i++) ans.push_back(nums[i]);

    return ans;
}
void permutation(vector<int> ans, vector<int> nums){
    if(nums.size() == 0){
        for(int i=0;i<ans.size();i++){
            cout << ans[i];
        }
        cout << endl;
        return;
    }

    for(int i=0;i<nums.size();i++){
        int x = nums[i];
        vector<int> newAns = ans;
        newAns.push_back(x);
        permutation(newAns,add(nums,i));
    }
}

int main(){
    vector<int> nums = {1,2,3};
    vector<int> v;
    permutation(v,nums);
}
