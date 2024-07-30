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
        cin >> s ;

        vi ss(s);
        mii cc;

        e=0;
        x=0;
        y=0;

        fori(0,s){
            cin>>ss[i];
            if(ss[i]>e){
                e=ss[i];
            }
            cc[ss[i]]+=1;

        }


        sort(ss.begin(),ss.end());

        unique(ss.begin(),ss.end());

        for(int i=ss.size();i>=0;i--){

            if(cc[ss[i]]%2==1){
                cout<<"YES"<<endl;
                y=1;

                break;


            }


        }







        if(y==0){
            cout<<"NO"<<endl;
        }
        // else{
        //     cout<<"NO"<<endl;
        // }

        





    }
    return 0;
}
