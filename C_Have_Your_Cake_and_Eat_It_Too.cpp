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
    while(t--){

        int s,e,x,y;
        cin >> s;  
        int n; cin >> n;
        vector<vector<int>> a(3, vector<int>(n+1)), pr(3, vector<int>(n+1)),sf(3, vector<int>(n+1));
        vi f1,f2,f3;


        for (int i=0; i<3; i++){

         for (int j=1; j<=n; j++){
             cin >> a[i][j];
         }}


        int tot = 0;


        for (int i=1; i<=n; i++) tot+= a[0][i];

        int tr= (tot+2)/3;


        
        
        

       
    }
    return 0;
}

