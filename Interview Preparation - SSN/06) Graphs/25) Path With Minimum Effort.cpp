You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.


class Solution {
public:
    typedef pair< int, pair<int,int> > pi;
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        ans[0][0] = 0;

        priority_queue<pi,vector<pi>,greater<pi>> pq; // min heap 
        // pi -> {dist,{row,col}};
        pq.push({0,{0,0}});

        while(pq.size()){

            auto p = pq.top();
            pq.pop();

            int row = p.second.first;
            int col = p.second.second;
            int dist = p.first;

            for(auto dir : directions){

                int i = row + dir[0];
                int j = col + dir[1];

                if((i >= 0 && i < n) && (j >= 0 && j < m)){

                    int val = heights[row][col];
                    int curr_val = heights[i][j];

                    int effort = abs(val - curr_val);
                    effort = max(effort,dist);

                    if(ans[i][j] > effort){
                        ans[i][j] = effort;
                        pq.push({effort,{i,j}});
                    }
                }
            }
        }

        return ans[n-1][m-1];


    }
};
