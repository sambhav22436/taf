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




int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    
    while (t--) {
        int s, e, x, y;
        cin >> s >> e >> x;
        
        vector<int> ss(s + 1, -1);


        fill(ss.begin() + x, ss.begin() + e + 1, 1);
        
        y = -1;
        for (int i = x - 1; i >= 1; --i) {
            ss[i] = y;
            y = -y;
        }
        
        y = -1;
        for (int i = e + 1; i <= s; ++i) {
            ss[i] = y;
            y = -y;
        }
        
        
        fori(1,s+1){
            cout << ss[i] << " ";11111`````
        }
        cout << endl;
    }
    
    return 0;
}
