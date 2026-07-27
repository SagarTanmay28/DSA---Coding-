# DP on Grids -- Pattern-wise LeetCode Solutions (C++)

A pattern-wise collection of Grid / Matrix Dynamic Programming problems from LeetCode, each solved with one or more approaches (Recursion + Memoization, Bottom-Up Tabulation, and space-optimized variants where applicable). Problems are grouped by the underlying DP pattern so it's easier to see how techniques from one problem transfer to the next.

## Table of Contents

- [Pattern 1: Basic Grid Path Counting (Down/Right moves)](#pattern-1-basic-grid-path-counting-downright-moves)
  - [62. Unique Paths](#62-unique-paths)
  - [63. Unique Paths II](#63-unique-paths-ii)
- [Pattern 2: Path Sum Minimization](#pattern-2-path-sum-minimization)
  - [64. Minimum Path Sum](#64-minimum-path-sum)
  - [931. Minimum Falling Path Sum](#931-minimum-falling-path-sum)
  - [1289. Minimum Falling Path Sum II](#1289-minimum-falling-path-sum-ii)
- [Pattern 3: Grid Traversal with Extra State/Constraints](#pattern-3-grid-traversal-with-extra-stateconstraints)
  - [174. Dungeon Game](#174-dungeon-game)
  - [3418. Maximum Amount of Money Robot Can Earn](#3418-maximum-amount-of-money-robot-can-earn)
  - [3459. Maximum Path Score in a Grid](#3459-maximum-path-score-in-a-grid)
  - [2435. Paths in Matrix Whose Sum Is Divisible by K](#2435-paths-in-matrix-whose-sum-is-divisible-by-k)
  - [3618. Minimum Cost Path with Teleportations](#3618-minimum-cost-path-with-teleportations)
  - [1594. Maximum Non-Negative Product in a Matrix](#1594-maximum-non-negative-product-in-a-matrix)
- [Pattern 4: Multiple Agents Traversing the Same Grid](#pattern-4-multiple-agents-traversing-the-same-grid)
  - [1463. Cherry Pickup II](#1463-cherry-pickup-ii)
  - [3272. Find the Maximum Number of Fruits Collected](#3272-find-the-maximum-number-of-fruits-collected)
- [Pattern 5: Diagonal Traversal & Square Sub-structures](#pattern-5-diagonal-traversal-&-square-sub-structures)
  - [3459. Length of Longest V-Shaped Diagonal Segment](#3459-length-of-longest-v-shaped-diagonal-segment)
  - [1277. Count Square Submatrices with All Ones](#1277-count-square-submatrices-with-all-ones)
- [Pattern 6: Ordered / Directional Path Counting (DFS + Memo)](#pattern-6-ordered--directional-path-counting-dfs-+-memo)
  - [2328. Number of Increasing Paths in a Grid](#2328-number-of-increasing-paths-in-a-grid)
  - [688. Knight Probability in Chessboard](#688-knight-probability-in-chessboard)
- [Pattern 7: Grid/Row Coloring & Combinatorics DP](#pattern-7-gridrow-coloring-&-combinatorics-dp)
  - [1411. Number of Ways to Paint N x 3 Grid](#1411-number-of-ways-to-paint-n-x-3-grid)
- [Pattern 8: Column/Interval DP with Greedy Structure](#pattern-8-columninterval-dp-with-greedy-structure)
  - [Maximum Walls Destroyed by Robots](#maximum-walls-destroyed-by-robots)
  - [Maximum Score From Grid Operations](#maximum-score-from-grid-operations)

---

## Pattern 1: Basic Grid Path Counting (Down/Right moves)

Classic DP-on-grid problems where a token moves only **down** or **right**, and we count the number of ways to reach the destination, possibly with obstacles blocking some cells.

### 62. Unique Paths

**LeetCode:** https://leetcode.com/problems/unique-paths/

**Problem Statement:**

A robot is placed on the top-left corner of an `m x n` grid. It can only move either **down** or **right** at any point in time. The robot is trying to reach the bottom-right corner of the grid. Find how many possible unique paths exist.

**Example:**

**Input:** m = 3, n = 7
**Output:** 28

**Input:** m = 3, n = 2
**Output:** 3
**Explanation:** From the top-left corner, there are 3 ways to reach the bottom-right corner: Right -> Down -> Down, Down -> Down -> Right, Down -> Right -> Down.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*                   Scroll below to see JAVA code as well                */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Recursion Memoization Only - https://www.youtube.com/watch?v=DaakAKiCkyc
                                  Bottom Up Also Detailed    - https://www.youtube.com/watch?v=QDVxAf_hqRQ
    Company Tags                : Amazon, Cisco, Paytm, OLA Cabs, Walmart, LinkedIn
    Leetcode Link               : https://leetcode.com/problems/unique-paths/
*/

************************************************************ C++ ************************************************************
//Approach-1 - Recursion + Memoization
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& t) {
        if(i == m-1 && j == n-1) {
            return 1; //we found 1 path to reach [m-1][n-1]
        }

        if(i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        int right = solve(i, j+1, m, n, t);
        int down  = solve(i+1, j, m, n, t);

        return t[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m+1, vector<int>(n+1, -1));
        return solve(0, 0, m, n, t);
    }
};

//Approach-2 (using Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    //source = [0][0]
    //Dest = [0][0]
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n));
        //t[i][j] = total no. of ways to reach [i][j] from [0][0]

        t[0][0] = 1; //total ways to reach 0,0 from 0,0

        //Fill 0th row
        for(int col = 1; col < n; col++) {
            t[0][col] = 1;
        }

        //Fill 0th col
        for(int row = 1; row < m; row++) {
            t[row][0] = 1;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }

        return t[m-1][n-1];

    }
};



************************************************************ JAVA ************************************************************
//Approach-1 - Recursion + Memoization
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
```

### 63. Unique Paths II

**LeetCode:** https://leetcode.com/problems/unique-paths-ii/

**Problem Statement:**

Same setup as Unique Paths, but now the grid contains obstacles (marked `1`). The robot still moves only down or right, but cannot step on an obstacle cell. Count the unique paths from top-left to bottom-right.

**Example:**

**Input:** obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
**Output:** 2
**Explanation:** There is one obstacle in the middle of the 3x3 grid, so there are 2 ways to reach the bottom-right corner.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*                   Scroll below to see JAVA code as well                */
/*
    MY YOUTUBE VIDEO ON THIS Qn : Recursion + Memo        - https://www.youtube.com/watch?v=JC1fSPdJjMc
                                  Bottom Up Also Detailed - https://www.youtube.com/watch?v=9RUpue4oMx4
    Company Tags                : Amazon, Cisco, Paytm, OLA Cabs, Walmart, LinkedIn
    Letcode Link                : https://leetcode.com/problems/unique-paths-ii/
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Recursion + Memo)
//Recursion T.C : O(m*n)
//Memo T.C      : O(m*n)
class Solution {
public:
    int m, n;
    int t[101][101];
    
    int solve(vector<vector<int>>& obstacleGrid, int i, int j) {
        
        if(i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] != 0) {
            return 0;
        }
        
        if(t[i][j] != -1)
            return t[i][j];
        
        if(i == m-1 && j == n-1)
            return 1;
        
        //Why we are not making [i][j] visited ?
        //Because robot can only move down or right so it will never visit any visited cell again
        //int temp = obstacleGrid[i][j];
        //obstacleGrid[i][j] = -1;
        
        int right = solve(obstacleGrid, i, j+1);
        int down  = solve(obstacleGrid, i+1, j);
        
        //obstacleGrid[i][j] = temp;
        
        return t[i][j] = right + down;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        
        memset(t, -1, sizeof(t));
        
        return solve(obstacleGrid, 0, 0);
    }
};


//Approach-2 (Bottom Up). T.C : O(m*n)
class Solution {
public:
    int m, n;

    //Tabular approach
    int solve(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> t(m, vector<int>(n, 0));
        if(obstacleGrid[0][0] == 1)
            return 0;
        
        for(int col = 0; col<n; col++) {
            if(col > 0 && obstacleGrid[0][col-1] == 1) {
                t[0][col] = 0;
                obstacleGrid[0][col] = 1; //Bcz now it's not possible to reach any cell in first row from this cell onwards
            }
            else if(obstacleGrid[0][col] == 1)
                t[0][col] = 0;
            else
                t[0][col] = 1;
        }
        
        for(int row = 0; row<m; row++) {
            if(row > 0 && obstacleGrid[row-1][0] == 1) {
                t[row][0] = 0;
                obstacleGrid[row][0] = 1; //Bcz now it's not possible to reach any cell in first col from this cell onwards
            }
            else if(obstacleGrid[row][0] == 1)
                t[row][0] = 0;
            else
                t[row][0] = 1;
        }
        
        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                if(obstacleGrid[i][j] == 1)
                    t[i][j] = 0;
                else
                    t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        
        return solve(obstacleGrid);
        
    }
};





************************************************************ JAVA ************************************************************
//Approach-1 (Recursion + Memo)
//Recursion T.C : O(m*n)
//Memo T.C      : O(m*n)
class Solution {
    Integer t[][]=new Integer[101][101];
    int m, n;
```

---

## Pattern 2: Path Sum Minimization

Instead of counting paths, these problems ask for the path with the **minimum accumulated cost/sum**, moving down/right or falling from one row to the next.

### 64. Minimum Path Sum

**LeetCode:** https://leetcode.com/problems/minimum-path-sum/

**Problem Statement:**

Given an `m x n` grid filled with non-negative numbers, find a path from top-left to bottom-right which minimizes the sum of all numbers along the path. You can only move down or right at any point in time.

**Example:**

**Input:** grid = [[1,3,1],[1,5,1],[4,2,1]]
**Output:** 7
**Explanation:** The path 1→3→1→1→1 minimizes the sum.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6aML2-rJJik
    Company Tags                : OLA, Goldman Sachs, Google (Google asked with small variation)
    Leetcode Link               : https://leetcode.com/problems/minimum-path-sum/   
*/


/***************************************************************************** C++ ******************************************************************/
//Approach-1 (Recur + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int MPS(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& t) {
        if(i == m-1 && j == n-1)
            return t[i][j] = grid[i][j];
        if(t[i][j] != -1)
            return t[i][j];
        if(i == m-1) { //we can only go right
            return t[i][j] = grid[i][j] + MPS(grid, i, j+1, m, n, t);
        } else if(j == n-1) { //we can go only down
            return t[i][j] = grid[i][j] + MPS(grid, i+1, j, m, n, t);
        } else {
            return t[i][j] = grid[i][j] + min(MPS(grid, i+1, j, m, n, t), MPS(grid, i, j+1, m, n, t));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> t(m+1, vector<int>(n+1, -1));
        return MPS(grid, 0, 0, m, n, t);
    }
};

//Approach-2 (Bottom Up DP)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int DFS(vector<vector<int>>& grid, int m, int n) {
        vector<vector<int>> t(m, vector<int>(n));
        t[0][0] = grid[0][0];
        
        for(int i = 1; i<m; i++)
            t[i][0] = t[i-1][0]+grid[i][0];
        
        for(int j = 1; j<n; j++)
            t[0][j] = t[0][j-1]+grid[0][j];

        for(int i = 1; i<m; i++) {
            for(int j = 1; j<n; j++) {
                t[i][j] = grid[i][j] + min(t[i-1][j], t[i][j-1]);
            }
        }
        return t[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return DFS(grid, m, n);
    }
};
```

### 931. Minimum Falling Path Sum

**LeetCode:** https://leetcode.com/problems/minimum-falling-path-sum/

**Problem Statement:**

Given an `n x n` matrix, a falling path starts at any cell in the first row and chooses one cell from each remaining row - the next row's cell must be directly below or diagonally left/right of the current cell. Return the minimum sum of any falling path.

**Example:**

**Input:** matrix = [[2,1,3],[6,5,4],[7,8,9]]
**Output:** 13
**Explanation:** The path [1,4,7] or [1,5,7] gives the minimum sum of 13.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=EQC0ckOyEGs
    Company Tags                : Google, Microsoft, Amazon, Flipkart, OLA, Goldman Sachs, MakeMyTrip, OYO Rooms, Samsung
    Leetcode Link               : https://leetcode.com/problems/minimum-falling-path-sum/
    
    Similar tough problem : Leetcode - 1937 : Maximum Number of Points with Cost  (Must Try !!!!)
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Recur + Memoization) : O(m*n) (New test Case has been added, this will give TLE in last Test Case) (49 / 50 testcases passed)
//T.C : O(m*n)
//S.C : O(101) ~ O(1) (Excluding stack recursion space)
class Solution {
public:
    int MFS(vector<vector<int>>& A, int row, int col, vector<vector<int>>& t) {
        if(row == A.size()-1)
            return A[row][col];
        if(t[row][col] != -1)
            return t[row][col];
        
        int minSum = INT_MAX;
        
        for(int shift = -1; shift<=1; shift++) {
            if(col + shift >=0 && col+shift < A[row].size()) {
                minSum = min(minSum, A[row][col] + MFS(A, row+1, col+shift, t));
            }
        }
        
        return t[row][col] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(); //row
        int n = m; //column
        vector<vector<int>> t(101, vector<int>(101));
        for(int i = 0; i<101; i++) {
            for(int j = 0; j<101; j++) {
                t[i][j] = -1;
            }
        }
        int result = INT_MAX;
        for(int col = 0; col<n; col++) {
            result = min(result, MFS(A, 0, col, t));
        }
        return result;
    }
};

//Approach-2 (Bottom UP DP) : O(m*n)
//T.C : O(m*n)
//S.C :  O(m*n)
class Solution {
public:
    int MFS(vector<vector<int>>& A) {
        int m = A.size();
        vector<vector<int>> t(m, vector<int>(m));
        
        //initialization
        for(int col = 0; col<m; col++) {
            t[0][col] = A[0][col];
        }
        
        for(int row = 1; row < m; row++) {
            for(int col = 0; col < m; col++) {
                t[row][col] = A[row][col] + min({t[row-1][col], 
                                                 t[row-1][max(0, col-1)], 
                                                 t[row-1][min(m-1, col+1)]});
            }
        }

        return *min_element(t[m-1].begin(), t[m-1].end());
        
    }
    int minFallingPathSum(vector<vector<int>>& A) { 
        return MFS(A);
    }
};


//Approach-3 (Bottom Up Space Optimized)
//T.C : O(m*n)
//S.C :  O(m*n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> prev(n);
        for(int col = 0; col<n; col++)
            prev[col] = A[0][col];
        
        for(int row = 1; row<n; row++) {
            vector<int> curr(n);
            for(int col = 0; col<n; col++) {
                curr[col] = A[row][col] + min({prev[max(0, col-1)],  prev[col],  prev[min(n-1, col+1)]});
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
```

### 1289. Minimum Falling Path Sum II

**LeetCode:** https://leetcode.com/problems/minimum-falling-path-sum-ii/

**Problem Statement:**

Same as Minimum Falling Path Sum, but this time the next row's chosen cell must be in a **different column** than the current one (no diagonal-adjacency restriction). Return the minimum sum of a falling path with non-zero shifts.

**Example:**

**Input:** grid = [[1,2,3],[4,5,6],[7,8,9]]
**Output:** 13
**Explanation:** The path with minimum sum picks a different column in every row, e.g. 1→5→7 = 13.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rpW1qKAs4V4
    Company Tags                : Google, Microsoft, Amazon, Samsung
    Leetcode Link               : https://leetcode.com/problems/minimum-falling-path-sum-ii/
    
    Similar tough problem : Leetcode - 1937 : Maximum Number of Points with Cost  (Must Try !!!!)
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Recur + Memoization)
//T.C : O(N^3)
//S.C : O(N^2)
class Solution {
public:
    int n;
    int t[201][201];
    int solve(int row, int col, vector<vector<int>>& grid) {
        if (row == n - 1) {
            return grid[row][col];
        }

        if(t[row][col] != -1) {
            return t[row][col];
        }
        
        int ans = INT_MAX;
        for (int nextCol = 0; nextCol < n; nextCol++) {
            if (nextCol != col) {
                ans = min(ans, solve(row + 1, nextCol, grid));
            }
        }

        return t[row][col] = grid[row][col] + ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        memset(t, -1, sizeof(t));

        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, solve(0, col, grid));
        }

        return result;
    }
};



//Approach-2 (Bottom Up)
//T.C : O(N^3)
//S.C : O(N^2)
class Solution {
public:
    int n;
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> t(n, vector<int>(n, INT_MAX));

        for (int col = 0; col < n; col++) {
            t[n - 1][col] = grid[n - 1][col];
        }

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int ans = INT_MAX;
                for (int nextCol = 0; nextCol < n; nextCol++) {
                    if (nextCol != col) {
                        ans = min(ans, t[row + 1][nextCol]);
                    }
                }
                t[row][col] = grid[row][col] + ans;
            }
        }

        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, t[0][col]);
        }

        return result;
    }
};


//Approach-3 (Getting rid of extra for loop)
//T.C : O(N^2)
//S.C : O(N^2)
class Solution {
public:
    int n;
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> t(n, vector<int>(n, INT_MAX));

        int nextMin1Col = -1;
        int nextMin2Col = -1;
        
        for (int col = 0; col < n; col++) {
            t[n - 1][col] = grid[n - 1][col];
            
            if(nextMin1Col == -1 || t[n - 1][col] <= t[n-1][nextMin1Col]) {
                nextMin2Col = nextMin1Col;
                nextMin1Col = col;
            } else if(nextMin2Col == -1 || t[n - 1][col] <= t[n-1][nextMin2Col]) {
                nextMin2Col = col;
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            
            int min1Col = -1;
            int min2Col = -1;
            
            for (int col = 0; col < n; col++) {
                
                if(col != nextMin1Col) {
                    t[row][col] = grid[row][col] + t[row+1][nextMin1Col];
                } else {
                    t[row][col] = grid[row][col] + t[row+1][nextMin2Col];
                }
                
                if(min1Col == -1 || t[row][col] <= t[row][min1Col]) {
                    min2Col = min1Col;
                    min1Col = col;
                } else if(min2Col == -1 || t[row][col] <= t[row][min2Col]) {
                    min2Col = col;
                }
            }
                            
            nextMin1Col = min1Col;
            nextMin2Col = min2Col;
                
        }

        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, t[0][col]);
        }

        return result;
        //Or you can directly return the minimum from the first row
        //return t[0][nextMin1Col];
    }
};


//Approach-4 
//T.C : O(N^2)
//S.C : O(1)
class Solution {
public:
    int n;
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int nextMin1Col = -1;
        int nextMin2Col = -1;
        
        int nextMin1Val = -1;
        int nextMin2Val = -1;
        
        for (int col = 0; col < n; col++) {

            if(nextMin1Col == -1 || grid[n - 1][col] <= nextMin1Val) {
                nextMin2Col = nextMin1Col;
                nextMin2Val = nextMin1Val;
                
                nextMin1Col = col;
                nextMin1Val = grid[n-1][col];
                
            } else if(nextMin2Col == -1 || grid[n - 1][col] <= nextMin2Val) {
                nextMin2Col = col;
                nextMin2Val = grid[n-1][col];
            }
        }

        for (int row = n - 2; row >= 0; row--) {
            
            int min1Col = -1;
            int min2Col = -1;
            
            int min1Val = -1;
            int min2Val = -1;
            
            for (int col = 0; col < n; col++) {
                
                int ans;
                if(col != nextMin1Col) {
                    ans = grid[row][col] + nextMin1Val;
                } else {
                    ans = grid[row][col] + nextMin2Val;
                }
                
                if(min1Col == -1 || ans <= min1Val) {
                    min2Col = min1Col;
                    min2Val = min1Val;
                    
                    min1Col = col;
                    min1Val = ans;
                } else if(min2Col == -1 || ans <= min2Val) {
                    min2Col = col;
                    min2Val = ans;
                }
            }
                            
            nextMin1Col = min1Col;
            nextMin1Val = min1Val;
            
            nextMin2Col = min2Col;
            nextMin2Val = min2Val;
                
        }

        // Return the minimum from the first row
        return nextMin1Val;
    }
};
```

---

## Pattern 3: Grid Traversal with Extra State/Constraints

These are down/right traversal problems, but an **extra dimension of state** (health, remaining skips, remaining budget, remaining teleports, running remainder, or running product) must be tracked alongside position.

### 174. Dungeon Game

**LeetCode:** https://leetcode.com/problems/dungeon-game/

**Problem Statement:**

A knight starts at the top-left of a dungeon grid and must rescue a princess at the bottom-right, moving only right or down. Each cell adds/subtracts from the knight's health. Find the minimum initial health so the knight's health never drops to 0 or below at any point along some path.

**Example:**

**Input:** dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
**Output:** 7
**Explanation:** Starting with 7 health lets the knight survive the path RIGHT -> RIGHT -> DOWN -> DOWN.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*                   Scroll below to see JAVA code as well                */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Mlcy-9hB6Jc
    Company Tags                : Microsoft, Amazon, Uber
    Leetcode Link               : https://leetcode.com/problems/unique-paths/
*/

/************************************************************ C++ ************************************************************/
//Approach-1 - Brute Force (Binary Search on Answer) and also memoizing it - TLE
//T.C : O(O(log(maxHealth) * m * n * maxHealth), total states in map = m * n * maxHealth
//S.C : O(m * n * maxHealth)
  class Solution {
public:
    int m, n;
    unordered_map<string, int> memo;

    bool canSurvive(int i, int j, vector<vector<int>>& dungeon, int currHealth) {
        if (i >= m || j >= n) return false;

        currHealth += dungeon[i][j];
        if (currHealth <= 0) 
            return false;

        if (i == m - 1 && j == n - 1) 
            return true;

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(currHealth);
        if (memo.count(key))
            return memo[key];

        bool canReach = canSurvive(i + 1, j, dungeon, currHealth) ||
                        canSurvive(i, j + 1, dungeon, currHealth);

        memo[key] = canReach;
        return canReach;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        int left = 1;
        int right = 4 * 1e7;
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            memo.clear();  // clear for new health level

            if (canSurvive(0, 0, dungeon, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};


//Approach-2 (Using Recursion and Memoization) - ACCEPTED
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    int t[201][201];

    int solve(int i, int j, vector<vector<int>>& dungeon) {
        if (i >= m || j >= n)
            return 1e9;

        if (t[i][j] != -1)
            return t[i][j];

        if (i == m - 1 && j == n - 1)
            return t[i][j] = (dungeon[i][j] > 0 ? 1 : abs(dungeon[i][j]) + 1);

        int down  = solve(i + 1, j, dungeon);
        int right = solve(i, j + 1, dungeon);

        int res = min(down, right) - dungeon[i][j];
        return t[i][j] = (res > 0 ? res : 1);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, dungeon);
    }
};



//Approach-3 (Bottom Up) - ACCEPTED
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        //NOTE : We will write bottom up by traversing from bottom right to top left because 
        // when we find t[i][j] we must be already aware of the health for down (t[i+1][j) and right (t[i][j+1])
      
        vector<vector<int>> t(m, vector<int>(n, 0));
        //t[i][j] = min health needed to reach (m-1, n-1) from (i,j)

        // Fill the rest of the DP table
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if(i == m-1 && j == n-1) {
                    t[i][j] = (dungeon[m-1][n-1] > 0 ? 1 : abs(dungeon[m-1][n-1]) + 1);
                } else {
                    int down  = (i+1 >= m) ? 1e9 : t[i+1][j];  // Health needed if moving down
                    int right = (j+1 >= n) ? 1e9 : t[i][j+1]; // Health needed if moving right
                    int res = min(down, right) - dungeon[i][j];  // Calculate the required health

                    // If the result is <= 0, we need at least 1 health
                    t[i][j] = (res > 0 ? res : 1);
                }
            }
        }

        // The result is the minimum health required to start at the top-left corner
        return t[0][0];
    }
};

/************************************************************ C++ ************************************************************/
//Approach-1 - Brute Force (Binary Search on Answer) and also memoizing it - TLE
//T.C : O(O(log(maxHealth) * m * n * maxHealth), total states in map = m * n * maxHealth
//S.C : O(m * n * maxHealth)
class Solution {
    int m, n;
```

### 3418. Maximum Amount of Money Robot Can Earn

**LeetCode:** https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/

**Problem Statement:**

A robot starts at the top-left of a grid of coins (some negative, i.e. 'robbers') and moves right/down to the bottom-right. The robot may neutralize up to 2 robber cells so that cell contributes 0 instead of a loss. Maximize the total money collected.

**Example:**

**Input:** coins = [[0,1,-1],[1,-2,3],[2,-3,4]]
**Output:** 8
**Explanation:** The robot neutralizes the two negative cells it passes through to maximize its earnings.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=4X3B07RFNW8
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn
*/



/**************************************************************** C++ ****************************************************************/
//Approach (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m;
    int n;
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {
        if(i == m-1 && j == n-1) {
            if(coins[i][j] < 0 && neu > 0) {
                return 0; //neutralize kardiya robber ko
            }

            return coins[i][j];
        }

        if(i >= m || j >= n) {
            return INT_MIN;
        }

        if(t[i][j][neu] != INT_MIN) {
            return t[i][j][neu];
        }

        //Take the current cell value
        int take = coins[i][j] + max(solve(coins, i+1, j, neu), solve(coins, i, j+1, neu));

        //Skip current value if you can
        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0) {
            int skipDown = solve(coins, i+1, j, neu-1);
            int skipRight = solve(coins, i, j+1, neu-1);

            skip = max(skipDown, skipRight);
        }

        return t[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {

        m = coins.size();
        n = coins[0].size();

        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(coins, 0, 0, 2);
    }
};
```

### 3459. Maximum Path Score in a Grid

**LeetCode:** https://leetcode.com/problems/maximum-path-score-in-a-grid

**Problem Statement:**

Moving only right/down from top-left to bottom-right, the path score is the sum of visited cells. You may pass through at most `k` cells with a positive value along the way (a 'cost' budget). Maximize the score, or return -1 if the destination is unreachable within the budget.

**Example:**

**Input:** grid = [[5,3],[4,0]], k = 1
**Output:** 8
**Explanation:** Only one positive cell may be visited on the path, so the optimal path is 5 -> 3 -> 0, using exactly one positive cell.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=S8ETOX9njRQ
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-path-score-in-a-grid
*/



/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> t(
            m+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1))
        );

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int cost = k; cost >= 0; cost--) {

                    int newCost = cost + (grid[i][j] > 0);

                    if (newCost > k) continue;

                    // Base case: destination
                    if (i == m - 1 && j == n - 1) {
                        t[i][j][cost] = grid[i][j];
                        continue;
                    }

                    int down  = -1;
                    int right = -1;

                    if (i + 1 < m)
                        down = t[i + 1][j][newCost];

                    if (j + 1 < n)
                        right = t[i][j + 1][newCost];

                    int bestNext = max(down, right);

                    if (bestNext != -1) {
                        t[i][j][cost] = grid[i][j] + bestNext;
                    }
                }
            }
        }

        return t[0][0][0];
    }
};


//Approach-2 (Bottom Up)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int m, n;

    int solve(vector<vector<int>>& grid, int k, int i, int j, int cost, vector<vector<vector<int>>>& t) {
        if(i >= m || j >= n)
            return INT_MIN;
        
        int newCost = cost + (grid[i][j] > 0);

        if(newCost > k)
            return INT_MIN;
        
        if(i == m-1 && j == n-1)
            return grid[i][j]; //score
        
        if(t[i][j][cost] != -1) {
            return t[i][j][cost];
        }
        
        //down
        //right
        int down  = solve(grid, k, i+1, j, newCost, t);
        int right = solve(grid, k, i, j+1, newCost, t);

        int bestNext = max(down, right);

        if(bestNext == INT_MIN) {
            return t[i][j][cost] = INT_MIN;
        }

        return t[i][j][cost] = grid[i][j] + bestNext;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> t(m+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1)));

        int result = solve(grid, k, 0, 0, 0, t);

        return result == INT_MIN ? -1 : result;
    }
};
```

### 2435. Paths in Matrix Whose Sum Is Divisible by K

**LeetCode:** https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k

**Problem Statement:**

Moving only right/down from top-left to bottom-right, count how many paths have a sum of visited values divisible by `k`. Return the count modulo `1e9+7`.

**Example:**

**Input:** grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
**Output:** 2
**Explanation:** There are 2 paths whose total sum is divisible by 3.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=k-9LZZEB1sI
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization : DP On Grids)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<vector<int>>> t;

    int solve(int row, int col, int remain, vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if(row >= m || col >= n)
            return 0;

        if(row == m - 1 && col == n - 1)
            return ((remain + grid[row][col]) % k == 0);

        if(t[row][col][remain] != -1)
            return t[row][col][remain];

        int newRemain = (remain + grid[row][col]) % k;

        int down  = solve(row + 1, col, newRemain, grid, k);
        int right = solve(row, col + 1, newRemain, grid, k);

        return t[row][col][remain] = (down + right) % M;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        t.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(0, 0, 0, grid, k);
    }
};


//Approach-2 (Bottom Up  : DP On Grids)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int M = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int t[m+1][n+1][k+1];
        memset(t, 0, sizeof(t));
        // t[i][j][remain] = number of paths from [i][j] to [m-1][n-1] with current remainder = remain

        // Base case same as recursion
        for(int remain = 0; remain < k; remain++) {
            t[m-1][n-1][remain] = ((remain + grid[m-1][n-1]) % k == 0 ? 1 : 0);
        }

        for(int row = m - 1; row >= 0; row--) {
            for(int col = n - 1; col >= 0; col--) {

                for(int remain = 0; remain < k; remain++) {

                    if(row == m - 1 && col == n - 1)
                        continue;

                    int newRemain = (remain + grid[row][col]) % k;

                    long long down  = t[row + 1][col][newRemain];
                    long long right = t[row][col + 1][newRemain];

                    t[row][col][remain] = (down + right) % M;
                }
            }
        }

        return t[0][0][0];
    }
};
```

### 3618. Minimum Cost Path with Teleportations

**LeetCode:** https://leetcode.com/problems/minimum-cost-path-with-teleportations

**Problem Statement:**

Moving right/down normally costs the value of the destination cell. You are additionally allowed up to `k` free teleports from any cell to any other cell whose value is less than or equal to the current cell's value. Find the minimum cost to go from top-left to bottom-right.

**Example:**

**Input:** grid = [[1,3,3],[1,1,1],[3,2,1]], k = 1
**Output:** 5
**Explanation:** Using one teleport to skip over expensive cells reduces the total cost compared to only moving right/down.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=KySBrz1lk4I
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-path-with-teleportations
*/



/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m^2 * n^2 * k)
//S.C : O(m*n*k)
class Solution {
public:
    int m, n, K;

    // t[i][j][tPort] = min cost from (i,j) with tPort teleports already used
    vector<vector<vector<int>>> t;

    int solve(int i, int j, int tPort, vector<vector<int>>& grid) {
        // Reached destination
        if (i == m - 1 && j == n - 1)
            return 0;

        if (t[i][j][tPort] != -1) 
            return t[i][j][tPort];

        int result = 1e9; //Large value
        int curVal = grid[i][j];

        // Move Right
        if (j + 1 < n) {
            int next = solve(i, j + 1, tPort, grid);
            result = min(result, grid[i][j + 1] + next);
        }

        // Move Down
        if (i + 1 < m) {
            int next = solve(i + 1, j, tPort, grid);
            result = min(result, grid[i + 1][j] + next);
        }

        // Teleport
        if (tPort < K) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    if ((x != i || y != j) && grid[x][y] <= curVal) {
                        result = min(result, solve(x, y, tPort + 1, grid)); // cost = 0
                    }
                }
            }
        }

        return t[i][j][tPort] = result;
    }

    int minCost(vector<vector<int>>& grid, int k) {
        K = k;
        m = grid.size();
        n = grid[0].size();

        t.assign(m, vector<vector<int>>(n, vector<int>(K + 1, -1)));

        return solve(0, 0, 0, grid);
    }
};



//Approach-2 (Bottom Up)
//T.C : O(m^2 * n^2 * k)
//S.C : O(m*n*k)
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e9;

        // t[i][j][tPort] = min cost from (i,j) with tPort teleports already used
        vector<vector<vector<int>>> t(
            m, vector<vector<int>>(n, vector<int>(k + 1, INF))
        );

        // Base case: destination
        for (int tPort = 0; tPort <= k; tPort++) {
            t[m - 1][n - 1][tPort] = 0;
        }

        // Fill teleport layers from back to front
        for (int tPort = k; tPort >= 0; tPort--) {
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {

                    if (i == m - 1 && j == n - 1)
                        continue;

                    int result = 1e9;

                    // Right
                    if (j + 1 < n) {
                        result = min(result,
                                     grid[i][j + 1] + t[i][j + 1][tPort]);
                    }

                    // Down
                    if (i + 1 < m) {
                        result = min(result,
                                     grid[i + 1][j] + t[i + 1][j][tPort]);
                    }

                    // Teleport
                    if (tPort < k) {
                        for (int x = 0; x < m; x++) {
                            for (int y = 0; y < n; y++) {
                                if ((x != i || y != j) && grid[x][y] <= grid[i][j]) {
                                    result = min(result, t[x][y][tPort + 1]);
                                }
                            }
                        }
                    }

                    t[i][j][tPort] = result;
                }
            }
        }

        return t[0][0][0];
    }
};



//Approach-3 (Bottom Up with Layered DP for optimization)
//T.C : O(m*n*k)
//S.C : O(m*n*k)
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[m-1][n-1] = 0;

        int maxVal = 0;
        for(auto &row : grid) {
            for(int &val : row) {
                maxVal = max(maxVal, val);
            }
        }

        vector<int> teleportCost(maxVal+1, INT_MAX);

        for(int t = 0; t <= k; t++) {

            for(int i = m-1; i >= 0; i--) {
                for(int j = n-1; j >= 0; j--) {

                    if(i+1 < m)
                        dp[i][j] = min(dp[i][j], grid[i+1][j] + dp[i+1][j]);
                    
                    if(j+1 < n)
                        dp[i][j] = min(dp[i][j], grid[i][j+1] + dp[i][j+1]);

                    if(t > 0) {
                        dp[i][j] = min(dp[i][j], teleportCost[grid[i][j]]);
                    }
                }
            }

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    teleportCost[grid[i][j]] = min(teleportCost[grid[i][j]], dp[i][j]);
                }
            }

            for(int i = 1; i < teleportCost.size(); i++) {
                teleportCost[i] = min(teleportCost[i], teleportCost[i-1]);
            }
        }

        return dp[0][0];
    }
};
```

### 1594. Maximum Non-Negative Product in a Matrix

**LeetCode:** https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/

**Problem Statement:**

Moving only right/down from top-left to bottom-right, the path's score is the **product** of all visited values (which may be negative). Return the largest non-negative product possible, modulo `1e9+7`, or -1 if no non-negative product path exists.

**Example:**

**Input:** grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
**Output:** -1
**Explanation:** It's impossible to obtain a non-negative product from any path in this grid.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=l2_da8_l1jw
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/
*/


/**************************************************************** C++ ****************************************************************/
//Approach - 1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    typedef long long ll;
    int MOD = 1e9+7;

    vector<vector<pair<ll, ll>>> t;
    
    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
        if(i == m-1 && j == n-1) {
            return {grid[i][j], grid[i][j]};
        }

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        if(t[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) {
            return t[i][j];
        }

        //Down
        if(i+1 < m) {
            auto [downMax, downMin] = solve(i+1, j, grid);
            maxVal = max({maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
            minVal = min({minVal, grid[i][j] * downMax, grid[i][j] * downMin});
        }


        //Right
        if(j+1 < n) {
            auto [rightMax, rightMin] = solve(i, j+1, grid);
            maxVal = max({maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            minVal = min({minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
        }

        return t[i][j] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        t = vector<vector<pair<ll, ll>>>(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
        auto [maxProd, minProd] = solve(0, 0, grid);

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};


//Approach - 2 (Bottom Up)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        

        //bottom up dp lena padega
        vector<vector<pair<ll, ll>>> t(m, vector<pair<ll, ll>>(n));
        //t[i][j] = {maxVal, minVal} to reach from (0, 0) to (i, j)

        t[0][0] = {grid[0][0], grid[0][0]};

        //filling the first row
        for(int j = 1; j < n; j++) {
            t[0][j].first  = t[0][j-1].first  * grid[0][j]; //maxVal
            t[0][j].second = t[0][j-1].second * grid[0][j]; //minVal
        }

        //filling the first column
        for(int i = 1; i < m; i++) {
            t[i][0].first  = t[i-1][0].first  * grid[i][0]; //max Val
            t[i][0].second = t[i-1][0].second * grid[i][0]; //min val
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                ll upMax = t[i-1][j].first;
                ll upMin = t[i-1][j].second;

                ll leftMax = t[i][j-1].first;
                ll leftMin = t[i][j-1].second;

                t[i][j].first  = max({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
                t[i][j].second = min({upMax * grid[i][j], upMin * grid[i][j], leftMax * grid[i][j], leftMin * grid[i][j]});
            }
        }

        auto [maxProd, minProd] = t[m-1][n-1];

        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};
```

---

## Pattern 4: Multiple Agents Traversing the Same Grid

Two (or three) agents move through the same grid simultaneously (row by row, or along diagonals), and the state must track the positions of **all** agents at once, taking care not to double count a shared cell.

### 1463. Cherry Pickup II

**LeetCode:** https://leetcode.com/problems/cherry-pickup-ii

**Problem Statement:**

You are given a grid of cherry counts. Two robots start at the top-left and top-right corners of row 0. Each moves down, down-left, or down-right one row at a time simultaneously. Maximize the total cherries collected by both robots by the time they reach the last row (a cell visited by both robots is only counted once).

**Example:**

**Input:** grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
**Output:** 24
**Explanation:** Robot #1 and Robot #2 pick up all cherries possible without overlapping wastefully.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Pd9wdXe8S6I
    Company Tags                : Microsoft, Amazon, Google
    Leetcode Link               : https://leetcode.com/problems/cherry-pickup-ii
*/

/*************************************************** C++ ********************************************************************/
//Approach-1 (Using Recursion + Memoization)
//T.C : O(row*col*col * 9) -> 9 is from the double for loop for colDir
//S.C : O(row * col * col)
class Solution {
public:
    int m, n;
    int t[71][71][71];
    vector<int> colDir{-1, 0, 1};
    bool isSafe(int& i) {
        return i >= 0 && i < n;
    }
    
    int solve(vector<vector<int>>& grid, int row, int c1, int c2) {
        if(row >= m)
            return 0;
        
        
        if(t[row][c1][c2] != -1) {
            return t[row][c1][c2];
        }
        
        int count = grid[row][c1];
        if(c1 != c2) {
            count += grid[row][c2];
        }
        
        
        int ans = 0;
        for(int& x : colDir) {
            for(int& y : colDir) {
                
                int c1_ = x + c1;
                int c2_ = y + c2;
                
                if(isSafe(c1_) && isSafe(c2_)) {
                    ans = max(ans, solve(grid, row+1, c1_, c2_));
                }
            }
        }
        
        return t[row][c1][c2] = count+ans;  
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));
        return solve(grid, 0, 0, n-1);
    }
};

//Approach-2 (Bottom Up - 3D Array)
//T.C : O(row*col*col * 9)
//S.C : O(row * col * col)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int t[71][71][71] = {0};
        
        //t[row][c1][c2] =  max cherries that can be collected till (row, c1) by robot1 and (row, c2) by robot2
        //return max in last row 
        
        //For first row (robot1 is in 0th column) and robot2 is in (n-1)th column
        t[0][0][n - 1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n - 1]; 
        
        for (int row = 1; row < m; row++) {
            for (int c1 = 0; c1 <= min(n-1, row); c1++) {      //min(n-1, row)   - Explained in video
                for (int c2 = max(0, n-1-row); c2 < n; c2++) { //max(0, n-1-row) - Explained in video
                    
                    int prev_max = 0;
                    //A Robot can come to current column from either column-1, column, or column+1 of prev row (row-1)
                    for (int column1 = max(0, c1 - 1); column1 <= min(n - 1, c1 + 1); column1++) {
                        for (int column2 = max(0, c2 - 1); column2 <= min(n - 1, c2 + 1); column2++) {
                                prev_max = max(prev_max, t[row - 1][column1][column2]);
                        }
                    }
                    
                    if (c1 == c2)
                        t[row][c1][c2] = prev_max + grid[row][c1];
                    else
                        t[row][c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
                }
            }
        }
        
        int res = 0;
        //return max in last row 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, t[m - 1][i][j]);    
            }
        }
        return res;
    }
};


//Approach-3 (Bottom Up - 2D Array) We only need previous row
//T.C : O(row*col*col * 9)
//S.C : O(col * col)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> prev(n, vector<int>(n));
        prev[0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1];
        
        for (int row = 1; row < m; row++) {

            vector<vector<int>> curr(n, vector<int>(n));

            for (int c1 = 0; c1 <= min(n-1, row); c1++) {      //min(n-1, row)   - Explained in video
                for (int c2 = max(0, n-1-row); c2 < n; c2++) { //max(0, n-1-row) - Explained in video
                    
                    int prev_max = 0;
                    //A Robot can come to current column from either column-1, column, or column+1 of prev row (row-1)
                    for (int column1 = max(0, c1 - 1); column1 <= min(n - 1, c1 + 1); column1++) {
                        for (int column2 = max(0, c2 - 1); column2 <= min(n - 1, c2 + 1); column2++) {
                                prev_max = max(prev_max, prev[column1][column2]);
                        }
                    }
                    
                    if (c1 == c2)
                        curr[c1][c2] = prev_max + grid[row][c1];
                    else
                        curr[c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
                }
            }
            prev = curr;
        }
        
        int res = 0;
        //return max in last row 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, prev[i][j]);    
            }
        }
        return res;
    }
};
```

### 3272. Find the Maximum Number of Fruits Collected

**LeetCode:** https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected

**Problem Statement:**

Three children start at the three corners of an `n x n` grid (top-left, top-right, bottom-left) and must all reach the bottom-right corner. Child 1 only moves diagonally; children 2 and 3 move toward the opposite corner via cells adjacent to the main diagonal. Maximize the total fruits collected by all three, counting shared cells once.

**Example:**

**Input:** fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]
**Output:** 100
**Explanation:** All three children coordinate their diagonal-hugging paths to maximize the collected total.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*                   Scroll below to see JAVA code as well                */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=K9-ZV-_UJ0Q
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected
*/

/************************************************************ C++ ************************************************************/
//Approach-1 - (Recursion + Memoization)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
    int n;
    vector<vector<int>> t;

public:

    //Can only move diagonally
    int child1Collect(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += grid[i][i];
            grid[i][i] = 0;
            t[i][i] = 0;
        }
        return ans;
    }

    int child2Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }
        
        //can't go beyond diagonal or left to diagonal (only have n-1 moves)
        if (i == j || i > j) {
            return 0;
        }

        if (t[i][j] != -1)
            return t[i][j];

        int leftcorner = grid[i][j] + child2Collect(i + 1, j - 1, grid);
        int middle = grid[i][j] + child2Collect(i + 1, j, grid);
        int rightcorner = grid[i][j] + child2Collect(i + 1, j + 1, grid);

        return t[i][j] = max({middle, rightcorner, leftcorner});
    }

    int child3Collect(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (i == n - 1 && j == n - 1) {
            return 0;
        }

        //can't go beyond diagonal or right to diagonal (only have n-1 moves)
        if (i == j || j > i) {
            return 0;
        }
        if (t[i][j] != -1)
            return t[i][j];

        int topcorner   = grid[i][j] + child3Collect(i - 1, j + 1, grid);
        int right       = grid[i][j] + child3Collect(i, j + 1, grid);
        int rightcorner = grid[i][j] + child3Collect(i + 1, j + 1, grid);

        return t[i][j] = max({right, rightcorner, topcorner});
    }

    int maxCollectedFruits(vector<vector<int>>& grid) {
        n = grid.size();
        t.resize(n, vector<int>(n, -1));

        // First child
        int firstChildScore = child1Collect(grid);

        // Second child
        int secondChildScore = child2Collect(0, n - 1, grid);

        // Third child
        int thirdChildScore  = child3Collect(n - 1, 0, grid);

        return (firstChildScore + secondChildScore + thirdChildScore);
    }    
};


//Approach-2 - (Bottom Up)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> t(n, vector<int>(n, 0));
        //t[i][j] = max fruits collected till [i][j]

        //child1Collect - Diagonal elements
        int result = 0;
        for(int i = 0; i < n; i++) {
            result += fruits[i][i];
        }


        //Before child2 and child3, nullify the cells which can't be visited by child2 and child3
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i < j && i+j < n-1) {
                    t[i][j] = 0;
                } else if(i > j && i+j < n-1) {
                    t[i][j] = 0;
                } else {
                    t[i][j] = fruits[i][j];
                }
            }
        }


        //child2 collect fruits
        //cells upper to diagonal : i < j
        for(int i = 1; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                t[i][j] += max({t[i-1][j-1], t[i-1][j], (j+1 < n) ? t[i-1][j+1] : 0});
            }
        }

        //child3 collect fruits
        //cells upper to diagonal : i > j
        for(int j = 1; j < n; j++) {
            for(int i = j+1; i < n; i++) {
                t[i][j] += max({t[i-1][j-1], t[i][j-1], (i+1 < n) ? t[i+1][j-1] : 0});
            }
        }

        return result + t[n-2][n-1] + t[n-1][n-2];

    }
};
```

---

## Pattern 5: Diagonal Traversal & Square Sub-structures

These problems require reasoning along **diagonals** of the grid — either finding the longest structure formed while moving diagonally, or counting square sub-matrices, which itself is computed using a DP recurrence that looks diagonally at neighboring cells.

### 3459. Length of Longest V-Shaped Diagonal Segment

**LeetCode:** https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment

**Problem Statement:**

Starting on a cell containing `1`, move diagonally through a strictly alternating sequence of `2`s and `0`s. You are allowed **one clockwise 90° turn** during the whole segment. Return the length of the longest such V-shaped diagonal segment found anywhere in the grid.

**Example:**

**Input:** grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
**Output:** 5
**Explanation:** The longest V-shaped diagonal segment (including one turn) has length 5.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tIEUAD4tWcw
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Traverse and explore all possible paths + memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:

    vector<vector<int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int m, n;
    int t[501][501][4][2];

    int solve(int i, int j, int d, bool canTurn, int val, vector<vector<int>>& grid) {
        int i_ = i + directions[d][0];
        int j_ = j + directions[d][1];

        if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] != val) {
            return 0;
        }

        if(t[i_][j_][d][canTurn] != -1) {
            return t[i_][j_][d][canTurn];
        }

        int result = 0;
        int keepMoving = 1 + solve(i_, j_, d, canTurn, val == 2 ? 0 : 2, grid);
        result = max(result, keepMoving);

        if(canTurn == true) {
            int turnAndMove = max(keepMoving, 1 + solve(i_, j_, (d+1)%4, false, val == 2 ? 0 : 2, grid));
            result = max(result, turnAndMove);
        }

        return t[i_][j_][d][canTurn] = result;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));

        int result = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    for(int d = 0; d <= 3; d++) {
                        result = max(result, 1 + solve(i, j, d, true, 2, grid));
                    }
                }
            }
        }

        return result;

    }
};
```

### 1277. Count Square Submatrices with All Ones

**LeetCode:** https://leetcode.com/problems/count-square-submatrices-with-all-ones

**Problem Statement:**

Given an `m x n` binary matrix, count the number of square sub-matrices that contain only `1`s. This uses the same 'largest square ending here' DP as Maximal Square (LC 221), summed over every cell.

**Example:**

**Input:** matrix = [[0,1,1,1],[1,1,1,1],[0,1,1,1]]
**Output:** 15
**Explanation:** There are 10 squares of side 1, 4 squares of side 2, and 1 square of side 3, totalling 15.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=y3kdowdyNMM
    Company Tags                : Flipkart
    Leetcode Link               : https://leetcode.com/problems/count-square-submatrices-with-all-ones
*/


/**************************************************************** C++ ****************************************************************/
//Approach - 1 (simple Recursion Memoization) - Same as Maximal Square (Leetcode-221)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& t) {
        
        if (i >= grid.size() || j >= grid[0].size()) 
            return 0;

        if (grid[i][j] == 0)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        // Right
        int right = solve(i, j + 1, grid, t);
        // Diagonal
        int diagonal = solve(i + 1, j + 1, grid, t);
        // Below
        int below = solve(i + 1, j, grid, t);

        return t[i][j] = 1 + min({right, diagonal, below});
    }

    int countSquares(vector<vector<int>>& grid) {
        int result = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n, -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                result += solve(i, j, grid, t);
            }
        }
        return result;
    }
};


