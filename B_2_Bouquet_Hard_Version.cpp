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
    while(t--) {
        int s, e, x, y;


        cin >> s >> e;

        vi types(s), counts(s);


        fori(0, s){ 
            cin >> types[i];}

        fori(0, s){ 
            cin >> counts[i];
            }

        mii fll;

        fori(0, s) {
            fll[types[i]] = counts[i];
        }

        int best_revenue = 0;

        vi ssp;

        for(const auto& pair : fll) {
            ssp.pb(pair.F);
        }
        
        sort(ssp.begin(), ssp.end());

        for(int price : ssp) {


            int css = fll[price];

            int nss = (fll.find(price + 1) != fll.end()) ? fll[price + 1] : 0;

            int cbb = min(css, e / price);
            int rem= e - cbb * price;

            int nbb = 0;
            if(nss > 0) {
                nbb = min(nss, rem/ (price + 1));
                rem-= nbb * (price + 1);
            }

            best_revenue = max(best_revenue, cbb * price + nbb * (price + 1));

            int leftover_next = nss - nbb;
            int transferable = min(min(cbb, rem), leftover_next);
            cbb -= transferable;
            nbb += transferable;

            best_revenue = max(best_revenue, cbb * price + nbb * (price + 1));
        }

        cout << best_revenue << endl;
    }

    return 0;
}