#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define mp make_pair
#define int long long
#define fori(a, b) for(int i=a; i<b; i++)
#define forj(a, b) for(int j=a; j<b; j++)
typedef unsigned long long ull;
typedef long double lld;

const int MAXN = 505;
int dp[MAXN][MAXN];
int choose[MAXN / 2 + 1][MAXN / 2 + 1];

int count_ways(int s, int e, const string& x) {
    if ((e - s) % 2 == 0) return 0;
    if (s > e) return 1;
    if (dp[s][e] != -1) return dp[s][e];
    if (e - s == 1) return dp[s][e] = (x[s] == x[e]);

    int y = 0;
    for (int k = s + 1; k <= e; k += 2) {
        if (x[s] == x[k]) {
            int temp = (count_ways(s + 1, k - 1, x) * 
                        count_ways(k + 1, e, x) * 
                        choose[(e - s + 1) / 2][(e - k) / 2]) % MOD;
            y = (y + temp) % MOD;
        }
    }

    return dp[s][e] = y;
}

void compute_combinations(int n) {
    choose[0][0] = 1;
    for (int i = 1; i <= n/2; i++) {
        choose[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            choose[i][j] = (choose[i-1][j] + choose[i-1][j-1]) % MOD;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    string s;
    cin >> n >> s;

    memset(dp, -1, sizeof(dp));
    compute_combinations(n);

    cout << count_ways(0, n-1, s) << '\n';

    return 0;
}