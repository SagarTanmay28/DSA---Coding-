Given a group of N people, each having a unique ID value from 0 to (N - 1) and an array arr[] of M elements of the form {U, V, time} representing that the person U will become acquainted with person V at the given time. Let’s say that person U is acquainted with person V if U is friends with V, or U is a friend of someone acquainted with V. The task is to find the earliest time at which every person became acquainted with each other.

Examples:



Input: N = 4, arr[] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}}
Output: 4
Explanation: Initially, the number of people are 4, i.e, {0}, {1}, {2}, {3}. 



At time = 2, {0} and {1} became friends. Therefore, the group of acquainted people becomes {0, 1}, {2}, {3}.
At time = 3, {1} and {2} became friends. Therefore, the group of acquainted people becomes {0, 1, 2}, {3}.
At time = 4, {2} and {3} became friends. Therefore, the group of acquainted people becomes {0, 1, 2, 3}.


Hence, at time = 4, every person became acquainted with each other.





Input: N = 6, arr[] = {{0, 1, 4}, {3, 4, 5}, {2, 3, 14}, {1, 5, 24}, {2, 4, 12}, {0, 3, 42}, {1, 2, 41}, {4, 5, 11}}
Output: 24



Approach: The given problem can be solved using the Disjoint Set Union Data Structure. The idea is to perform the union operations between people in order of the increasing value of time. The required answer will be the time when all people belong to the same set. Follow the steps below to solve the given problem:

Implement the Disjoint Set Union Data Structure with the union and findSet functions according to the algorithm discussed here.
Initialize a variable time, which stores the value of the current timestamp of the DSU.
Sort the given array arr[] in increasing order of time.
Traverse the given array arr[] using variable i, and perform union operation between (Ui, Vi) and update the current timestamp to timei if Ui and Vi belong to the different sets.
If the total number of sets after completely traversing through the array arr[] is 1, return the value of the variable time, else return -1.


class Solution {
public:
    vector<int> parent, Rank;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

        if (Rank[px] < Rank[py])
            swap(px, py);

        parent[py] = px;

        if (Rank[px] == Rank[py])
            Rank[px]++;

        return true;
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {

        sort(logs.begin(), logs.end());

        parent.resize(n);
        Rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int components = n;

        for (auto &log : logs) {

            int time = log[0];
            int x = log[1];
            int y = log[2];

            if (Union(x, y))
                components--;

            if (components == 1)
                return time;
        }

        return -1;
    }
};
