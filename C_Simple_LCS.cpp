#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>
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

const int MAXN = 505;

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    string x;
    cin >> n >> x;

    vector<vector<int>> dp(MAXN, vector<int>(MAXN, -1));
    vector<vector<int>> choose(MAXN/2+1, vector<int>(MAXN/2+1, 0));

    // Compute combinations
    choose[0][0] = 1;
    fori(1, n/2+1) {
        choose[i][0] = 1;
        forj(1, i+1) {
            choose[i][j] = (choose[i-1][j] + choose[i-1][j-1]) % MOD;
        }
    }

    // Lambda function for count_ways
    function<int(int,int)> count_ways = [&](int s, int e) -> int {
        if ((e - s) % 2 == 0) return 0;
        if (s > e) return 1;
        if (dp[s][e] != -1) return dp[s][e];
        if (e - s == 1) return dp[s][e] = (x[s] == x[e]);

        int y = 0;
        for (int k = s + 1; k <= e; k += 2) {
            if (x[s] == x[k]) {
                int temp = (count_ways(s + 1, k - 1) * 
                            count_ways(k + 1, e) * 
                            choose[(e - s + 1) / 2][(e - k) / 2]) % MOD;
                y = (y + temp) % MOD;
            }
        }

        return dp[s][e] = y;
    };

    // Compute and output the result
    cout << count_ways(0, n-1) << '\n';

    return 0;
}