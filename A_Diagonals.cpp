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

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int s, e, x, y;
        cin >> s >> e;

       

        x = 0;
        
        for(int y = 1; e > 0; y++) {
            if (y == 1) {
                e -= s;
            }
            else {
                int diff = s - y + 1;
                if(e > diff) {
                    x++;
                    e -= 2 * diff;
                }
                else {
                    e -= diff;
                }
            }
            x++;
        }
        
        cout << x << endl;



        
    }

    return 0;
}