//Approach - 2 (simple Bottom Up - Same as Maximal Square (Leetcode-221)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> t(m, vector<int>(n, 0));
        int result = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = matrix[i][j];
                } else {
                    if(matrix[i][j] == 1) {
                        // Because, if you have any 0, then you cannot expand side of square
                        t[i][j] = 1 + min({t[i-1][j], t[i][j-1], t[i-1][j-1]});
                    }
                }
                result += t[i][j];
            }
        }
        
        return result;
    }
};
```

---

## Pattern 6: Ordered / Directional Path Counting (DFS + Memo)

The grid has no fixed movement direction (all 4 or 8 directions are allowed), but a monotonic property (increasing values, or a move counter) prevents cycles, letting us safely memoize a DFS over grid cells.

### 2328. Number of Increasing Paths in a Grid

**LeetCode:** https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

**Problem Statement:**

From every cell in the grid, you may move to any of the 4 adjacent cells whose value is strictly greater than the current cell's value. Count the total number of increasing paths in the grid, modulo `1e9+7` (this is the grid analogue of Longest Increasing Path in a Matrix, LC 329).

**Example:**

**Input:** grid = [[1,1],[3,4]]
**Output:** 8
**Explanation:** The increasing paths are: (0,0), (0,1), (1,0), (1,1), (0,0)->(1,0), (0,0)->(1,1), (0,1)->(1,1), (1,0)->(1,1).

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=s-dQjzykhVA
    Company Tags                : Microsoft, Adobe
    Leetcode Link               : https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
*/

/*
    NOTE : This problem is similar to Leetcode-329.
           Leetcode-329 is a famous interview problem so this is kind of standard problem.
           That's why I always say, don't be afraid of new Hard Problems,these qns are standard and many other problems can
           be solved using the concept based on these problems.
*/

//-------In future, I will move this qn to a separate folder "2D-DP"

//Approach-1 (Using simple DFS) - TLE
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };
    
    bool isSafe(int i, int j) {
        return (i < m && i >= 0 && j < n && j >= 0);
    }
    
    long long MOD = 1e9+7;
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        
        int answer = 1;
        
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(isSafe(i_, j_) && grid[i_][j_] < grid[i][j]) {
                answer = (answer + dfs(grid, i_, j_)) % MOD;
            }
        }
        
        return answer;
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        
        int result = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                result = (result + dfs(grid, i, j)) % MOD;
                
            }
        }
        
        
        return result;
    }
};

//Approach-2 (Building increasing path from small to lareg value)
//Simply change the check from "grid[i_][j_] < grid[i][j]" to "grid[i_][j_] > grid[i][j]"


//Approach-3 (By Memoization of Approach-1&2 above) - Accepted -O(m*n)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };
    
    int t[1001][1001];
    
    bool isSafe(int i, int j) {
        return (i < m && i >= 0 && j < n && j >= 0);
    }
    
    long long MOD = 1e9+7;
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        
        if(t[i][j] != -1)
            return t[i][j];
        
        int answer = 1;
        
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(isSafe(i_, j_) && grid[i_][j_] < grid[i][j]) {
                answer = (answer + dfs(grid, i_, j_)) % MOD;
            }
        }
        
        return t[i][j] = answer;
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        memset(t, -1, sizeof(t));
        
        int result = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                result = (result + dfs(grid, i, j)) % MOD;
                
            }
        }
        
        
        return result;
    }
};


//Approach-4 (Using Dynamic Programming)
//Coming Soon
```

