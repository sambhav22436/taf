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
 






int dfs(int node, const vector<vector<int>> &adj, vector<bool> &visited) {
    int k=1;
    visited[node] = true;


    for(auto &v:adj[node]){

            if (!visited[v]) {
                k+=dfs(v,adj,visited);
            }
        }


        return k;
    }


int32_t main() {

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int s, e, x, y;
        cin >> s >> e;

        int MOD = 1e9 + 7;

        vector<vector<int>> adj(s + 1);
        for (int i = 0; i < e; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(s + 1, false);

        x=0;
        y = 1;

        for (int i = 1; i <= s; ++i) {
            if (!visited[i]) {
                

               
                x++;

                int p=dfs(i, adj, visited);
                y = (y * p) % MOD;
                x=x%MOD;
            }
        }

        cout << x << " " << y << endl;
    }

    
}
