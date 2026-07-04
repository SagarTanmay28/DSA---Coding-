You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

 

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.


class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int x, int y) {
        int p_x = find(x);
        int p_y = find(y);
        
        if(p_x != p_y) {
            if(rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
            } else if(rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
            } else {
                parent[p_x] = p_y;
                rank[p_y]++;
            }
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        
        for(int i = 0; i<26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(string &s : equations) {
            if(s[1] == '=')
                Union(s[0]-'a', s[3]-'a');
        }
        
        for(string &s : equations) {
            if(s[1] == '!') {
                if(find(s[0]-'a') == find(s[3]-'a'))
                    return false;
            }
        }
        
        return true;
        
    }
};
