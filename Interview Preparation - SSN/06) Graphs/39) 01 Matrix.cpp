Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.


class Solution {
public:
    int n;
    int m;

    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& isWater) {
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