### 688. Knight Probability in Chessboard

**LeetCode:** https://leetcode.com/problems/knight-probability-in-chessboard/

**Problem Statement:**

A knight starts on cell `(row, column)` of an `n x n` chessboard and makes exactly `k` moves, choosing uniformly at random among the 8 knight moves each time (even if that would move it off the board, in which case it stops moving). Return the probability that the knight remains on the board after `k` moves.

**Example:**

**Input:** n = 3, k = 2, row = 0, column = 0
**Output:** 0.0625
**Explanation:** There is a 6.25% chance the knight stays on the board after 2 random moves from a corner.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ETA-5CD0z7Q
    Company Tags                : Amazon, Directi
    Leetcode Link               : https://leetcode.com/problems/knight-probability-in-chessboard/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/probability-of-knight5529/1
*/

//Using simple recursion and memoization (T.C : We visit each state once only and we have k possible tries - O(k * n^2)
class Solution {
public:
    unordered_map<string, double> mp;
    vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    double helper( int N, int K , int row, int col ) {
        
        if ( row < 0 || row >= N || col < 0 || col >= N ) 
            return 0; 
        
        if (K==0)
            return 1;  //one possibility over, return now
        
        string key = to_string(K) + "_" + to_string(row) + "_" + to_string(col);
        
        if(mp.find(key) != mp.end()) 
            return mp[key];
        
        double ans = 0;
        for(auto &dir : directions) {
            int new_row = row + dir.first;
            int new_col = col + dir.second;
            ans += (double)helper(N, K-1, new_row, new_col);
        }
        
        return mp[key] = (double)(ans/8.0); 
    }
    
    
    double knightProbability(int n, int k, int row, int column) {
        return helper( n , k , row , column); 
    }
};


