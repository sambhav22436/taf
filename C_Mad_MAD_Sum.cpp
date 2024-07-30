#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
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
// Function to compute the MAD (Maximum Appearing Duplicate)
int computeMAD(const vector<int>& arr, int end) {
    mii freq;
    int mad = 0;

    for (int i = 0; i < end; ++i) {
        freq[arr[i]]++;
        if (freq[arr[i]] >= 2) {
            mad = max(mad, arr[i]);
        }
    }

    return mad;
}

void processTestCase() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int sum = 0;
    while (true) {
        // Add the sum of current array
        sum += accumulate(a.begin(), a.end(), 0);

        // Compute the new array
        vector<int> new_a(n);
        bool allZeros = true;

        for (int i = 0; i < n; ++i) {
            int mad = computeMAD(a, i + 1);
            new_a[i] = mad;
            if (mad != 0) {
                allZeros = false;
            }
        }

        // Check if all elements are zero
        if (allZeros) {
            break;
        }

        // Update the array
        a = new_a;
    }

    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        processTestCase();
    }

    return 0;
}
