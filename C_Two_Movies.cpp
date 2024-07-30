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
 








int32_t main() {
    
    int t;
    
    cin>>t;
    
    while(t--){
        
    int s, e, x, y ;
    
    cin >> s  ;
    e=0;
    x=0;
    vi v(s),t(s),m(s);

    fori(0,s){
        cin>>v[i];
        

    }
    fori(0,s){
        cin>>t[i];
        if(v[i]>t[i]){
            e+=v[i];
        }
        if(t[i]>v[i]){
            x+=t[i];
        }

      

    }

 
    
    int ss= max(e,x);

    int og1=0;
    int og2= INT_MIN;

    


    fori(0,s){

        

        if((v[i]==1 && t[i]==1)){
            if(e>x){

                

                x+=t[i];
               



            }
            if(e<x){

                

                e+=t[i];
               



            }
            // if(e==x){

                

            //     // e+=t[i];
            //     // x+=t[i];
            //     continue;



            // }
        }
        if((v[i]==-1 && t[i]==-1)){
            if(e<x){

                

                x+=t[i];
                



            }
            if(e>x){

                

                e+=t[i];
                



            }
            if(e==x){

                

                e+=t[i];
                x+=t[i];
                



            }
        }
        og2= max(og2,min(e,x));



    }





 cout<<min(e,x)<<endl;
    
    
 
  
   
    
    
    }
    
    
    
    


}
