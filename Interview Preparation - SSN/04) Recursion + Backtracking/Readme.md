
# 🔥 The Backtracking Mastery

A complete, pattern-wise collection of **37 Backtracking / DFS problems** (LeetCode + GfG), organized by the underlying technique so you can spot the pattern instantly in interviews.

Each problem below includes:
- 📝 **Description** — what the problem asks
- 📥 **Input** / 📤 **Output** — a worked example
- 💻 **Code (C++)** — exact code from the original solution file

---

## 📚 Table of Contents

1. [Subsets Pattern](#1-subsets-pattern)
2. [Combinations Pattern](#2-combinations-pattern)
3. [Permutations Pattern](#3-permutations-pattern)
4. [String Partitioning Pattern](#4-string-partitioning-pattern)
5. [Grid / Matrix DFS Pattern](#5-grid--matrix-dfs-pattern)
6. [Constraint Satisfaction Pattern (N-Queens style)](#6-constraint-satisfaction-pattern-n-queens-style)
7. [Partition / Equal Distribution Pattern](#7-partition--equal-distribution-pattern)
8. [String / Sequence Generation Pattern](#8-string--sequence-generation-pattern)
9. [Expression & Number Construction Pattern](#9-expression--number-construction-pattern)
10. [Subsequence Selection Pattern](#10-subsequence-selection-pattern)
11. [Permutation Optimization Pattern](#11-permutation-optimization-pattern)
12. [Advanced / Hybrid Backtracking](#12-advanced--hybrid-backtracking)

---

## 🧠 The "Khandani" Backtracking Template

Almost every solution here follows the same skeleton:

```cpp
void solve(/* state */) {
    if (/* base case reached */) {
        // record the answer
        return;
    }

    for (/* each choice */) {
        // DO   -> make the choice
        solve(/* new state */);
        // UNDO -> revert the choice (backtrack)
    }
}
```

---

## 1. Subsets Pattern

> **Idea:** At every index, you have a binary choice — include the current element in the subset, or don't. Every node visited in the recursion tree (not just leaves) is a valid answer.

### 1.1 Subsets II
- **Company Tags:** Snapdeal
- **LeetCode:** https://leetcode.com/problems/subsets-ii/
- **Description:** Given an integer array `nums` that may contain duplicates, return all possible subsets (the power set), without duplicate subsets.
- **Input:** `nums = [1,2,2]`
- **Output:** `[[],[1],[1,2],[1,2,2],[2],[2,2]]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    Company Tags  : Snapdeal
    Leetcode Link : https://leetcode.com/problems/subsets-ii/
*/

class Solution {
public:
    void generate(vector<int>& nums, vector<int> sub, vector<vector<int>>& result, int start) {
        result.push_back(sub);
        
        for(int i = start; i<nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1])
                continue;
            sub.push_back(nums[i]);
            generate(nums, sub, result, i+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;
        sort(nums.begin(), nums.end());
        generate(nums, sub, result, 0);
        return result;
    }
};
```

---

## 2. Combinations Pattern

> **Idea:** Choose `k` elements out of `n`, starting from an index and always moving forward, so the same combination isn't generated twice. Duplicate handling is done via sorting + skip-adjacent-equal at the same recursion depth.

### 2.1 Combinations
- **Company Tags:** META
- **LeetCode:** https://leetcode.com/problems/combinations/
- **Description:** Given two integers `n` and `k`, return all possible combinations of `k` numbers chosen from the range `[1, n]`.
- **Input:** `n = 4, k = 2`
- **Output:** `[[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
      MY YOUTUBE VIDEO ON THIS : https://www.youtube.com/watch?v=QQ9Tn2i269I
      Company Tags             : META
      Leetcode Link            : https://leetcode.com/problems/combinations/
*/

//Khandani Approach of backtracking (Using for loop)
class Solution {
public:
    vector<vector<int>> result;
    
    void solve(int start, int n, int k, vector<int>& temp) {
        if(k == 0) {
            result.push_back(temp);
            return;
        }

        for(int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(i+1, n, k-1, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        
        solve(1, n, k, temp);
        
        return result;
    }
};


//Khandani Backtracking Approach (without for loop)
class Solution {
public:
    vector<vector<int>> result;
    
    void solve(int start, int n, int k, vector<int>& temp) {
        if(k == 0) {
            result.push_back(temp);
            return;
        }
        
        if(start > n)
            return;
        
        temp.push_back(start);
        solve(start+1, n, k-1, temp);
        temp.pop_back();
        solve(start+1, n, k, temp);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        
        solve(1, n, k, temp);
        
        return result;
    }
};
```

### 2.2 Combination Sum II
- **Company Tags:** Adobe, Amazon, Microsoft
- **LeetCode:** https://leetcode.com/problems/combination-sum-ii/
- **Description:** Given a collection of candidate numbers (`candidates`, may contain duplicates) and a `target`, find all unique combinations where the candidates sum to `target`. Each number may only be used once.
- **Input:** `candidates = [10,1,2,7,6,1,5], target = 8`
- **Output:** `[[1,1,6],[1,2,5],[1,7],[2,6]]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=bfKwLi6jtDk
    Company Tags                : Adobe, Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/combination-sum-ii/
*/


/******************************************************** C++ ********************************************************/
//Khaandani Template Backtracking
//T.C : O(2^n)
//S.C : O(n)
class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1])
                continue; //ignore duplicate elements
            curr.push_back(candidates[i]);
            solve(candidates, target-candidates[i], curr, result, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); //because we will ignore duplicate elements
        solve(candidates, target, curr, result, 0);
        return result;
    }
};
```

### 2.3 Combination Sum III
- **Company Tags:** Adobe, Amazon, Microsoft
- **LeetCode:** https://leetcode.com/problems/combination-sum-iii/
- **Description:** Find all valid combinations of `k` numbers from digits `1-9` that sum up to `n`, using each number at most once.
- **Input:** `k = 3, n = 7`
- **Output:** `[[1,2,4]]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    Company Tags  : Adobe, Amazon, Microsoft
    Leetcode Link : https://leetcode.com/problems/combination-sum-iii/
*/

//Approach-1 (Start with this approach. Build from bad to best solution in interviews)
class Solution {
public:
    vector<vector<int>> result;
    void generate(vector<int>& nums, vector<int>& temp, int idx, int k, int target) {
        if(target == 0 && temp.size() == k) {
            result.push_back(temp);
            return;
        }

        if(idx >= nums.size() || target < 0) {
            return;
        }

        for(int i = idx; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            generate(nums, temp, i+1, k, target-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> temp;

        generate(nums, temp, 0, k, n);

        return result;
    }
};

//Approach-2 (without using nums vector)
class Solution {
public:
    vector<vector<int>> result;

    void generate(int num, vector<int>& temp, int k, int target) {
        if(target == 0 && temp.size() == k) {
            result.push_back(temp);
            return;
        }

        if(num >= 10 || target < 0) {
            return;
        }

        for(int i = num; i<10; i++) {
            temp.push_back(i);
            generate(i+1, temp, k, target-i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int num = 1;
        vector<int> temp;

        generate(num, temp, k, n);

        return result;
    }
};
```

### 2.4 Combination Sum IV
- **Company Tags:** Google, Facebook, Snapchat
- **LeetCode:** https://leetcode.com/problems/combination-sum-iv/
- **Description:** Given an array of distinct integers `nums` and a `target`, return the number of possible **ordered** combinations (permutation-like) that add up to `target`. This is a counting DP problem solved via backtracking + memoization.
- **Input:** `nums = [1,2,3], target = 4`
- **Output:** `7` (combinations: `(1,1,1,1)`, `(1,1,2)`, `(1,2,1)`, `(1,3)`, `(2,1,1)`, `(2,2)`, `(3,1)`)

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YyuwTwXzSxY
    Company Tags                : Google, Facebook, Snapchat
    Leetcode Link               : https://leetcode.com/problems/combination-sum-iv/
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Using Khandaani Backtracking Template + Memoization to Pass)
/*
The main crux here is that you will have to start again from index 0 to consider all possible combinations
For example : in [1,2,3], target = 4
We can also have [1, 2, 1] -> I added 1 and then 2 and then again added 1 (This is possible only when we
restart from 0 also)
*/
//T.C : O(N*target)
class Solution {
public:
    int n;
    int t[1001][201];
    int solve(vector<int>& nums, int target, int idx) {
        if(target == 0)
            return 1;
        
        if(idx >= n || target < 0)
            return 0;
        
        if(t[target][idx] != -1)
            return t[target][idx];
        
        int take_idx    = solve(nums, target - nums[idx], 0);
        int reject_idx  = solve(nums, target, idx+1);
        
        return t[target][idx] = take_idx + reject_idx;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        
        return solve(nums, target, 0);
    }
};

//Approach-2 (Same backtracking + but just using for loop)
//T.C : O(N*target)
class Solution {
public:
    int n;
    int t[1001][201];
    
    int solve(int idx, vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        
        if(idx >= n || target < 0)
            return 0;
        
        int result = 0;
        
        if(t[target][idx] != -1)
            return t[target][idx];
        
        for(int i = idx; i<n; i++) {
            int take_i   = solve(0, nums, target-nums[i]);
            
            result += take_i;
        }
        
        return t[target][idx] = result;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, target);
    }
};

//Approach-3 (In Approach-2 above, you can see that we no longer need to pass idx BECAUSE the for loop always starts from 0)
//So, remove idx from parameter
//T.C : O(N*target)
class Solution {
public:
    int n;
    int t[2001];
    
    int solve(vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        
        if(target < 0)
            return 0;
        
        int result = 0;
        
        if(t[target] != -1)
            return t[target];
        
        for(int i = 0; i<n; i++) {
            int take_i   = solve(nums, target-nums[i]);
            
            result += take_i;
        }
        
        return t[target] = result;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, target);
    }
};
```

---

## 3. Permutations Pattern

> **Idea:** Order matters. Either swap elements in place to fix each position, or track a `used[]`/frequency map to build the permutation one slot at a time. Duplicates are handled by sorting + skipping same values at a level, or using a `set`/frequency map.

### 3.1 Permutations
- **Company Tags:** Accolite, Amazon, OYO Rooms, Samsung, Snapdeal, Citrix, Walmart, MAQ Software, Cisco, Apple
- **LeetCode:** https://leetcode.com/problems/permutations/
- **Description:** Given an array `nums` of distinct integers, return all possible permutations.
- **Input:** `nums = [1,2,3]`
- **Output:** `[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=T8hqjK94Fig
    Compnay Tags                : Accolite, Amazon, OYO Rooms, Samsung, Snapdeal, Citrix, Walmart, MAQ Software, Cisco, Apple
    Leetcode Qn Link            : https://leetcode.com/problems/permutations/
*/


//Approach-1 (Swapping elements in nums)
class Solution {
public:
    vector<vector<int>> result;
    int n;
    
    void solve(int idx, vector<int>& nums) {

        if(idx == n) {
            result.push_back(nums);
            return;
        }
        
        for(int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);
            
            solve(idx+1, nums);
            
            swap(nums[i], nums[idx]);
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        
        solve(0, nums);
        
        return result;
    }
};


//Approach-2 (A very general Backtracking pattern which can help solve subsets, Subsets II, Permutations, Permutations II,  Combination Sum, Combination Sum II as well.
class Solution {
public:
    vector<vector<int>> result;
    unordered_set<int> st;
    int n;
    
    void solve(vector<int>& temp, vector<int>& nums) {

        if(temp.size() == n) {
            result.push_back(temp);
            return;
        }
        
        for(int i = 0; i<n; i++) {
            if(st.find(nums[i]) == st.end()) {
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                solve(temp, nums);

                st.erase(nums[i]);
                temp.pop_back();
            }
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        
        vector<int> temp;
        
        solve(temp, nums);
        
        return result;
    }
};
```

### 3.2 Permutations II
- **Company Tags:** Google, Accolite, Amazon, OYO Rooms, Samsung, Snapdeal, Citrix, Walmart, MAQ Software, Cisco, Apple
- **LeetCode:** https://leetcode.com/problems/permutations-ii/
- **Description:** Given a collection of numbers `nums` that might contain duplicates, return all possible unique permutations.
- **Input:** `nums = [1,1,2]`
- **Output:** `[[1,1,2],[1,2,1],[2,1,1]]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*                 Scroll down to see JAVA code also     */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Vd2YizhbN74
    Company Tags                : Google, Accolite, Amazon, OYO Rooms, Samsung, Snapdeal, Citrix, Walmart, MAQ Software, Cisco, Apple
    Leetcode Qn Link            : https://leetcode.com/problems/permutations-ii/
*/

/********************************************************* C++ *********************************************************/
//Approach-1 (Using same concept as Permutation-I but keeping count to avoid duplicates)
//T.C : O(N * N!)
//S.C : O(N)
class Solution {
public:
    int n;
    vector<vector<int>> result;
    void backtrack(vector<int>& temp, unordered_map<int, int>& mp) {

        if (temp.size() == n) { //we got all numbers
            result.push_back(temp);
            return;
        }

        for (auto& [num, count] : mp) {

            if (count == 0)
                continue;
            
            // Do something
            temp.push_back(num);
            mp[num]--;

            // Explore it
            backtrack(temp, mp);

            // Undo it
            temp.pop_back();
            mp[num]++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> mp;
        
        // count the occurrence of each number
        for (int& num : nums) {
            mp[num]++;
        }
        
        vector<int> temp;
        backtrack(temp, mp);
        
        return result;
    }
};



//Approach-2 (Using swap technique but avoiding duplicates by using set)
//T.C : O(N * N!) worst case
//S.C : O(N)
class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(int idx, vector<int>& nums) {
        if(idx == n) {
            result.push_back(nums);
            return;
        }
        
        unordered_set<int> uniqueSet;
        for(int i = idx; i < n; i++) {
            
            if(uniqueSet.count(nums[i]) > 0) {
                continue;
            }
            
            uniqueSet.insert(nums[i]);
            
            swap(nums[i], nums[idx]);

            solve(idx+1, nums);

            swap(nums[i], nums[idx]);
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        
        solve(0, nums);
        
        return result;
    }
};
```

### 3.3 All Unique Permutations of an array
- **Company Tags:** Google
- **GfG:** https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1
- **Description:** Given an array `arr` (may contain duplicates), find all its unique permutations.
- **Input:** `arr = [1,1,2]`
- **Output:** `[[1,1,2],[1,2,1],[2,1,1]]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : will soon come
    Company Tags                : Google
    GfG Link                    : https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1
//T.C : O(n*n!)
//S.C : O(n*n!)
class Solution {
  public:
    unordered_set<string> st;
    vector<vector<int>> result;
    int N;
    
    
    void solve(vector<int> &arr, vector<int>& temp, vector<bool>& used) {
        if(temp.size() == N) {
            string s = "";
            for(int &x : temp) {
                s += to_string(x);
            }
            if(st.find(s) == st.end()) {
                result.push_back(temp);
                st.insert(s);
            }
            return;
        }
        
        
        for(int i = 0; i < N; i++) {
            if(used[i] == false) {
                temp.push_back(arr[i]);
                used[i] = true;
                
                solve(arr, temp, used);
                
                used[i] = false;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        N = n;
        
        vector<bool> used(n, false);
        vector<int> temp;
        sort(begin(arr), end(arr));
        solve(arr, temp, used);
        
        return result;
    }
};


//Approach-2
//T.C : O(n*n!)
//S.C : O(n*n!)
class Solution {
  public:
    vector<vector<int>> result;
    int N;
    
    void solve(vector<int> &arr, vector<bool>& used, vector<int>& temp, string tempString) {
        if(temp.size() == N) {
            result.push_back(temp);
            return;
        }
        //1, 1, 2
        //tempString = "112"
        for(int i = 0; i < N; i++) {
            
            if(used[i] == true || (i > 0 && arr[i] == arr[i-1] && used[i-1] == true)) {
                continue;
            }
            
            used[i] = true;
            temp.push_back(arr[i]);
            
            
            solve(arr, used, temp,tempString);
            
            temp.pop_back();
            used[i] = false;
            
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(begin(arr), end(arr));
        
        vector<int> temp;
        string tempString="";
        vector<bool> used(n, false);
        N = n;
        
        solve(arr, used, temp,tempString);
        
        return result;
        
    }
};
```

---

## 4. String Partitioning Pattern

> **Idea:** Try every possible "cut point" starting from the current index, validate the resulting piece (palindrome check / dictionary lookup / uniqueness check), and recurse on the remainder.

### 4.1 Palindrome Partitioning
- **Company Tags:** Google, Amazon, Microsoft, Meta
- **LeetCode:** https://leetcode.com/problems/palindrome-partitioning/
- **Description:** Given a string `s`, partition it such that every substring of the partition is a palindrome. Return all possible palindrome partitionings.
- **Input:** `s = "aab"`
- **Output:** `[["a","a","b"],["aa","b"]]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*         Scroll below to see JAVA Code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Backtracking         - https://www.youtube.com/watch?v=jHR7KUAAEzw
                                  DP + Backtracking    - https://www.youtube.com/watch?v=pxaqbkMxdBA
    Company Tags                : Google, Amazon, Microsoft, Meta
    Leetcode Link               : https://leetcode.com/problems/palindrome-partitioning/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1
*/

/******************************************************** C++ ********************************************************/
//Approach-1 (Using Bakctracking Khandani Template)
//Whenever a question asks for "Generating all possible" something, think about Backtracking once
//T.C : O(n * 2^n) - For a string of length n, there are 2^(𝑛 − 1) potential ways to partition it (since each position can either be a cut or not). and we also check palindrome O(n)
//S.C : O(n * 2^n) - Number of partitions * their length
class Solution {
public:
    int n;
    
    bool isPalindrome(string &s, int l, int r) {
        
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
        
    }
    
    void backtrack(string &s, int idx, vector<string> curr, vector<vector<string>> &result) {
        
        if(idx == n) {
            result.push_back(curr);
            return;
        }
        
        
        for(int i = idx; i<n; i++) {
            
            if(isPalindrome(s, idx, i)) {
                
                curr.push_back(s.substr(idx, i-idx+1));
                
                backtrack(s, i+1, curr, result);
                
                curr.pop_back();
                
            }
            
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>> result;
        vector<string> curr;
        
        backtrack(s, 0, curr, result);
        
        return result;
        
    }
};


//Approach-2 (Using DP + Backtracking)
//T.C : O(2^n)
//S.C : O(n^2)
class Solution {
public:

    void solve(string &s, int i, vector<string>& currPartition, vector<vector<bool>>& t, vector<vector<string>>& result) {
        if(i == s.length()) { //I was able to successfully partition the entire string
            result.push_back(currPartition);
            return;
        }

        for(int j = i; j < s.length(); j++) {
            if(t[i][j] == true) { //palindrome
                currPartition.push_back(s.substr(i, j-i+1));
                solve(s, j+1, currPartition, t, result);
                currPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));

        // Initialize the DP table for palindromic substrings
        //t[i][j] = true -> s[i...j] is a palindrome
        
        for (int i = 0; i < n; ++i) {
            t[i][i] = true; //substring of single character is always a palindrome
        }
        
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < n - L + 1; ++i) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    if (L == 2) {
                        t[i][j] = true;
                    } else {
                        t[i][j] = t[i + 1][j - 1];
                    }
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currPartition;
        solve(s, 0, currPartition, t, result);

        return result;
    }
};
```

### 4.2 Split a String Into the Max Number of Unique Substrings
- **Company Tags:** Will update soon
- **LeetCode:** https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings
- **Description:** Given a string `s`, return the maximum number of unique substrings that `s` can be split into.
- **Input:** `s = "ababccc"`
- **Output:** `5` (`"a","b","ab","c","cc"`)

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=sTzh1L7BkQA
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings
*/


/************************************************************ C++ ************************************************/
//Approach (Using simple backtracking)
//T.C : O(n*2^n)
//S.C : O(n)
class Solution {
public:

    void solve(string& s, int idx, unordered_set<string>& st, int currCount, int& maxCount) {
        if(currCount + (s.length() - idx) <= maxCount) { //Pruning for slight improvement
            return;
        }

        if(idx == s.length()) {
            maxCount = max(maxCount, currCount);
        }

        for(int j = idx; j < s.length(); j++) {
            string sub = s.substr(idx, j-idx+1);
            if(st.find(sub) == st.end()) {
                st.insert(sub);
                solve(s, j+1, st, currCount+1, maxCount);
                st.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCount  = 0;
        int currCount = 0;
        solve(s, 0, st, currCount, maxCount);

        return maxCount;
    }
};
```

### 4.3 Word Break II
- **Company Tags:** Meta Phone Screen Interview, Twitter, Snapchat, Dropbox, Uber, Google
- **LeetCode:** https://leetcode.com/problems/word-break-ii/description
- **Description:** Given a string `s` and a dictionary `wordDict`, add spaces to `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
- **Input:** `s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]`
- **Output:** `["cats and dog","cat sand dog"]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
        MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=TmkRMtbXVPw
        Company Tags                : Meta Phone Screen Interview, Twitter, Snapchat, Dropbox, Uber, Google
        Leetcode Link               : https://leetcode.com/problems/word-break-ii/description
*/


/******************************************************* C++ *******************************************************/
//Approach-1 (Using simple backtracking)
//T.C : O(2^n)
//S.C : max depth of recursion is n (length of string s). You can say O(n) . You also have to store those sentences which is O(2^n)
class Solution {
public:
    vector<string> result;
    unordered_set<string> dict;

    void solve(int i, string& currSentence, string &s) {
        if(i >= s.length()) {
            result.push_back(currSentence);
            return;
        }

        for(int j = i; j < s.length(); j++) {

            string tempWord = s.substr(i, j-i+1);

            if(dict.find(tempWord) != dict.end()) {
                string origSentence = currSentence;
                if(!currSentence.empty())
                    currSentence += " ";
                
                currSentence += tempWord;

                solve(j+1, currSentence, s);

                currSentence = origSentence;

            }

        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &word : wordDict) {
            dict.insert(word);
        }

        string currSentence = "";
        solve(0, currSentence, s);

        return result;
    }
};



//Approach-2 (Using simple backtracking)
//T.C : O(2^n)
//S.C : max depth of recursion is n (length of string s). You can say O(n) . You also have to store those sentences which is O(2^n)
class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> mp;

    vector<string> solve(string &s) {
       if(s.empty()) {
            return {""};
       }
      
       if(mp.count(s))
            return mp[s];

        if(mp.count(s))
            return mp[s];
        
        vector<string> result;
        for(int l = 1; l <= s.length(); l++) {
            string currWord   = s.substr(0, l);
            if(dict.count(currWord)) {
                string remainWord = s.substr(l);
                vector<string> remainResult = solve(remainWord);
                for(string &w : remainResult) {
                    string toAdd = currWord + (w.empty() ? "" : " ") + w;
                    result.push_back(toAdd);
                }
            }
        }


        return mp[s] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string &word : wordDict) {
            dict.insert(word);
        }

        return solve(s);
    }
};
```

---

## 5. Grid / Matrix DFS Pattern

> **Idea:** Classic DFS/backtracking on a 2D grid — mark the current cell as visited (or temporarily mutate it), explore all 4 directions, then restore the cell before returning (undo).

### 5.1 Word Search
- **Company Tags:** Apple, Amazon, Microsoft, Intuit
- **LeetCode:** https://leetcode.com/problems/word-search/
- **Description:** Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` exists in the grid, formed by adjacent (horizontally/vertically) cells, without reusing the same cell.
- **Input:** `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"`
- **Output:** `true`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*         Scroll to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=whyax_vB8xY
    Company Tags                : Apple, Amazon, Microsoft, Intuit
    Leetcode Link               : https://leetcode.com/problems/word-search/
*/

/************************************************************ C++ ***************************************************/
/*Space Complexity: O(L)
Time Complexity: O(M * N * 3^L)
Space Complexity is because of recursion - to store function stack context.
Time Complexity - from every block we go in three adjacent blocks (avoiding the direction we came from). 
This walk can go for max of L times. So each thred at most goes L length long. -> O(3^L).
Now this is applied at each node from main calling function -> O(M * N). Therefore, O(M * N * 3^L).
*/
class Solution {
public:
    int l, m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx) {
        if(idx >= l)
            return true;
        
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$';
        
        for(auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(find(board, i_, j_, word, idx+1))
                return true;
        }
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.length();
        if(m*n < l)
            return false;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == word[0] && find(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};


//Thanks to sabra-jain for providing the JAVA code <3
```

### 5.2 Path with Maximum Gold
- **Company Tags:** GOOGLE
- **LeetCode:** https://leetcode.com/problems/path-with-maximum-gold/description/
- **Description:** In a gold mine `grid`, every cell has a value representing gold amount (0 means no gold). Collect the maximum amount of gold by starting/stopping anywhere, moving in 4 directions, and never visiting the same cell twice.
- **Input:** `grid = [[0,6,0],[5,8,7],[0,9,0]]`
- **Output:** `24` (path `9 -> 8 -> 7`)

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also     */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qlgeXDM1z7A
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/path-with-maximum-gold/description/
*/


/********************************************************* C++ *************************************************/
//Approach - Using DFS
//T.C : O(m*n * 4^(cells with gold))
//S.C : O(cells with gold) - the length of a path through gold will contribute to the recursive call stack
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int DFS(vector<vector<int>>& grid, int i, int j) {

        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) {
            return 0; //Zero gold
        }

        int originalGoldValue = grid[i][j];
        grid[i][j] = 0;

        int maxGold = 0;

        //up, down, left, right
        for(vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            maxGold = max(maxGold, DFS(grid, new_i, new_j));
        }


        grid[i][j] = originalGoldValue;
        return originalGoldValue + maxGold;


    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxGold = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] != 0) {
                    //It has gold
                    maxGold = max(maxGold, DFS(grid, i, j));
                }

            }
        }

        return maxGold;
    }
};
```

### 5.3 Unique Paths III
- **Company Tags:** Apple, Amazon(on-site), Meta, Microsoft, Salesforce
- **LeetCode:** https://leetcode.com/problems/unique-paths-iii/
- **Description:** Given a grid with a start (`1`), an end (`2`), empty squares (`0`), and obstacles (`-1`), find the number of paths that walk over every non-obstacle square exactly once, from start to end.
- **Input:** `grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]`
- **Output:** `2`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=eagGLroZXMk
    Company Tags                : Apple, Amazon(on-site), Meta, Microsoft, Salesforce
    Leetcode Link               : https://leetcode.com/problems/unique-paths-iii/
*/

class Solution {
public:
    int m, n;
    int emptyCells;
    int result = 0;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<int>>& grid, int curr_count, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) {
            return;
        }
        
        if(grid[i][j] == 2) {
            if(curr_count == emptyCells) {
                result++;
            }
            return;
        }
        
        
        grid[i][j] = -1;
        for(vector<int> dir:directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            dfs(grid, curr_count+1, i_, j_);
        }
        grid[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        emptyCells = 0;
        result = 0;
        
        int start_x = 0;
        int start_y = 0;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0)
                    emptyCells++;
                
                if(grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        
        emptyCells += 1; //walk over every non-obstacle square exactly once.
        int curr_count = 0;
        
        dfs(grid, curr_count, start_x, start_y);
        
        return result;
    }
};
```

---

## 6. Constraint Satisfaction Pattern (N-Queens style)

> **Idea:** Place items one row/cell at a time; before placing, validate against all constraints (columns, diagonals, sub-grids). Use hash sets or direct grid checks to prune invalid states early.

### 6.1 N-Queens
- **Company Tags:** Accolite, Amazon, Visa, MAQ Software, Amdocs, Twitter, Qualcomm, Google
- **LeetCode:** https://leetcode.com/problems/n-queens/
- **Description:** Place `n` queens on an `n x n` chessboard such that no two queens attack each other. Return all distinct board configurations.
- **Input:** `n = 4`
- **Output:** `[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
	MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FOY49yQcbQ4
    	Company Tags  : Accolite, Amazon, Visa, MAQ Software, Amdocs, Twitter, Qualcomm, Google 
    	Leetcode Link : https://leetcode.com/problems/n-queens/
*/

/*
    Time complexity for Approach-1 : O(N!)
    Unlike the brute force approach, we will only place queens on squares that aren't under attack.
    For the first queen, we have N options. For the next queen, we won't attempt to place it in the
    same column as the first queen, and there must be at least one square attacked diagonally by the
    first queen as well. Thus, the maximum number of squares we can consider for the second queen is
    (N−2). For the third queen, we won't attempt to place it in 2 columns already occupied by the first
    2 queens, and there must be at least two squares attacked diagonally from the first 2 queens.
    Thus, the maximum number of squares we can consider for the third queen is (N-4).
    This pattern continues, resulting in an approximate time complexity of O(N!)
*/

/*************************************************************** C++ *************************************************************************/
//Approach-1 (Simple dfs)
//T.C : O(N!) - Read the reason above
//S.C : O(N) to store the result
class Solution {
public:
    vector<vector<string>> result;
    bool isValid(vector<string>& board, int row, int col) {
        //look for up
        for(int i = row; i>=0; i--) {
            if(board[i][col] == 'Q')
                return false;
        }
        
        //check left diagonal upwards
        for(int i = row, j = col; i>=0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }
        
        //check right diagonal upwards
        for(int i = row, j = col; i>=0 && j<board.size(); i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }
        
        /*
			Wait a second, Why didn't I check any squares downwards ???
			If you notice, every time I am calling dfs(board, row+1); i.e. after
			placing a Queen at a row, I move down. So, It's guaranteed I will
			not get any Queen downwards.
			Example :

			For n = 4

	                _   _    _  Q   (Put int the first row)
	                Q  _   _   _    (While putting here, I only need to see above of me because I have not populated any Q in downwards)
	                _   _   Q  _    (Same,  While putting here, I only need to see above of me because I have not populated any Q in downwards)
	
	                So, on

	*/
        
        
        return true;
    }
    void solve(vector<string>& board, int row) {
        if(row == board.size()) {
            result.push_back(board);
            return;
        }
        
        /*
            place one queen at every row and check before placing
            in every directions where there is risk if being attackes
            i.e. up, diagonally because we are placing queens from
            top row to bottom row, so we need to check if we put a queen
            vertically up in some row or diagonally upwards in some row
        */
        for(int i = 0; i<board.size(); i++) {
            if(isValid(board, row, i)) {
                board[row][i] = 'Q';
                
                solve(board, row+1);
                
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0)
            return {};
        vector<string> board(n, string(n, '.')); 
        //For, n = 3, board = {"...", "...", "..."} initially
        
        solve(board, 0);
        
        return result;
    }
};

//Approach-2
//T.C : O(N!) in worst case it explores all possible configurations
//S.C : O(N) for result and also for storing, cols, diags and antidiags
class Solution {
public:
    vector<vector<string>> result;
    void solve(vector<string>& board, int row, unordered_set<int>& cols, unordered_set<int>& diags, unordered_set<int>& antiDiags) {
        if(row == board.size()) {
            result.push_back(board);
            return;
        }
        
        /*
            For a square (i, j) :
            Diagonally (i-j)      is constant
            Anti diagonally (i+j) is constant
            
            We can use this to find which square(i, j)
            has a risk of being attacked by another queen
            placed already in 'diagonal', or 'anti-diagonal'
            or 'column'
        */
        
        for(int col = 0; col<board.size(); col++) {
            int diag_id       = row-col;
            int anti_diag_id  = row+col;
            
            /*
                If the col, or diagonal or anti_diaonal
                are used, means one of them has a Queen placed
                already which can attack, so look for other column
            */
            if(cols.find(col) != cols.end() ||
              diags.find(diag_id) != diags.end() ||
              antiDiags.find(anti_diag_id) != antiDiags.end())
                continue;
            
            cols.insert(col);
            diags.insert(diag_id);
            antiDiags.insert(anti_diag_id);
            board[row][col] = 'Q';
            
            
            solve(board, row+1, cols, diags, antiDiags);

            cols.erase(col);
            diags.erase(diag_id);
            antiDiags.erase(anti_diag_id);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0)
            return {};
        vector<string> board(n, string(n, '.')); 
        //For, n = 3, board = {"...", "...", "..."} initially
        
        int start_row = 0;
        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> antiDiags;
        solve(board, start_row, cols, diags, antiDiags);
        
        return result;
    }
};
```

### 6.2 N-Queens II
- **Company Tags:** Accolite, Amazon, Visa, MAQ Software, Amdocs, Twitter, Qualcomm, Google
- **LeetCode:** https://leetcode.com/problems/n-queens-ii/
- **Description:** Same setup as N-Queens, but instead of returning the actual boards, return only the **count** of distinct solutions.
- **Input:** `n = 4`
- **Output:** `2`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    Company Tags  : Accolite, Amazon, Visa, MAQ Software, Amdocs, Twitter, Qualcomm, Google 
    Leetcode Link : https://leetcode.com/problems/n-queens-ii/
*/

/*
    A simple approach will be the same as N Queens problem. Instead of returning all the configurations of board (vector<vector<string>>),
    here we return the count of total configurations. Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Backtracking/N-Queens.cpp
    
    But, you don't need to form boards and configurations to count the total configurations. See the solution below.
*/
class Solution {
public:
    int count = 0;
    unordered_set<int> cols;
    unordered_set<int> diags;
    unordered_set<int> antiDiags;
    void dfs(int row, int n) {
        if(row == n) {
            count++;
            return;
        }
        
        for(int col = 0; col<n; col++) {
            int d  = row-col;
            int ad = row+col;
            
            if(cols.count(col) || diags.count(d) || antiDiags.count(ad))
                continue;
            
            cols.insert(col);
            diags.insert(d);
            antiDiags.insert(ad);
            
            dfs(row+1, n);
            
            cols.erase(col);
            diags.erase(d);
            antiDiags.erase(ad);
            
        }
    }
    vector<vector<string>> result;
    int totalNQueens(int n) {
        count = 0;
        if(n == 1)
            return 1;
        if(n <= 3)
            return count;
        
        dfs(0, n);
        
        return count;
        
    }
};
```

### 6.3 Sudoku Solver
- **Company Tags:** Uber, Snapchat, Microsoft, Qualcomm
- **LeetCode:** https://leetcode.com/problems/sudoku-solver/
- **Description:** Write a program to solve a Sudoku puzzle by filling the empty cells (`'.'`) in-place, such that the standard Sudoku rules (row, column, 3x3 sub-box) are satisfied.
- **Input:** A `9x9` board with digits `1-9` and `'.'` for empty cells.
- **Output:** The same board, mutated in-place with a valid, fully solved Sudoku.

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO LINK : https://www.youtube.com/watch?v=5g6fheUtjRs
    Company Tags          : Uber, Snapchat, Microsoft, Qualcomm
    Frequency             : 66%
    Leetcode Link         : https://leetcode.com/problems/sudoku-solver/
*/


/************************************************************ C++ ************************************************/
//Approach (Khandani Backtracking template and all possible options)
//T.C : O(1), fixed frid size
//S.C : O(1), fixed grid size
class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char d) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == d)
                return false;
            
            if(board[row][i] == d) {
                return false;
            }
        }

        int start_i = row/3 * 3;
        int start_j = col/3 * 3;

        for(int k = 0; k < 3; k++) {
            for(int l = 0; l < 3; l++) {
                if(board[start_i+k][start_j+l] == d) {
                    return false;
                }
            }
        }

        return true;
    }

    //2^9
    //O(9 ^ 81)
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) { //O(9)
            for(int j = 0; j < 9; j++) { //O(9)
                if(board[i][j] == '.') {

                    for(char d = '1'; d <= '9'; d++) { 

                        if(isValid(board, i, j, d)) {
                            board[i][j] = d;

                            if(solve(board) == true) {
                                return true;
                            }

                            board[i][j] = '.';
                        }

                    }

                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
```

---

## 7. Partition / Equal Distribution Pattern

> **Idea:** Distribute a set of items into `k` groups (buckets/subsets/people), trying to satisfy a sum/fairness constraint. Sorting in descending order + strong pruning (`visited[]`, `currSum > target`) is key to avoiding TLE.

### 7.1 Matchsticks to Square
- **Company Tags:** Microsoft, Amazon
- **LeetCode:** https://leetcode.com/problems/matchsticks-to-square/
- **Description:** Given `matchsticks` (lengths), determine if you can use all of them to form a square (i.e., partition into 4 subsets of equal sum). This is "Partition to K Equal Sum Subsets" with `k = 4`.
- **Input:** `matchsticks = [1,1,2,2,2]`
- **Output:** `true` (square side = `2`)

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    Company Tags  : Microsoft, Amazon
    Leetcode Link : https://leetcode.com/problems/matchsticks-to-square/
*/

//This problem is nothing but "Partition to K Equal Sum Subsets" with k = 4
//Link (2 approaches) : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Backtracking/Partition%20to%20K%20Equal%20Sum%20Subsets.cpp

/*Time Complexity : O(4^N)
    Bcause we have a total of N sticks and for each one of those matchsticks, we have 4 different possibilities
    for the subsets they might belong to or the side of the square they might be a part of.
*/
class Solution {
public:
    int n;
    int visited[16];
    
    bool possible(vector<int>& matchsticks, int numsIndex, int currSum, int& subsetSum, int k) {
        if(k == 1)
            return true;
        if(currSum == subsetSum) {
            return possible(matchsticks, n-1, 0, subsetSum, k-1);
        }
        
        for(int i = numsIndex; i>=0; i--) {
            if(visited[i] || currSum + matchsticks[i] > subsetSum)
                continue;
            
            visited[i] = 1;
            currSum   += matchsticks[i];
            
            if(possible(matchsticks, i+1, currSum, subsetSum, k))
                return true;
            
            visited[i] = 0;
            currSum   -= matchsticks[i];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(begin(matchsticks), end(matchsticks), 0);
        int k   = 4; //using concept of Leetcode Problem "Partition to K Equal Sum Subsets"
        /*
            If we are able to divide array in 4 parts each of which has equal sum (side of square)
            then it's possible to form the square with that equal subset sum as the side of square
        */
        
        if(sum%4 != 0)
            return false;
        
        memset(visited, 0, sizeof(visited));
        sort(begin(matchsticks), end(matchsticks));
	/*
		Why did I sort ?
		This will actually improve the DFS perofmance because we first put the
		largest matchstick in our subset and if it exceds the target subsetSum,
		then we discard this matchstick because it will further exceed.

		This gave me :
		Runtime: 0 ms, faster than 100.00% of C++ online submissions
	*/
	    
        n                   = matchsticks.size();
        int subsetSum       = sum/4;
        int numsIndex       = n-1;
        int currSum         = matchsticks[numsIndex];
        visited[numsIndex]  = 1;
        
        return possible(matchsticks, numsIndex, currSum, subsetSum, k);
    }
};
```

### 7.2 Partition to K Equal Sum Subsets
- **Company Tags:** Microsoft, Amazon
- **LeetCode:** https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
- **Description:** Given an integer array `nums` and an integer `k`, return `true` if it's possible to divide this array into `k` non-empty subsets whose sums are all equal. (Exact same idea as Matchsticks to Square, generalized to any `k`.)
- **Input:** `nums = [4,3,2,3,5,2,1], k = 4`
- **Output:** `true` (subsets: `(5),(1,4),(2,3),(2,3)`)

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    Company Tags     : Microsoft, Amazon
    Leetcode Link    : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
    
    Exact Same Qn    : Matchsticks to Square (Leetcode - 473)
    
*/

//Approach-1 (Using extra O(k) space)
class Solution {
public:
    int n, k;
    int visited[17];
    
    bool possible(vector<int>& nums, int numsIndex, vector<int>& buckets, int bucketsIndex, int& subsetSum) {
        if(buckets[bucketsIndex] == subsetSum) { 
            /*
                I have found that subsetSum which is of size k has been filled till index k-2, so the last subset need
                not be checked because it will definitely contain "target" (since, sum%k == 0)
            */
            
            if(bucketsIndex == k-2)
                return true;
            
            return possible(nums, n-1, buckets, bucketsIndex+1, subsetSum);
        }
        
        for(int i = numsIndex; i>=0; i--) {
            if(visited[i] || buckets[bucketsIndex]+nums[i] > subsetSum)
                continue;
            
            visited[i] = 1;
            buckets[bucketsIndex] += nums[i];
            
            if(possible(nums, i-1, buckets, bucketsIndex, subsetSum))
                return true;
            
            visited[i] = 0;
            buckets[bucketsIndex] -= nums[i];
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int K) {
        int sum = accumulate(begin(nums), end(nums), 0);
        
        memset(visited, 0, sizeof(visited));
        n = nums.size();
        k = K;
        
        if(sum%k != 0)
            return false;
        
        int subsetSum = sum/k;
        vector<int> buckets(k, 0);
        int bucketsIndex      = 0;
        int numsIndex         = n-1;
        buckets[bucketsIndex] = nums[numsIndex];
        visited[numsIndex]    = 1;
        
        return possible(nums, numsIndex, buckets, bucketsIndex, subsetSum);
        
    }
};

//Approach-2 (Without using any O(k) space)
class Solution {
public:
    int n;
    int visited[17];
    
    bool possible(vector<int>& nums, int numsIndex, int currSum, int& subsetSum, int k) {
        if(k == 1)
            return true;
        
        if(currSum == subsetSum) {
            return possible(nums, n-1, 0, subsetSum, k-1);
        }
        
        for(int i = numsIndex; i>=0; i--) {
            if(visited[i] || currSum+nums[i] > subsetSum)
                continue;
            
            visited[i] = 1;
            currSum   += nums[i];
            
            if(possible(nums, i+1, currSum, subsetSum, k))
                return true;
            
            visited[i] = 0;
            currSum   -= nums[i];
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0);
        
        memset(visited, 0, sizeof(visited));
        n = nums.size();
        
        if(sum%k != 0)
            return false;
        
        int subsetSum      = sum/k;
        int numsIndex      = n-1;
        int currSum        = nums[numsIndex];
        visited[numsIndex] = 1;
        
        return possible(nums, numsIndex, currSum, subsetSum, k);
        
    }
};
```

### 7.3 Fair Distribution of Cookies
- **Company Tags:** (to be updated)
- **LeetCode:** https://leetcode.com/problems/fair-distribution-of-cookies/
- **Description:** Distribute `cookies` (bags, can't split a bag) among `k` children so that the maximum number of cookies any child gets (the "unfairness") is minimized.
- **Input:** `cookies = [8,15,10,20,8], k = 2`
- **Output:** `31`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=vcaAC2fqFpk
    Company Tags                : <soon, I will update>
    Leetcode Link               : https://leetcode.com/problems/fair-distribution-of-cookies/
*/


//TC : O(K^n)
class Solution {
public:
    
    int result = INT_MAX;
    int n;
    
    void solve(int idx, vector<int>& cookies, vector<int>& children, int k) {
        if(idx == cookies.size()) {
            
            int ans = *max_element(begin(children), end(children));
            result = min(result, ans);
            return;
        }
        
        int candy = cookies[idx];
        for(int i = 0; i<k; i++) {
            children[i] += candy;
            
            solve(idx+1, cookies, children, k);
            
            children[i] -= candy;
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> children(k);
        solve(0, cookies, children, k);
        
        return result;
    }
};
```

### 7.4 Tug Of War
- **Company Tags:** Amazon, Samsung (variation of this question)
- **Description:** Divide `n` integers into 2 subsets such that the difference of the sum of the two subsets is as minimum as possible. If `n` is even, both subsets contain exactly `n/2` elements; if odd, one contains `(n-1)/2` and the other `(n+1)/2`.
- **Input:** `arr = [1,2,3,4,5,6]`
- **Output:** `1` (e.g. subsets `{1,3,6}` and `{2,4,5}` → sums `10` and `11`)

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    Company Tags : Amazon, Samsung (variation of this question)
*/

/*
Qn : You are given an array of n integers. You have to divide these n integers into 2 subsets such that difference of sum of two subsets is
as minimum as possible. 
Constraints - 
a) If n is even, both subsets will contain exactly n/2 elements.
b) If n is odd, one of the subsets will contain (n-1)/2 elements and other will contain (n+1)/2 elements.

Example : 
n = 6
{1, 2, 3, 4, 5, 6}

Output:
{1, 3, 6} {2, 4, 5}
*/


/*
    Note :
    (1) If in the question above, the constraints (a) and (b) were not given then this question is nothing but "Minimum Sum Partition" problem.
        Link to it is : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/Minimum%20sum%20partition%20(Memoization%20and%20TopDown)
    (3) If we only had even number of elements always, this qn would be similar to Leetcode-2035 (Check it out in my Bit_Magic section)
    (2) You can also store the results (set1 and set2) which results in minimum difference and print them if asked by interviewer
*/


int minDiff = INT_MAX;
void solve(vector<int>& arr, int idx, int n, vector<int> set1, vector<int> set2, int sum1, int sum2) {
    if(idx == n) {
        minDiff = min(minDiff, abs(sum1-sum2));
        return;
    }
  
    //handles even and odd cases
    //This is acutually an optimmization
    if(set1.size() <= (n+1)/2) {
        set1.push_back(arr[idx]);
        solve(arr, idx+1, n, set1, set2, sum1+arr[idx], sum2);
        set1.pop_back();
    }
    
    //handles even and odd cases
    //This is acutually an optimmization
    if(set2.size() <= (n+1)/2) {
        set2.push_back(arr[idx]);
        solve(arr, idx+1, n, set1, set2, sum1, sum2+arr[idx]);
        set2.pop_back();
    }
}

int tugOfWar(vector<int>& arr) {
    int n = arr.size();
    vector<int> set1;
    vector<int> set2;

    int sum_set1 = 0;
    int sum_set2 = 0;

    solve(arr, 0, n, set1, set2, sum_set1, sum_set2);
    return minDiff;
}
```

### 7.5 Maximum Number of Achievable Transfer Requests
- **Company Tags:** GOOGLE, ADOBE
- **LeetCode:** https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
- **Description:** Given `n` buildings and `requests[i] = [fromi, toi]`, find the maximum number of achievable requests such that each building's net employee change is zero (in-degree = out-degree).
- **Input:** `n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]`
- **Output:** `5`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=eY4PHr1DPp0
    Company Tags                : GOOGLE, ADOBE
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
*/


/*
Time complexity: O((2^m) * N)

We iterate over every two possibilities for each of the M requests 
This is equal to 2^M possibilities. 
At the end we will iterate over N buildings to check if the employee change is zero which takes O(N)
*/

class Solution {
public:
    int m;
    int result = INT_MIN;
    
    void solve(int idx, int count, int n, vector<int>& resultant, vector<vector<int>>& requests) {
        if(idx == m) {
            
            int allZero = true;
            for(int &x : resultant) {
                if(x != 0) {
                    allZero = false;
                    break;
                }
            }
            
            if(allZero) {
                result = max(result, count);
            }
            return;
        }
        
        
        int from = requests[idx][0];
        int to   = requests[idx][1];
        
        resultant[from]--;
        resultant[to]++;
        solve(idx+1, count+1, n, resultant, requests);
        
        resultant[from]++;
        resultant[to]--;
        solve(idx+1, count, n, resultant, requests);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m = requests.size();
        
        vector<int> resultant(n, 0);
        
        solve(0, 0, n, resultant, requests);
        
        return result;
    }
};
```

---

## 8. String / Sequence Generation Pattern

> **Idea:** Build a string/sequence character-by-character (or digit-by-digit), branching over the valid next choices at each position, until the target length is reached.

### 8.1 Generate Parentheses
- **Company Tags:** Samsung
- **LeetCode:** https://leetcode.com/problems/generate-parentheses/
- **Description:** Given `n` pairs of parentheses, generate all combinations of well-formed parentheses.
- **Input:** `n = 3`
- **Output:** `["((()))","(()())","(())()","()(())","()()()"]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7xkPbffc6w8
    Company Tags                : Samsung
    Leetcode Qn Link            : https://leetcode.com/problems/generate-parentheses/
*/

/************************************************************ C++ ************************************************************/
//Approach-1 (Simple Recursion)
//T.C : O(2n* (2^(2n)) -> Removing constant -> O(n * (2^n))
//S.C : O(2*n) -> Removing constant -> O(n) -> recursion stack space - Max depth of recusion tree
class Solution {
public:
    vector<string> result;

    bool isValid(string str) {
        int count = 0;

        for(char ch:str) {
            if(ch == '(')
                count++;
            else
                count--;
            if(count < 0)
                return false;
        }
        return count==0;
    }

    void solve(string& curr, int n) {
        if(curr.length() == 2*n) {
            if(isValid(curr)) {
                result.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(curr, n);

        return result;
    }
};

//Approach-2 (Smart Recursion)
//T.C : O(2^n)
//S.C : O(2*n) -> Removing constant -> O(n) -> recursion stack space - Max depth of recusion tree
class Solution {
public:
    vector<string> result;

    void solve(int n, string curr, int open, int close) {
        if(curr.length() == 2*n) {
            result.push_back(curr);
            return;
        }
        
        if(open < n) {
            curr.push_back('(');
            solve(n, curr, open+1, close);
            curr.pop_back();
        }
        if(close < open) {
            curr.push_back(')');
            solve(n, curr, open, close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(n, curr, 0, 0);

        return result;
    }
};
```

### 8.2 Generate Parenthesess (Alternate Version)
- **Company Tags:** Samsung
- **LeetCode:** https://leetcode.com/problems/generate-parentheses/
- **Description:** Same problem as above — generate all valid combinations of `n` pairs of parentheses — solved with a slightly different recursion signature (passing `length` explicitly instead of relying on `curr.length()` alone, and validating only at the leaf).
- **Input:** `n = 2`
- **Output:** `["(())","()()"]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    Company Tags     : Samsung
    Leetcode Qn Link : https://leetcode.com/problems/generate-parentheses/
    
    Note: Why didn't we have to use a for loop from idx just like blue print of Backtracking ?
    Ans: Because, we don't have any string as input here. Just a number 'n' and we have to generate a string of length 2*n
*/

class Solution {
public:
    bool isValid(string str) {
        int sum = 0;
        for(char ch:str) {
            if(ch == '(')
                sum++;
            else
                sum--;
            if(sum < 0)
                return false;
        }
        return sum==0;
    }
    void generate(string curr, int n, int length, vector<string>& result) {
        if(length == 2*n) {
            if(isValid(curr))
                result.push_back(curr);
            return;
        }
        
        curr.push_back('(');
        generate(curr, n, length+1, result);
        curr.pop_back();
        curr.push_back(')');
        generate(curr, n, length+1, result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        generate("", n, 0, result);
        return result;
    }
};
```

### 8.3 Letter Combinations of a Phone Number
- **Company Tags:** Microsoft, Meta, Epic Systems, Amazon, Flipkart
- **LeetCode:** https://leetcode.com/problems/letter-combinations-of-a-phone-number/
- **Description:** Given a string containing digits `2-9`, return all possible letter combinations that the number could represent (like an old phone keypad).
- **Input:** `digits = "23"`
- **Output:** `["ad","ae","af","bd","be","bf","cd","ce","cf"]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIEDO ON THIS Qn : https://www.youtube.com/watch?v=vgnhZzw-kfU
    Company Tags                : Microsoft, Meta, Epic Systems, Amazon, Flipkart
    Leetcode Link               : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

//Backtracking - Khandani template
/*
    Each digit can be presented at most by 4 letters. On each iteration we go over all 4 of them. And we do this N (the number of digits) time. 
    The complexity would be at most O(4^N)
    But, you you still have to traverse the entire string and do the same amount of operations, so it's O(n • 4^N).
*/
class Solution {
public:
    vector<string> result;
    
    void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp) {
        
        if(idx >= digits.length()) {
            result.push_back(temp);
            return;
        }
        
        
        char ch = digits[idx];
        string str = mp[ch];
        
        for(int i = 0; i<str.length(); i++) {
            
            //Do
            temp.push_back(str[i]);
            solve(idx+1, digits, temp, mp);
            temp.pop_back();
            
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        
        unordered_map<char, string> mp;
        
        mp['2'] =  "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        string temp = "";
        
        solve(0, digits, temp, mp);
        
        return result;
    }
};
```

### 8.4 Letter Tile Possibilities
- **Company Tags:** Will update soon
- **LeetCode:** https://leetcode.com/problems/letter-tile-possibilities
- **Description:** Given a string `tiles` of uppercase letters, return the number of possible non-empty sequences of letters that can be made using the letters printed on those tiles.
- **Input:** `tiles = "AAB"`
- **Output:** `8` (`"A","B","AA","AB","BA","AAB","ABA","BAA"`)

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=cD0D-QSKG20
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/letter-tile-possibilities
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using simple backtracking Khandani Template)
//T.C : O(n!)
//S.C : O(n * n!), total possible sequences = n! and each having n length
class Solution {
public:
    int n;

    void solve(string& tiles, vector<bool>& used, unordered_set<string>& result, string &curr) {
        result.insert(curr);

        for(int i = 0; i < n; i++) {
            if(used[i])
                continue;

            curr.push_back(tiles[i]);
            used[i] = true;

            solve(tiles, used, result, curr);

            used[i] = false;
            curr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {
        n = tiles.length();
        vector<bool> used(n, false);
        unordered_set<string> result;
        string curr = "";

        solve(tiles, used, result, curr);

        return result.size()-1;
    }
};


//Approach-2 (Using count of characters + backtracking)
//T.C : O(n!)
//S.C : O(n), total possible sequences = n! and each having n length
class Solution {
public:
    int total;
    void findSequences(vector<int>& count) {
        total++;

        for (int pos = 0; pos < 26; pos++) {
            if (count[pos] == 0) {
                continue;
            }

            count[pos]--;
            findSequences(count);
            count[pos]++;
        }
    }

    int numTilePossibilities(std::string tiles) {
        total = 0;

        vector<int> count(26, 0);
        for (char c : tiles) {
            count[c - 'A']++;
        }

        findSequences(count);
        return total-1;
    }
};
```

### 8.5 The k-th Lexicographical String of All Happy Strings of Length n
- **Company Tags:** Will update soon
- **LeetCode:** https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
- **Description:** A "happy string" of length `n` uses only `'a','b','c'` with no two adjacent characters equal. Generate all happy strings of length `n` in lexicographical order and return the `k`-th one, or `""` if fewer than `k` exist.
- **Input:** `n = 1, k = 3`
- **Output:** `"c"`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=sQ1gHiDtcXg
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
//S.C : O(n * 2^n) , total 2^n strings eaching having length n
class Solution {
public:
    void solve(int n, string &curr, vector<string> &result) {
        if (curr.length() == n) {
            result.push_back(curr);
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;
            
            // Do
            curr.push_back(ch);

            // Explore
            solve(n, curr, result);

            // Undo
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> result;
        solve(n, curr, result);

        if (result.size() < k) 
            return "";
        
        return result[k - 1];
    }
};



//Approach-2 (Khandani Backtracking remplate - Without storing all possible strings)
//T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
//S.C : O(n) by recursion system stack
class Solution {
public:
    void solve(int n, string &curr, int &count, int k, string &result) {
        if (curr.length() == n) {
            count++;
            if (count == k) {
                result = curr;  // Store only the k-th string
            }
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;
            
            // Do
            curr.push_back(ch);

            // Explore
            solve(n, curr, count, k, result);

            // If result is found, exit early
            if (!result.empty()) return;

            // Undo
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        int count = 0;
        
        solve(n, curr, count, k, result);

        return result;
    }
};
```

### 8.6 Sequential Digits
- **Company Tags:** Let me know when you find it. Help me make this repository perfect :-)
- **LeetCode:** https://leetcode.com/problems/sequential-digits/
- **Description:** A number is "sequential" if its digits are consecutive increasing (e.g. `123`, `2345`). Return all sequential digit numbers in the range `[low, high]`, sorted in increasing order.
- **Input:** `low = 100, high = 300`
- **Output:** `[123,234]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    Company Tags  : Let me know when you find it. Help me make this repository perfect :-)
    Leetcode Link : https://leetcode.com/problems/sequential-digits/
*/

//Approach-1 (Using Backtracking)
class Solution {
public:
    void backtrack(int low, int high, int start, vector<int>& result) {
        if(start == 9)
            return;
        if(start%10 < 9) {
            start = start * 10 + (start%10) + 1; 
            //example : start = 12 ,  now we need 123, so (12*10) + (12%10) + 1 = 123
            if(start>=low && start<=high)
                result.push_back(start);
            backtrack(low, high, start, result); //next, look for 1234
        } else {
            //if start = 123456789 , we need to go now for 23456789
            //Remeber that 123456789 would have started from start = 1
            //so for 23456789, we need to start from 2 i.e. (SD of start)+ 1
            //How to get MSD of 123456789   i.e. MSD = 1
            //If we divide 123456789 from pow(10, # digits -1)
            int num_digits = log10(start);
            int MSD = start/pow(10, num_digits);
            backtrack(low, high, MSD+1, result);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        backtrack(low, high, 1, result);
        sort(result.begin(), result.end());
        return result;
    }
};

//Approach-2 (Using Simple Loop)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        
        vector<int> result;
        for(int i = 0; i<9; i++) {
            for(int j = i+1; j<9; j++) {//why j = i+1 ? Bcz 10 <= low <= high <= 10^9 (No single digit)
                string temp = s.substr(i, j-i+1);
                
                int num = stoi(temp);
                if(num > high) break;
                
                if(num >= low && num <= high)
                    result.push_back(num);
            }
        }        
        
        
        sort(begin(result), end(result));
        return result;
    }
};
```

---

## 9. Expression & Number Construction Pattern

> **Idea:** Backtrack over ways to split digits into numbers and combine them with operators, tracking running values (and for multiplication, the previous operand) so you can "undo" a chained operation correctly.

### 9.1 Expression Add Operators
- **Company Tags:** Google, Facebook, Amazon
- **LeetCode:** https://leetcode.com/problems/expression-add-operators/
- **Description:** Given a string `s` containing only digits and an integer `target`, add the binary operators `+`, `-`, or `*` between digits so that the resulting expression evaluates to `target`. Return all valid expressions.
- **Input:** `s = "123", target = 6`
- **Output:** `["1+2+3","1*2*3"]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    Company Tags  : Google, Facebook, Amazon
    Frequency     : 60%
    Leetcode Link : https://leetcode.com/problems/expression-add-operators/
*/

class Solution {
public:
    vector<string> result;
    int target;
    string s;
    
    void solve(int i, const string& path, long prev, long prevNum) {
        if(i == s.length()) {
            if(prev == target) {
                result.push_back(path);
            }
            return;
        }
        
        string numStr;
        long num = 0;
        for(int j = i; j<s.length(); j++) {
            if(j > i && s[i] == '0') break;
            
            numStr += s[j];
            num     = num*10 + s[j]-'0';
            
            if(i == 0) {
                solve(j+1, path+numStr, num, num);
            } else {
                solve(j+1, path + "+" + numStr, prev+num, num);
                
                solve(j+1, path + "-" + numStr, prev-num, -num);

                solve(j+1, path + "*" + numStr, prev-prevNum + prevNum * num, prevNum*num);
            }
        }
    }
    
    vector<string> addOperators(string s, int target) {
        result = {};
        this->target = target;
        this->s    = s;
        
        solve(0, "", 0, 0);
        
        return result;
    }
};
```

### 9.2 24 Game
- **Company Tags:** Google
- **LeetCode:** https://leetcode.com/problems/24-game/description
- **Description:** Given 4 cards with values `1-9`, determine if you can combine them with `+`, `-`, `*`, `/` and parentheses to make exactly `24`. Backtrack by repeatedly picking two numbers, replacing them with a result of an operation, and recursing until one number is left.
- **Input:** `cards = [4,1,8,7]`
- **Output:** `true` (`(8-4) * (7-1) = 24`)

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=mmu3_8n0fVM
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/24-game/description
*/


/************************************************************ C++ ************************************************/
//Approach (Khandani Backtracking template and all possible options)
//T.C : O(1), size of input is constant and of size 4
//S.C : O(1), size of input is constant and of size 4
class Solution {
public:
    double epsilon = 0.1; //0.01, 0.001 etc will work too.
    // Tolerance for floating-point comparison. To avoid floating point precission errors 

    bool solve(vector<double>& cards) {
        if(cards.size() == 1) {
            return abs(cards[0] - 24) <= epsilon;
        }

        //pick two possible numbers
        for(int i = 0; i < cards.size(); i++) {
            for(int j = 0; j < cards.size(); j++) {
                if(i == j)
                    continue;
                
                vector<double> temp;
                for(int k = 0; k < cards.size(); k++) {
                    if(k != i && k != j) {
                        temp.push_back(cards[k]);
                    }
                }

                double a = cards[i];
                double b = cards[j];
                vector<double> possibleVal = {a+b, a-b, b-a, a*b}; //b-a is not required, our i and j for loop will take care of it

                if(abs(b) > 0.0) {
                    possibleVal.push_back(a/b);
                }

                if(abs(a) > 0.0) {
                    possibleVal.push_back(b/a); //b/a is not required, our i and j for loop will take care of it
                }

                for(double val : possibleVal) {
                    temp.push_back(val); //Do
                    if(solve(temp) == true) //Explore
                        return true;
                    temp.pop_back(); //Undo
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i = 0; i < cards.size(); i++) {
            nums.push_back(1.0 * cards[i]);
        }
        return solve(nums);
    }
};
```

---

## 10. Subsequence Selection Pattern

> **Idea:** Similar to subsets, but with an extra ordering/uniqueness constraint (non-decreasing, no adjacent equal-value repeats, or a "beautiful" difference rule). A `set`/frequency map at each recursion level avoids generating the same subsequence twice.

### 10.1 Non-decreasing Subsequences
- **Company Tags:** (soon)
- **LeetCode:** https://leetcode.com/problems/non-decreasing-subsequences/
- **Description:** Given an integer array `nums`, return all the different possible non-decreasing subsequences of length ≥ 2.
- **Input:** `nums = [4,6,7,7]`
- **Output:** `[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8dfPwZvvDc8
    Company Tags                : <soon>
    Leetcode Link               : https://leetcode.com/problems/non-decreasing-subsequences/
*/

/*
    NOTE : Exact same JAVA code available in my comment section of this YouTube video (link above)
*/

class Solution {
public:
    int n;
   
    void backtrack(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& result) {
        if(curr.size() > 1)
            result.push_back(curr);
        
        unordered_set<int> st;
        for(int i = idx; i<n; i++) {
            if((curr.empty() || nums[i]  >= curr.back()) && st.find(nums[i]) == st.end()) {
                
                curr.push_back(nums[i]);
                backtrack(nums, i+1, curr, result);
                curr.pop_back();
                
                st.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        n = nums.size();
        vector<vector<int>> result;
    
        
        vector<int> curr;
        
        backtrack(nums, 0, curr, result);
        
        return result;
    }
};
```

### 10.2 The Number of Beautiful Subsets
- **Company Tags:** (will soon update)
- **LeetCode:** https://leetcode.com/problems/the-number-of-beautiful-subsets/
- **Description:** A subset is "beautiful" if it doesn't contain two elements whose absolute difference equals `k`. Return the number of non-empty beautiful subsets of `nums`.
- **Input:** `nums = [2,4,6], k = 2`
- **Output:** `4` (`[2],[4],[6],[2,6]`)

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll down to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RoEzdG1bB9s
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/the-number-of-beautiful-subsets/
*/

/********************************************************************** C++ **********************************************************************/
//Simple backtracking just like subsets
//T.C : O(2^n)
//S.C : O(n)
class Solution {
public:

    int result;
    int K;
    void dfs(vector<int> &nums, int idx, unordered_map<int, int> &mp) {

        if(idx == nums.size()) {
            result++;
            return;
        }

        //not_take
        dfs(nums, idx+1, mp);
        
        //checking if we can take it or not
        if(!mp[nums[idx] - K] && !mp[nums[idx] + K]) {
                mp[nums[idx]]++;
                dfs(nums, idx + 1, mp);
                mp[nums[idx]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {

        result = 0;
        K = k;

        unordered_map<int, int> mp;
 
        dfs(nums, 0, mp);

        return result - 1; //-1 because we don't want to count empty subset in result
    }
};
```

### 10.3 Longest Subsequence Repeated k Times
- **Company Tags:** Will update soon
- **LeetCode:** https://leetcode.com/problems/longest-subsequence-repeated-k-times/
- **Description:** Given a string `s` and an integer `k`, find the longest subsequence `seq` of `s` such that `seq` repeated `k` times is also a subsequence of `s`.
- **Input:** `s = "letsleetcode", k = 2`
- **Output:** `"let"`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Kc4eUX-heL4
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/longest-subsequence-repeated-k-times/
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * ((n/k)!))
//S.C : O(n/k)
class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string& sub, int k) {
        int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();

        while(i < n && j < k*L) {
            if(s[i] == sub[j%L])
                j++;
            
            i++;
        }

        return j == k * L;
    }

    bool backtracking(string& s, string &curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen) {
        if(curr.length() == maxLen) {
            if(isSubsequence(s, curr, k)) {
                result = curr;
                return true;
            }
            return false;
        }

        for(int i = 25; i >= 0; i--) {
            if(canUse[i] == false || requiredFreq[i] == 0)
                continue;
            
            //DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            //EXPLORE
            if(backtracking(s, curr, canUse, requiredFreq, k, maxLen) == true) {
                return true;
            }

            //UNDO
            curr.pop_back();
            requiredFreq[i]++;

        }

        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        int freq[26] = {};
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k; //atmost this can be used in a subsequence
            }
        }

        int maxLen = n / k;

        for(int len = maxLen; len >= 0; len--) {
            vector<int> tempRequiredFreq = requiredFreq;
            string curr = "";
            if(backtracking(s, curr, canUse, tempRequiredFreq, k, len) == true) {
                return result;
            }
        }

        return result;


    }
};


//Approach-2 IMPROVED BACKTRACKING : (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * ((n/k)!))
//S.C : O(n/k)
class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string& sub, int k) {
        int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();

        while(i < n && j < k*L) {
            if(s[i] == sub[j%L])
                j++;
            
            i++;
        }

        return j == k * L;
    }

    void backtracking(string& s, string &curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen) {
        if(curr.length() > maxLen)
            return;
        
        if((curr.length() > result.length() || (curr.length() == result.length() && curr > result))
            && isSubsequence(s, curr, k)) {
                result = curr;
        }

        for(int i = 0; i <= 25; i++) {
            if(canUse[i] == false || requiredFreq[i] == 0)
                continue;
            
            //DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            //EXPLORE
            backtracking(s, curr, canUse, requiredFreq, k, maxLen);

            //UNDO
            curr.pop_back();
            requiredFreq[i]++;

        }

    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        int freq[26] = {};
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k; //atmost this can be used in a subsequence
            }
        }

        int maxLen = n / k;

        string curr;
        backtracking(s, curr, canUse, requiredFreq, k, maxLen);

        return result;


    }
};
```

---

## 11. Permutation Optimization Pattern

> **Idea:** Instead of collecting *all* permutations, backtrack over permutations while tracking a running cost/constraint, pruning branches early when the partial result can no longer beat the best-known answer (branch and bound).

### 11.1 Find the Minimum Cost Array Permutation
- **Company Tags:** will update soon
- **LeetCode:** https://leetcode.com/problems/find-the-minimum-cost-array-permutation/description/
- **Description:** Given an array `nums` of size `n`, find the permutation `perm` of `[0, n-1]` that minimizes `sum(|perm[i] - nums[perm[i+1]]|)` for `i` in `[0, n-2]` plus the wraparound term, returning the lexicographically smallest permutation among ties.
- **Input:** `nums = [1,0,2]`
- **Output:** `[0,1,2]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=l4B7HTwfNn0
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-minimum-cost-array-permutation/description/
*/


/************************************************ C++ ************************************************/
//T.C : O(n!)
//S.C : O(n)
class Solution {
public:
    int n;
    int minSum = INT_MAX;
    vector<int> result;

    void solve(vector<int>& nums, vector<bool>& visited, vector<int>& temp, int sum) {
        if (minSum <= sum)  //If you remove this, you will get TLE. This eliminates many useless calls further
            return; // No point in going further because sum is going higher than minVal

        if (temp.size() == n) {
            sum += abs(temp.back() - nums[temp[0]]);
            if (sum < minSum) {
                minSum = sum;
                result = temp;   
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.push_back(i);
                solve(nums, visited, temp, sum + abs(temp[temp.size() - 2] - nums[temp[temp.size() - 1]]));
                temp.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();
        vector<bool> visited(n, false);
        vector<int> temp = {0}; // lexicographically smallest will start from 0
        visited[0] = true; // We have used and hence visited 0

        solve(nums, visited, temp, 0);
        return result;
    }
};
```

### 11.2 Construct the Lexicographically Largest Valid Sequence
- **Company Tags:** Will update soon
- **LeetCode:** https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence
- **Description:** Given `n`, construct a sequence containing each number from `1` to `n` once, and each number `i` (for `i > 1`) twice, such that the distance between the two occurrences of `i` is exactly `i`. Return the lexicographically largest such sequence.
- **Input:** `n = 3`
- **Output:** `[3,1,2,3,2]`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wNOZM1Ki4DY
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence
*/


/************************************************************ C++ ************************************************/
//Approach (Using simple backtracking Khandani Template)
//T.C : O(n!)
//S.C : O(n)
class Solution {
public:

    bool solve(int i, int n, vector<int>& result, vector<bool>& used) {
        if(i >= result.size()) {
            return true; //gauranteed answer - we were filling largest numbers first
        }

        if(result[i] != -1) {
            return solve(i+1, n, result, used);
        }

        for(int num = n; num >= 1; num--) {
            if(used[num]) {
                continue;
            }

            //try
            used[num] = true;
            result[i] = num;

            //EXPLORE
            if(num == 1) {
                if(solve(i+1, n, result, used) == true) {
                    return true;
                }
            } else {
                int j = result[i] + i;

                if(j < result.size() && result[j] == -1) {
                    result[j] = num;
                    if(solve(i+1, n, result, used) == true) {
                        return true;
                    }
                    result[j] = -1;
                }
            }

            //UNDO
            used[num] = false;
            result[i] = -1;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n-1, -1);

        vector<bool> used(n+1, false);

        solve(0, n, result, used);

        return result;
    }
};
```

---

## 12. Advanced / Hybrid Backtracking

> **Idea:** Problems that combine backtracking with memoization (state-hashing) or with a greedy/scoring layer on top, because the plain exponential search needs an extra trick to run efficiently.

### 12.1 Pyramid Transition Matrix
- **Company Tags:** Airbnb, Google, Uber, Snapchat
- **LeetCode:** https://leetcode.com/problems/pyramid-transition-matrix
- **Description:** Given a `bottom` row string and a list of `allowed` triples (`"XYZ"` means `Z` can be placed above `X`,`Y`), determine if a pyramid can be built up to a single block at the top.
- **Input:** `bottom = "BCD", allowed = ["BCG","CDE","GEA"]`
- **Output:** `false`

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dWlpBUZDQc0
    Company Tags                : Airbnb, Google, Uber, Snapchat
    Leetcode Link               : https://leetcode.com/problems/pyramid-transition-matrix
*/


/************************************************************ C++ ************************************************/
//Approach (Khandani Backtracking template -> all possible options)
//T.C : ~(L^n) , L = maximum count of top characters available for each pairs in allowed, n = bottom.length()
//S.C : O(n^2) recursion stack can go at most n levels deep, and at each level you keep a partially built row of length ≤ n, so the total stack memory is O(n × n) = O(n²).
class Solution {
public:
    unordered_map<string, bool> t;

    bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx, string above) {
        if(curr.length() == 1) { //pyramid is formed and we are at the top
            return true;
        }

        string key = curr + "_" + to_string(idx) + "_" + above;

        if(t.count(key))
            return t[key];

        if(idx == curr.length()-1) { //time to move to next row i.e. abocve row
            return t[key] =  solve(above, mp, 0, "");
        }

        string pair = curr.substr(idx, 2);
        if(mp.find(pair) == mp.end()) {
            return t[key] = false;
        }

        for(char &ch : mp[pair]) {
            above.push_back(ch); //DO

            if(solve(curr, mp, idx+1, above) == true) //EXPLORE
                return t[key] = true;
            
            above.pop_back(); //UNDO
        }

        return t[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;

        for(auto& pattern : allowed) {
            mp[pattern.substr(0, 2)].push_back(pattern[2]); //"ABC"
        }

        return solve(bottom, mp, 0, "");
    }
};
```

### 12.2 Maximum Score Words Formed by Letters
- **Company Tags:** will update soon
- **LeetCode:** https://leetcode.com/problems/maximum-score-words-formed-by-letters
- **Description:** Given a list of `words`, a list of available `letters`, and a `score` for each of the 26 letters, find the maximum score obtainable by forming any non-empty subset of words using the available letters (each letter used at most once).
- **Input:** `words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]`
- **Output:** `23` (score of `"dad"` + `"good"` = `5+1+5 + 3+2+2+5 = 23`)

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Vn2eno9OIpc
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-score-words-formed-by-letters
*/


/********************************************************************* C++ *********************************************************************/
//Using simple backtracking
//T.C : O(2^n) where n is the total number of words
//S.C : O(n)
class Solution {
public:
    int n;
    int maxScore;

    void solve(int i, vector<int>& score, vector<string>& words, int currScore, vector<int>& freq){
          
        maxScore = max(maxScore, currScore);

        if(i >= n)
            return;

        vector<int> tempFreq = freq;

        int j         = 0;
        int tempScore = 0;

        while(j < words[i].length()) {
            char ch = words[i][j];

            tempFreq[ch - 'a']--;
            tempScore += score[ch - 'a'];

            if(tempFreq[ch-'a'] < 0)
                break;

            j++;
        }

        //Take words[i]
        if(j == words[i].length()) { //It means we could form the word words[i]
            solve(i+1, score, words, currScore + tempScore, tempFreq);
        }

        //Not Take words[i]
        solve(i+1, score, words, currScore, freq);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);

        for(char &ch : letters){
            freq[ch - 'a']++;
        }
        maxScore = INT_MIN;
        n        = words.size();

        solve(0, score, words, 0, freq);
        
        return maxScore;
    }
};
```

---

## 📌 Quick Reference Table

| # | Problem | Pattern | Difficulty |
|---|---------|---------|------------|
| 1 | Subsets II | Subsets | Medium |
| 2 | Combinations | Combinations | Medium |
| 3 | Combination Sum II | Combinations | Medium |
| 4 | Combination Sum III | Combinations | Medium |
| 5 | Combination Sum IV | Combinations (DP) | Medium |
| 6 | Permutations | Permutations | Medium |
| 7 | Permutations II | Permutations | Medium |
| 8 | All Unique Permutations of an array | Permutations | Medium |
| 9 | Palindrome Partitioning | String Partitioning | Medium |
| 10 | Split a String Into the Max Number of Unique Substrings | String Partitioning | Medium |
| 11 | Word Break II | String Partitioning | Hard |
| 12 | Word Search | Grid DFS | Medium |
| 13 | Path with Maximum Gold | Grid DFS | Medium |
| 14 | Unique Paths III | Grid DFS | Hard |
| 15 | N-Queens | Constraint Satisfaction | Hard |
| 16 | N-Queens II | Constraint Satisfaction | Hard |
| 17 | Sudoku Solver | Constraint Satisfaction | Hard |
| 18 | Matchsticks to Square | Partition/Distribution | Medium |
| 19 | Partition to K Equal Sum Subsets | Partition/Distribution | Medium |
| 20 | Fair Distribution of Cookies | Partition/Distribution | Medium |
| 21 | Tug Of War | Partition/Distribution | Medium |
| 22 | Maximum Number of Achievable Transfer Requests | Partition/Distribution | Hard |
| 23 | Generate Parentheses | String Generation | Medium |
| 24 | Generate Parenthesess (alt.) | String Generation | Medium |
| 25 | Letter Combinations of a Phone Number | String Generation | Medium |
| 26 | Letter Tile Possibilities | String Generation | Medium |
| 27 | The k-th Lexicographical String of All Happy Strings of Length n | String Generation | Medium |
| 28 | Sequential Digits | String Generation | Medium |
| 29 | Expression Add Operators | Expression Construction | Hard |
| 30 | 24 Game | Expression Construction | Hard |
| 31 | Non-decreasing Subsequences | Subsequence Selection | Medium |
| 32 | The Number of Beautiful Subsets | Subsequence Selection | Medium |
| 33 | Longest Subsequence Repeated k Times | Subsequence Selection | Hard |
| 34 | Find the Minimum Cost Array Permutation | Permutation Optimization | Hard |
| 35 | Construct the Lexicographically Largest Valid Sequence | Permutation Optimization | Medium |
| 36 | Pyramid Transition Matrix | Advanced/Hybrid | Medium |
| 37 | Maximum Score Words Formed by Letters | Advanced/Hybrid | Hard |

---

*Compiled from the original solution files, organized pattern-wise for quick interview revision.*
