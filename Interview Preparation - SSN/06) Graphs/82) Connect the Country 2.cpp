Problem Statement

There are n cities in a country. Each city has an associated construction cost given in an array cost.

The cost to build a bidirectional road between two cities i and j is the sum of their respective costs:

cost[i] + cost[j]

Additionally, there are m special road offers. Each offer is represented by a triplet:

[i, j, k]

meaning that a bidirectional road can be built between cities i and j for a cost of k.

For every offered road, you can either:

use the special offer and pay k, or
build the road at its normal cost cost[i] + cost[j].

Your task is to determine the minimum total cost required to connect all n cities, such that there is a path between every pair of cities.

Return the minimum cost.

Input Format
The first line contains an integer n, the number of cities.
The next n lines each contain one integer cost[i].
The next line contains an integer m, the number of offers.
The next line contains an integer p (always 3).
The next m lines each contain three integers:
offer[i][0] offer[i][1] offer[i][2]

where:

offer[i][0] = city 1
offer[i][1] = city 2
offer[i][2] = offered road cost

Cities are numbered from 1 to n.

Output Format

Return an integer representing the minimum cost required to connect all cities.

Test Case 1

Equivalent representation
n = 5
cost = [3, 1, 2, 3, 1]

m = 2
p = 3

offers = [
    [3, 4, 1],
    [1, 5, 5]
]
Output
10
Explanation

The optimal roads are:

3 -- 4 : 1    (special offer)
2 -- 5 : 2    (normal cost = 1 + 1)
2 -- 3 : 3    (normal cost = 1 + 2)
1 -- 5 : 4    (normal cost = 3 + 1)

Total:

1 + 2 + 3 + 4 = 10

So the answer is:

10



#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v)
            return false;

        if (rank[u] < rank[v])
            swap(u, v);

        parent[v] = u;

        if (rank[u] == rank[v])
            rank[u]++;

        return true;
    }
};

class Solution {
public:
    long long minimumCost(vector<int>& cost, vector<vector<int>>& offers) {

        int n = cost.size();

        // min heap: {edgeCost, u, v}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        // 1. Add all normal roads
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {

                long long roadCost = cost[i - 1] + cost[j - 1];

                pq.push({roadCost, i, j});
            }
        }

        // 2. Add all offered roads
        for (auto &offer : offers) {

            int u = offer[0];
            int v = offer[1];
            long long c = offer[2];

            pq.push({c, u, v});
        }

        // 3. Kruskal + DSU
        DSU dsu(n);

        long long ans = 0;
        int edgesUsed = 0;

        while (!pq.empty() && edgesUsed < n - 1) {

            auto [c, u, v] = pq.top();
            pq.pop();

            // IMPORTANT: compare roots
            if (dsu.find(u) != dsu.find(v)) {

                dsu.unite(u, v);

                ans += c;
                edgesUsed++;
            }
        }

        return ans;
    }
};
