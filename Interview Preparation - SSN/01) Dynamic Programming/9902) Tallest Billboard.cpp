You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.

 

Example 1:

Input: rods = [1,2,3,6]
Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.
Example 2:

Input: rods = [1,2,3,4,5,6]
Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
Example 3:

Input: rods = [1,2]
Output: 0
Explanation: The billboard cannot be supported, so we return 0.

//Approach-1 : Recurison - TLE
class Solution {
public:
    int n; 
    
    int solve(vector<int>& rods, int i, int s1, int s2) {

        if (i == n) {
            if (s1 == s2)
                return s1;

            return 0;
        }

        
        int ans = 0;

        int nothing  = solve(rods, i + 1 , s1 , s2);
        int in_rod_1 = solve(rods, i + 1 , s1 + rods[i], s2);
        int in_rod_2 = solve(rods, i + 1 , s1 , s2 + rods[i]);

        return max({nothing, in_rod_1, in_rod_2});
    }
    
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();

        return solve(rods, 0, 0, 0);
    }
};


 

//Approach-2 (We can't take t[21][5001][5001] because it will casue Memory Limit Exceed
//Instead of storing s1 and s2, we can store (s1-s2) i.e. diff
//i.e. t[n+1][max diff we can get]
/*
  To avoid negative diff, we will use same trick like we did in Leetcode-1027. Longest Arithmetic Subsequence (Adding an offset)
*/
class Solution {
public:
    int n; 
    int t[21][10003];
    int solve(vector<int>& rods, int i, int diff) {

        if (i == n) {
            if (diff == 0)
                return 0;

            return INT_MIN;
        }
        
        if( t[i][diff+5000] != -1)
            return  t[i][diff+5000];
        
        int ans = 0;

        int nothing     = solve(rods, i + 1 , diff);
        int in_rod_1    = rods[i] + solve(rods, i + 1 , diff + rods[i]);
        int not_in_rod1 = rods[i] + solve(rods, i + 1 , diff - rods[i]);

        return t[i][diff+5000] = max({nothing, in_rod_1, not_in_rod1});
    }
    
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        
        memset(t, -1, sizeof(t));
        
        return solve(rods, 0, 0)/2;
    }
};
