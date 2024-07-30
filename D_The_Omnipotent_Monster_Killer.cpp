#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define fori(a, b) for(int i=a; i<b; i++)
#define forj(a, b) for(int j=a; j<b; j++)
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<int>::iterator vit;
typedef set<int> si;
typedef map<int, int> mii;
typedef long long ll;

#include <map>
#include <queue>
#define INF 1e18
#define pb push_back
#define F first
#define S second

const int MAXN = 300005;
const int MAXK = 24;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        vector<ll> values(n+1);
        vector<vector<ll>> dp(n+1, vector<ll>(MAXK));
        vector<vi> adj(n+1);
        
        fori(1, n+1) cin >> values[i];
        
        fori(1, n) {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        
        function<void(int,int)> traverse = [&](int node, int parent) {
            fori(1, MAXK-1) dp[node][i] = i * values[node];
            
            for (int child : adj[node]) {
                if (child == parent) continue;
                traverse(child, node);
                
                ll temp = INF;
                vector<ll> min_vals(MAXK, INF);
                
                for (int k = MAXK-2; k >= 1; k--) {
                    min_vals[k] = min(min_vals[k+1], dp[child][k]);
                }
                
                fori(1, MAXK-1) {
                    dp[node][i] += min(temp, min_vals[i+1]);
                    temp = min(temp, dp[child][i]);
                }
            }
        };
        
        traverse(1, 0);
        
        cout << *min_element(dp[1].begin()+1, dp[1].begin()+MAXK-1) << '\n';
    }
    
    return 0;
}