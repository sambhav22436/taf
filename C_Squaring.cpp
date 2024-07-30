#include <iostream>
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
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int s, e, x, y;
        cin >> s;
        vector<int> ss(s);
        
        fori(0,s){
            cin>>ss[i];
        }
        
        int acts = 0;

        int c=0;
        
        
        for (int i = 1; i < s ;++i) {

            if (ss[i]==1 && ss[i-1]>1) {
                acts=-1;
                break;
            }
                

                int yy = max<int>(0, c + (ss[i - 1] == 1 ? 0 : ceil(log2(log2(ss[i - 1]) / log2(ss[i])))));

                acts+=yy;
                c=yy;
                 
                    
                
            

            

        }
        
        // if (impossible) {
        //     cout << -1 << endl;
        // } else {
            cout << acts << endl;
        
    }
    
    return 0;
}