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
 








int32_t main() {
    
    int t;
    
    cin>>t;
    
    while(t--){
        
    int s, e, x, y ;
    
    cin >> s >> e >> x ;
    
    vi v(s);
    
    int d=0;
    y=0;
    
   
  
   
    
    fori(0,s){
        cin>>v[i];
        
        
        
    }
    
    sort(v.begin(),v.end());
    
    
    fori(0,s){
        
        // cout<<d<<endl;
        
        y+= min(e,x)*(v[i]+d);
        
        d+=min(e,x);
        
        
        x-=min(e,x);
        
    
   
    }
    
    cout<<y<<endl;


}}
