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
        cin >> s;

        string st;
        cin >> st;
        
        vi ss;

        char p = '1';
        
        x=0;
        y=0;
        
        fori(0,s){

            if (st[i] == '1'){
                ss.pb(1);
            }
            // if (st[i] == '1' && p == '0'){

            //     // p=st[i];

            //     ss.pb(1);
            //     p=st[i];
            // }

            if (st[i] == '0' && p == '1'){

                // p=st[i];

                ss.pb(0);
            }

            p = st[i];
        }
        
        
        

        fori(0,ss.size()){
            if (ss[i] == 1){
                x++;

            } else{
                y++;

            }
        }
        
        
        if (y >= x){
            cout << "No" << endl;
        } else{
            cout << "Yes" << endl;
        }


    }
    
    return 0;
}