//Approach-2 (Bottom UP) - SOOON
```

---

## Pattern 7: Grid/Row Coloring & Combinatorics DP

The 'grid' here is really a sequence of rows, and the DP state is the **coloring pattern** of the previous row, transitioning to all compatible patterns for the current row.

### 1411. Number of Ways to Paint N x 3 Grid

**LeetCode:** https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid

**Problem Statement:**

You have an `n x 3` grid and 3 colors (Red, Yellow, Green). Paint every cell so that no two adjacent cells (horizontally or vertically) share the same color. Return the number of ways to paint the grid, modulo `1e9+7`.

**Example:**

**Input:** n = 1
**Output:** 12
**Explanation:** There are 12 possible ways to paint a single row of 3 cells with no two adjacent cells sharing a color.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=WXdLIuRhiRg
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid
*/

//If you want, I can make a separate video on Bottom Up. Let me know in the comments



/**************************************************************** C++ ****************************************************************/
//Approach (Recursion + Memoization : DP On Grids) - If you want, I can make a separate video on Bottom Up. Let me know in the comments
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>> t;

    //12 possible first rows
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};

    int solve(int n, int prev) {
        if(n == 0)
            return 1;
        
        if(t[n][prev] != -1)
            return t[n][prev];

        int result = 0;
        string last = states[prev];

        for(int curr = 0; curr < 12; curr++) {
            if(curr == prev)
                continue;
            
            string currPat = states[curr];
            bool conflict = false;
            for(int col = 0; col < 3; col++) {
                if(currPat[col] == last[col]) {
                    conflict = true;
                    break;
                }
            }

            if(!conflict) {
                result = (result + solve(n-1, curr)) % M;
            }
        }

        return t[n][prev] = result;
    }

    int numOfWays(int n) {
        t.resize(n, vector<int>(12, -1)); //T.C : O(n)
        int result = 0;

        for(int i = 0; i < 12; i++) { //chossing 1st row
            //now remaining n-1 rows painting
            result = (result + solve(n-1, i)) % M;
        }

        return result;
    }
};
```

