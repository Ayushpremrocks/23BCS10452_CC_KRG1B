#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto &adjNode : adj[node]){
                int next = adjNode.first;
                int price = adjNode.second;

                if(cost + price < dist[next] && stops <= k){
                    dist[next] = cost + price;
                    q.push({stops + 1, {next, dist[next]}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};