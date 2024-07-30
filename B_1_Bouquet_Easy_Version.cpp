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
    while(t--){

        int s, e, x, y;

        cin>>s>>e;

        vi ss(s);

        fori(0,s){
            cin>>ss[i];
        }

        sort(ss.begin(),ss.end());

        x=0;
        y=0;

        int c=0;
        int ans=0;

        while(x<s){
            c+=ss[x];

            while((ss[x]-ss[y])>1){
                c-=ss[y++];
            }

            while(c>e){
                c-=ss[y++];
            }

            ans=max(ans,c);

            x++;

        }

        cout<<ans<<endl;




    } 
    return 0;
}