---

## Pattern 8: Column/Interval DP with Greedy Structure

Harder grid problems where the DP state is defined per column/robot along with a running direction or height, often combined with prefix sums or binary search to evaluate transitions efficiently.

### Maximum Walls Destroyed by Robots

**LeetCode:** https://leetcode.com/problems/maximum-walls-destroyed-by-robots/description/

**Problem Statement:**

Robots are placed on a number line, and each robot can fire a bullet either left or right that destroys all walls within its given range. Robots fired to the right stop other robots' left-shots from reaching walls behind them (and vice versa). Choose a firing direction for every robot to maximize the total number of walls destroyed.

**Example:**

**Input:** robots = [4,2,1], distance = [4,2,1], walls = [1,2,3,4]
**Output:** 4
**Explanation:** All walls can be destroyed with an optimal choice of firing directions for each robot.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=niOPy-UHahQ
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-walls-destroyed-by-robots/description/
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Recursion + Memoization + Binary Search)
//T.C : O(n * log(w) + nlogn + wlogw), n = robots.size(), w = walls.size()
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> t;

    int countWalls(vector<int>& walls, int l, int r) {
        int left  = lower_bound(begin(walls), end(walls), l) - begin(walls);
        int right = upper_bound(begin(walls), end(walls), r) - begin(walls);

        return right - left;

    }

    int solve(vector<int>& walls, vector<P>& roboDist, vector<P>& range, int i, int prevDir) {

        if(i == roboDist.size())
            return 0;
        
        if(t[i][prevDir] != -1)
            return t[i][prevDir];

        int leftStart = range[i].first;

        if(prevDir == 1) { //prev robot fired bullet rtowards right
            leftStart = max(leftStart, range[i-1].second + 1);
        }

        int leftTake = countWalls(walls, leftStart, roboDist[i].first) 
                        + solve(walls, roboDist, range, i+1, 0);
                    
        int rightTake = countWalls(walls, roboDist[i].first, range[i].second) 
                        + solve(walls, roboDist, range, i+1, 1);

        
        return t[i][prevDir] = max(leftTake, rightTake);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<P> roboDist(n);
        for (int i = 0; i < n; i++) {
            roboDist[i] = {robots[i], distance[i]};
        }

        sort(begin(roboDist), end(roboDist));
        sort(begin(walls), end(walls));

        //Prepare range vector for each robot
        vector<P> range(n);

        for(int i = 0; i < n; i++) {
            int pos = roboDist[i].first;
            int d   = roboDist[i].second;

            int leftLimit  = (i == 0)   ? 1   : roboDist[i-1].first+1;
            int rightLimit = (i == n-1) ? 1e9 : roboDist[i+1].first-1;

            int L = max(pos - d, leftLimit);
            int R = min(pos + d, rightLimit);

            range[i] = {L, R};
        }

        t.assign(n+1, vector<int>(2, -1));

        //prev = 0/1 (previious robot hit buttlet to left/right)
        return solve(walls, roboDist, range, 0, 0);
    }
};
```

### Maximum Score From Grid Operations

**LeetCode:** https://leetcode.com/problems/maximum-score-from-grid-operations

**Problem Statement:**

Given an `n x n` binary grid, you may repeatedly turn any cell black by drawing an L-shaped mark spanning a column up to some height, provided at least one neighboring column already has an equal-or-taller black region. Each cell you turn black scores its grid value if it has a black neighbor to the left or right. Maximize the total score across all columns.

**Example:**

**Input:** grid = [[0,0,0,0,0,0],[0,0,0,0,0,0],[0,0,1,0,0,0],[0,1,1,1,0,0],[0,0,1,0,0,0],[0,0,0,0,0,0]]
**Output:** 3
**Explanation:** Marking adjacent columns strategically maximizes the number of scoring black cells.

**C++ Solution:**

```cpp
#include <bits/stdc++.h>

