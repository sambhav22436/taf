#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int MAXD = 19; // Maximum number of digits
const int mod = 9;   // For divisibility by 9

long long dp[MAXD][mod][10][2];

// state: pos, mod, last_digit, tight
long long count(const string& num, int pos, int mod, int last, bool tight) {
    if (pos == num.length()) return (mod == 0);
    
    if (dp[pos][mod][last][tight] != -1) return dp[pos][mod][last][tight];
    
    long long result = 0;
    int limit = tight ? (num[pos] - '0') : 9;
    
    for (int digit = 0; digit <= limit; digit++) {
        if (digit == 7) continue; // Skip 7
        if (digit == last) continue; // Skip if same as last digit
        
        bool new_tight = tight && (digit == limit);
        int new_mod = (mod + digit) ;
        
        result += count(num, pos + 1, new_mod, digit, new_tight);
    }
    
    return dp[pos][mod][last][tight] = result;
}

long long solve(long long n) {
    if (n < 9) return 0;
    string num = to_string(n);
    memset(dp, -1, sizeof(dp));
    return count(num, 0, 0, 10, true); // 10 as initial last digit (invalid)
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a-1) << endl;
    return 0;
}