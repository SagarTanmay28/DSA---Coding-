
You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

 

Example 1:



Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.
Example 2:



Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
 

Constraints:

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] is 0 or 1.
There is at least one water cell.


class Solution {
public:
    int n;
    int m;

    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        n = isWater.size();
        m = isWater[0].size();

        vector<vector<int>> vis(n,vector<int>(m,-1));

        // Multi - Source BFS 
        queue< pair<int,int> > q;

        // push all 0's
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(isWater[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 0;
                }
            }
        }


        while(q.size()){

            int sz = q.size();

            while(sz--){

                auto p = q.front();
                q.pop();

                int i = p.first;
                int j = p.second;

                for(auto dir : directions){

                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if((new_i >= 0 && new_i < n) && (new_j >= 0 && new_j < m) && vis[new_i][new_j] == -1){
                        
                        vis[new_i][new_j] = 1 + vis[i][j];
                        q.push({new_i,new_j});

                    }
                }
            }
        }

        return vis;


    }
};
