There is a country of n cities numbered from 0 to n - 1 where all the cities are connected by bi-directional roads. The roads are represented as a 2D integer array edges where edges[i] = [xi, yi, timei] denotes a road between cities xi and yi that takes timei minutes to travel. There may be multiple roads of differing travel times connecting the same two cities, but no road connects a city to itself.

Each time you pass through a city, you must pay a passing fee. This is represented as a 0-indexed integer array passingFees of length n where passingFees[j] is the amount of dollars you must pay when you pass through city j.

In the beginning, you are at city 0 and want to reach city n - 1 in maxTime minutes or less. The cost of your journey is the summation of passing fees for each city that you passed through at some moment of your journey (including the source and destination cities).

Given maxTime, edges, and passingFees, return the minimum cost to complete your journey, or -1 if you cannot complete it within maxTime minutes.

 

Example 1:



Input: maxTime = 30, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
Output: 11
Explanation: The path to take is 0 -> 1 -> 2 -> 5, which takes 30 minutes and has $11 worth of passing fees.
Example 2:



Input: maxTime = 29, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
Output: 48
Explanation: The path to take is 0 -> 3 -> 4 -> 5, which takes 26 minutes and has $48 worth of passing fees.
You cannot take path 0 -> 1 -> 2 -> 5 since it would take too long.
Example 3:

Input: maxTime = 25, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
Output: -1
Explanation: There is no way to reach city 5 from city 0 within 25 minutes.

class Solution {
public:
    typedef pair<int, pair<int, int>> pi;
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int t = e[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        // dist[node][time] = minimum cost to reach node
        // using exactly 'time' minutes
        vector<vector<int>> dist(n, vector<int>(maxTime + 1, INT_MAX));

        priority_queue<pi, vector<pi>, greater<pi>> pq;

        // Start at city 0, time = 0
        dist[0][0] = passingFees[0];

        pq.push({passingFees[0], {0, 0}});

        while(!pq.empty()) {

            auto [cost, state] = pq.top();
            pq.pop();

            int node = state.first;
            int time = state.second;

            // Ignore outdated state
            if(cost != dist[node][time])
                continue;

            // We reached destination
            if(node == n - 1)
                return cost;

            for(auto &[next, travelTime] : adj[node]) {

                int newTime = time + travelTime;

                if(newTime > maxTime)
                    continue;

                int newCost = cost + passingFees[next];

                if(newCost < dist[next][newTime]) {

                    dist[next][newTime] = newCost;

                    pq.push({
                        newCost,
                        {next, newTime}
                    });
                }
            }
        }

        return -1;
    }
};
