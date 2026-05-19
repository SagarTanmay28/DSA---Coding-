
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> diffArray(int n, vector<vector<int>> &queries){
    // Difference Array
    vector<int> ans(n);
    for(auto &e : queries){
        int l = e[0];
        int r = e[1];
        int x = e[2];
        ans[l] += x;
        if(r+1 < n) ans[r+1] -= x;  
    }
    // Prefix Sum 
    for(int i=1;i<n;i++) ans[i] += ans[i-1];
    return ans;

}
int main(){
    int n = 5;
    vector<vector<int>> queries = { {1,3,2},{2,4,3},{0,2,-2}};
    vector<int> result = diffArray(n, queries);
    
    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}