using namespace std;

/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=f81qWxDkj0Q
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-score-from-grid-operations
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Brute Force) - TLE
//T.C : O((n+1)^n * n^2))
//S.C : O(n)
class Solution {
public:
    long long computeScore(vector<int>& h, vector<vector<int>>& grid, int n) {
        long long score = 0;

        for (int j = 0; j < n; j++) {
            for (int i = h[j] + 1; i < n; i++) {

                bool hasBlackNeighbor = false;

                if (j - 1 >= 0 && i <= h[j - 1])
                    hasBlackNeighbor = true;

                if (j + 1 < n && i <= h[j + 1])
                    hasBlackNeighbor = true;

                if (hasBlackNeighbor)
                    score += grid[i][j];
            }
        }

        return score;
    }

    void solve(int col, vector<int>& h, vector<vector<int>>& grid, int n, long long& result) {
        if (col == n) {
            result = max(result, computeScore(h, grid, n));
            return;
        }

        // allow -1 (no operation)
        for (int height = -1; height < n; height++) {
            h[col] = height;
            solve(col + 1, h, grid, n, result);
        }
    }

    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> h(n);
        long long result = 0;

        solve(0, h, grid, n, result);

        return result;
    }
};




//Approach-2 (Brute Force with improved computeScore)
//T.C : O((n+1)^n * n))
//S.C : O(n^2)
class Solution {
public:
    using ll = long long;

