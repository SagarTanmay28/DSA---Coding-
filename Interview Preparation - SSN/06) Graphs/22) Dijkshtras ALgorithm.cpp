#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});      // {distance, node}

    while (!pq.empty()) {

        auto [dis, node] = pq.top();
        pq.pop();

        // Skip outdated entries
        if (dis > dist[node]) continue;

        for (auto &[adjNode, wt] : adj[node]) {

            if (dist[node] + wt < dist[adjNode]) {

                dist[adjNode] = dist[node] + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}
