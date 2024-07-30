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
        cin >> s >> e;

        vi ss;

        ss.pb(s);

        x = 0;  


        while (ss.size() < s) {
            int cur = ss.back();
            
            ss.pop_back();

            int di = min(e - 1, cur - 1);

            fori(0, di) {
                ss.pb(1);
            }
            // int di = min(s-1,e-1);
            // fori(0,ss){
            //     ss.pb(1);
            // }
            

            ss.pb(cur - di);

            x++;
        }

        cout << x << endl;
    }
    return 0;
}