    ll computeScore(vector<int>& h, vector<vector<ll>>& colPrefSum, int n) {
        ll score = 0;

        for (int col = 0; col < n; col++) {

            int left = (col - 1 >= 0 ? h[col - 1] : -1);
            int right = (col + 1 < n ? h[col + 1] : -1);

            int upper = max(left, right); // highest black neighbor
            int lower = h[col];           // current column height

            if (upper > lower) {
                score += colPrefSum[upper + 1][col + 1]
                       - colPrefSum[lower + 1][col + 1];
            }
        }

        return score;
    }

    void solve(int col, vector<int>& h, vector<vector<ll>>& colPrefSum,
               int n, ll& result) {

        if (col == n) {
            result = max(result, computeScore(h, colPrefSum, n));
            return;
        }

        for (int height = -1; height < n; height++) {
            h[col] = height;
            solve(col + 1, h, colPrefSum, n, result);
        }
    }

    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
      
        vector<vector<ll>> colPrefSum(n + 1, vector<ll>(n + 1, 0));

        for (int col = 1; col <= n; col++) {
            for (int row = 1; row <= n; row++) {
                colPrefSum[row][col] =
                    colPrefSum[row - 1][col] + grid[row - 1][col-1];
            }
        }

        vector<int> h(n);
        ll result = 0;

