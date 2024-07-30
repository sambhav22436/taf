#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const long long INF = numeric_limits<long long>::max();

struct Edge {
    int from, to;
    long long cost;
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;  // Convert to 0-based index
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> disc(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> disc[i][j];
        }
    }

    vector<Edge> edges;

    // Construct the graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                edges.push_back({i, j, p[j] + disc[j][i]});
            }
        }
    }

    vector<long long> dist(n, INF);
    dist[a[0]] = p[a[0]];

    // Bellman-Ford algorithm
    for (int i = 0; i < k - 1; i++) { // Relax the edges k-1 times
        for (const auto& edge : edges) {
            if (dist[edge.from] != INF && dist[edge.from] + edge.cost < dist[edge.to]) {
                dist[edge.to] = dist[edge.from] + edge.cost;
            }
        }
    }

    // Result: find the minimum distance to buy exactly the k artifacts
    long long result = 0;
    for (int i = 0; i < k; i++) {
        result += dist[a[i]];
    }

    cout << result << endl;

    return 0;
}
