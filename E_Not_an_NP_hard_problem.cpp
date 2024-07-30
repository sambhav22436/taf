#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>
#define int long long int
using namespace std;
#define fori(a, b) for(int i=a; i<b; i++)
#define forj(a, b) for(int j=a; j<b; j++)
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<int>::iterator vit;
typedef set<int> si;
typedef map<int, int> mii;
#include <map>
#include <queue>
#define INF 1e18
#define pb push_back
#define F first
#define S second
 





vector<int> dijkstra(const vector<vector<pair<int, int>>>& g, int n, int src) {
    vector<int> dist(n, INF);
    set<pair<int, int>> pq;
    
    dist[src] = 0;
    pq.insert({0, src});
    
    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        
        for (const auto& e : g[u]) {
            int v = e.F, w = e.S;
            if (dist[u] + w < dist[v]) {
                pq.erase({dist[v], v}); // Remove old distance
                dist[v] = dist[u] + w;  // Update distance
                pq.insert({dist[v], v}); // Insert updated distance
            }
        }
    }
    
    return dist;
}

int findOptimalWeight(const vector<vector<pair<int, int>>>& g, int n) {
    vector<int> sp = dijkstra(g, n, 0);
    int totalWeight = 0;
    
    for (int i = 1; i < n; ++i) {
        int minWeight = INF;
        for (const auto& e : g[i]) {
            int u = e.F, w = e.S;
            if (sp[i] == sp[u] + w) {
                minWeight = min(minWeight, w);
            }
        }
        totalWeight += minWeight;
    }
    
    return totalWeight;
}

int32_t main() {
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int s, e, x;
        cin >> s >> e >> x;
        g[s].pb({e, x});
        g[e].pb({s, x});
    }
    cout << findOptimalWeight(g, n);
    return 0;
}