        solve(0, h, colPrefSum, n, result);

        return result;
    }
};



//Approach-3 (Most optimal)
//T.C : O(n^3)
//S.C : O(n^2)
class Solution {
public:
    typedef long long ll;
    int n;
    ll t[2][101][101];

    ll solve(bool prevTaken, int prevHeight, int col, vector<vector<int>>& grid, vector<vector<ll>>& colPrefSum) {
        
        if(col == n) {
            return 0;
        }
        
        ll result = 0;

        if(t[prevTaken][prevHeight][col] != -1) {
            return t[prevTaken][prevHeight][col];
        } 

        for(int height = 0; height <= n; height++) {
            ll prevColScore = 0;
            ll currColScore = 0;

            if(!prevTaken && col-1 >= 0 && height > prevHeight) {
                prevColScore += colPrefSum[height][col] - colPrefSum[prevHeight][col];
            }

            if(prevHeight > height) {
                currColScore += colPrefSum[prevHeight][col+1] - colPrefSum[height][col+1];
            }


            ll currColScoreTaken    = currColScore + prevColScore + solve(true, height, col+1, grid, colPrefSum);
            ll currColScoreNotTaken = prevColScore + solve(false, height, col+1, grid, colPrefSum);

            result = max({result, currColScoreTaken, currColScoreNotTaken});
        }

        return t[prevTaken][prevHeight][col] = result;

    }

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        memset(t, -1, sizeof(t));


        vector<vector<ll>> colPrefSum(n + 1, vector<ll>(n + 1, 0));

        for(int col = 1; col <= n; col++) {
            for(int row = 1; row <= n; row++) {
                colPrefSum[row][col] = colPrefSum[row-1][col] + grid[row-1][col-1];
            }
        }

        return solve(false, 0, 0, grid, colPrefSum);
    }
};
```
