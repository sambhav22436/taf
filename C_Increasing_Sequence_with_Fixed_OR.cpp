#include <bits/stdc++.h>
#define int long long int

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int s = 0;
        vector<int> seq;
        vector<int> bits;
        for (int i = 0; i < 61; i++) {
            if (x & (1LL << i)) {
                s++;
                bits.push_back((1LL << i));
            }
        }
        s++;
        seq.push_back(x);
        for (auto e : bits) {
            if (x - e > 0) {
                seq.push_back(x - e);
            }
        }

        reverse(seq.begin(), seq.end());
        cout << seq.size() << endl;
        for (auto y : seq) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
