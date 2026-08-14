On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.

  class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i){
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) return;

        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y] += 1;
        }
    }


    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        parent.resize(n,0);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(int i=0;i<n;i++){

            int r = stones[i][0];
            int c = stones[i][1];

            for(int j=i+1;j<n;j++){

                int r_ = stones[j][0];
                int c_ = stones[j][1];

                if(r == r_ || c == c_){
                    Union(i,j);
                }
            
            }
        }

        unordered_set<int> st;
        for(int x : parent) st.insert(find(x));

        int components = st.size();

        return n - components;


    }
};
