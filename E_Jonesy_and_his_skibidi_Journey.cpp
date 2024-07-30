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

#define MOD 1000000007
#define MOD1 998244353

int32_t main() {
    int size;
    cin >> size;
    vi sequence(size);
    
    fori(0, size) {
        cin >> sequence[i];
    }
    
    // Compress values
    unordered_map<int, int> value_map;

    for (int val : sequence) {
        value_map[val] = 0;
    }
    
    vi unique_sorted;

    for (auto& pair : value_map) {
        unique_sorted.pb(pair.F);
    }


    sort(unique_sorted.begin(), unique_sorted.end());
    
    unordered_map<int, int> index_mapping;


    fori(0, unique_sorted.size()) {
        index_mapping[unique_sorted[i]] = i;
    }
    
    vi compressed;

    for (int val : sequence) {
        compressed.pb(index_mapping[val]);
    }
    
    int unique_count = unique_sorted.size();
    
    // Initialize memoization table
    vector<vector<vector<vector<int>>>> memo(size, vector<vector<vector<int>>>(size, vector<vector<int>>(unique_count, vector<int>(unique_count, -1))));
    
    
    function<int(int, int, int, int)> max_compatible_pairs = [&](int start, int end, int min_val, int max_val) -> int {
        if (start > end || min_val > max_val) {
            return 0;
        }
        if (memo[start][end][min_val][max_val] != -1) {
            return memo[start][end][min_val][max_val];
        }
        if (start == end) {
            return (min_val <= compressed[start] && compressed[start] <= max_val) ? 1 : 0;
        }
        
        int max_pairs = max(
            max_compatible_pairs(start + 1, end, min_val, max_val),
            max_compatible_pairs(start, end - 1, min_val, max_val)
        );
        
        if (min_val <= compressed[start] && compressed[start] <= max_val) {
            max_pairs = max(max_pairs, max_compatible_pairs(start + 1, end, compressed[start], max_val) + 1);
        }
        
        if (min_val <= compressed[end] && compressed[end] <= max_val) {
            max_pairs = max(max_pairs, max_compatible_pairs(start, end - 1, min_val, compressed[end]) + 1);
        }
        
        swap(compressed[start], compressed[end]);
        
        if (min_val <= compressed[start] && compressed[start] <= max_val) {
            max_pairs = max(max_pairs, max_compatible_pairs(start + 1, end - 1, compressed[start], max_val) + 1);
        }
        
        if (min_val <= compressed[end] && compressed[end] <= max_val) {
            max_pairs = max(max_pairs, max_compatible_pairs(start + 1, end - 1, min_val, compressed[end]) + 1);
        }
        
        if (min_val <= compressed[start] && compressed[start] <= max_val && 
            min_val <= compressed[end] && compressed[end] <= max_val) {
            max_pairs = max(max_pairs, max_compatible_pairs(start + 1, end - 1, compressed[start], compressed[end]) + 2);
        }
        
        swap(compressed[start], compressed[end]);
        
        memo[start][end][min_val][max_val] = max_pairs;
        return max_pairs;
    };
    
    int answer = max_compatible_pairs(0, size - 1, 0, unique_count - 1);
    cout << answer << endl;
    
    return 0;
}