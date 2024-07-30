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



void countTriangles(const vector<unordered_set<int>>& adj, vector<int>& triangleCount) {
    int n = adj.size();
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            if (u < v) {
                for (int w : adj[u]) {
                    if (v < w && adj[v].count(w)) {
                        triangleCount[u]++;
                        triangleCount[v]++;
                        triangleCount[w]++;
                    }
                }
            }
        }
    }
}

int main() {
    int s, e, x, y;
    cin >> s >> e >> x;

    vector<unordered_set<int>> adj(s + 1); 
    vector<int> Count(s + 1, 0); 


    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }


    countTriangles(adj, Count);

     y = 0;
    for (int i = 1; i <= s; ++i) {
        if (Count[i] < x) {
           y++;
        }
    }

    cout << y << endl;

    return 0;
}
