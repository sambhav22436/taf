#include <iostream>
#include <vector>
using namespace std;
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



int ct(int x){
    int d= (x*(x-1))/2;

    return d;

    
}


int factorial(int num) {
    if (num <= 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= num; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate binomial coefficient
int binomialCoefficient(int n, int k) {
    if (k > n) return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to find the number of ways to divide n into 3 positive integer sets
int numberOfWays(int n) {
    
    return binomialCoefficient(n - 1, 2);
}



set<tuple<int, int, int>> findTriplets(int N) {
    set<tuple<int, int, int>> triplets;
    
    for (int a = 1; a <= N-2; ++a) {
        for (int b = 1; b <= N-a-1; ++b) {
            int c = N - a - b;
            if (c >= 1) {
                triplets.emplace(a, b, c);
            }
        }
    }
    
    return triplets;
}

int32_t main() {
    int t;
    cin >> t;
    while(t--){
        set<tuple<int, int, int>> trip;

        int n,x;

        cin>>n>>x;

       vector<int> v;

       int ans=1;




        
    for (int i = 4; i <= x; i++) {

        if(ct(i)<=n){
            // set<tuple<int, int, int>> trip1;
            // trip1= findTriplets(x);
            // trip.insert(trip1.begin(),trip1.end());


            ans+=numberOfWays(i);
            // cout<<i<<" "<<ans<<endl;



        }
        if(ct(i)>n){
            break;
        }


    }

    cout<<ans<<endl;

        


    }

    return 0;
}
