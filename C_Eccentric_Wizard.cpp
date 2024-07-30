#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 14;
const long long INF = 1e18;

int n, k;
vector<int> required;
vector<int> prices;
vector<vector<int>> disc;

long long dp[1 << MAXN][MAXN + 1];
int required_mask;

long long solve(int mask, int last) {
    if (__builtin_popcount(mask & required_mask) == k) {
        return 0;
    }
    
    if (dp[mask][last + 1] != -1) {
        return dp[mask][last + 1];
    }
    
    long long best = INF;
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            int new_mask = mask | (1 << i);
            long long price = prices[i] - (last != -1 ? disc[i][last] : 0);
            best = min(best, price + solve(new_mask, i));
        }
    }
    
    return dp[mask][last + 1] = best;
}

int main() {
    cin >> n >> k;
    
    required.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> required[i];
        required[i]--;  // Convert to 0-based index
    }
    
    prices.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    disc.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> disc[i][j];
        }
    }
    
    required_mask = 0;
    for (int r : required) {
        required_mask |= (1 << r);
    }
    
    memset(dp, -1, sizeof(dp));
    long long result = solve(0, -1);
    
    cout << result  << endl;
    
    return 0;
}