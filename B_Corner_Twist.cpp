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
 




// Function to check if two grids can be made identical using the given operation
bool canTransform(vector<vector<int>>& a, vector<vector<int>>& b, int n, int m) {
    vector<vector<int>> diff(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            diff[i][j] = (b[i][j] - a[i][j] + 3) % 3;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int d = diff[i][j];
            if (d != 0) {
                diff[i][j] = (diff[i][j] - d + 3) % 3;
                diff[i][j + 1] = (diff[i][j + 1] - d + 3) % 3;
                diff[i + 1][j] = (diff[i + 1][j] - d + 3) % 3;
                diff[i + 1][j + 1] = (diff[i + 1][j + 1] - d + 3) % 3;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (diff[i][m - 1] != 0) return false;
    }
    for (int j = 0; j < m; ++j) {
        if (diff[n - 1][j] != 0) return false;
    }

    return true;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char x;
                cin >> x;
                a[i][j] = x - '0';
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char x;
                cin >> x;
                b[i][j] = x - '0';
            }
        }
        if (canTransform(a, b, n, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}