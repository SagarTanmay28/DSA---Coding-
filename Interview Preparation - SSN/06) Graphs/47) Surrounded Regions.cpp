You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]



class Solution {
public:
    
    vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;

        // First & Last Column
        for (int i = 0; i < m; i++) {

            if (board[i][0] == 'O') {
                board[i][0] = '#';
                q.push({i, 0});
            }

            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = '#';
                q.push({i, n - 1});
            }
        }

        // First & Last Row
        for (int j = 0; j < n; j++) {

            if (board[0][j] == 'O') {
                board[0][j] = '#';
                q.push({0, j});
            }

            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = '#';
                q.push({m - 1, j});
            }
        }


        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dir) {

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    board[nx][ny] == 'O') {

                    board[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }

        // Convert board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
