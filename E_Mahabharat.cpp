#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n, m, k, w;
vector<vector<string>> layers;

int calculate_diff(int i, int j) {
    int count = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (layers[i][r][c] != layers[j][r][c]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    cin >> n >> m >> k >> w;

    layers.resize(k, vector<string>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> layers[i][j];
        }
    }

    vector<bool> memorized(k, false);
    int total_effort = n * m;  // Memorize the first layer entirely
    memorized[0] = true;

    for (int i = 1; i < k; i++) {
        int min_effort = n * m;
        int best_prev = -1;

        for (int j = 0; j < i; j++) {
            if (memorized[j]) {
                int diff_effort = calculate_diff(i, j) * w;
                if (diff_effort < min_effort) {
                    min_effort = diff_effort;
                    best_prev = j;
                }
            }
        }

        total_effort += min_effort;
        memorized[i] = true;
    }

    cout << total_effort << endl;

    return 0;
}