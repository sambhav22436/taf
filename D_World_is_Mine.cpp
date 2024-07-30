#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), cnt(n + 1, 0);

    // Read the array and count occurrences
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    // Sort the array and remove duplicates
    sort(a.begin() + 1, a.end());
    a.erase(unique(a.begin() + 1, a.end()), a.end());

    int m = a.size() - 1, sum = 0;
    priority_queue<int> pq;

    for (int i = 1; i <= m; ++i) {
        if (sum + cnt[a[i]] + pq.size() <= i - 1) {
            pq.push(cnt[a[i]]);
            sum += cnt[a[i]];
        } else if (!pq.empty() && pq.top() > cnt[a[i]] && (sum - pq.top()) + cnt[a[i]] + (pq.size() - 1) <= i - 1) {
            sum -= pq.top();
            pq.pop();
            pq.push(cnt[a[i]]);
            sum += cnt[a[i]];
        }
    }

    cout << m - pq.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
