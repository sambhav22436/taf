#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct MagicRegion {
    ll begin, finish, position;
};

bool sortMagicRegions(const MagicRegion &first, const MagicRegion &second) {
    if (first.begin == second.begin)
        return first.finish > second.finish;
    return first.begin < second.begin;
}

vector<MagicRegion> createMagicRegions(int n, const vector<ll> &xranges, const vector<ll> &yranges) {
    vector<MagicRegion> regions(n);
    for (int i = 0; i < n; i++) {
        regions[i] = {xranges[i], yranges[i], i};
    }
    return regions;
}

vector<int> findContainingRegions(const vector<MagicRegion> &sortedRegions) {
    int n = sortedRegions.size();
    vector<int> containsOthers(n, 0);
    ll minEnd = LLONG_MAX;
    for (auto it = sortedRegions.rbegin(); it != sortedRegions.rend(); ++it) {
        if (it->finish >= minEnd) {
            containsOthers[it->position] = 1;
        }
        minEnd = min(minEnd, it->finish);
    }
    return containsOthers;
}

vector<int> findContainedRegions(const vector<MagicRegion> &sortedRegions) {
    int n = sortedRegions.size();
    vector<int> containedByOthers(n, 0);
    ll maxEnd = -1;
    for (const auto &region : sortedRegions) {
        if (region.finish <= maxEnd) {
            containedByOthers[region.position] = 1;
        }
        maxEnd = max(maxEnd, region.finish);
    }
    return containedByOthers;
}

void analyzeMagicRegions(int n, vector<ll> &xranges, vector<ll> &yranges) {
    vector<MagicRegion> regions = createMagicRegions(n, xranges, yranges);
    sort(regions.begin(), regions.end(), sortMagicRegions);
    vector<int> containingRegions = findContainingRegions(regions);
    vector<int> containedRegions = findContainedRegions(regions);
    for (int result : containingRegions) cout << result << ' ';
    cout << endl;
    for (int result : containedRegions) cout << result << ' ';
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<ll> xranges(n);
    vector<ll> yranges(n);
    for (int i = 0; i < n; i++) cin >> xranges[i];
    for (int i = 0; i < n; i++) cin >> yranges[i];
    analyzeMagicRegions(n, xranges, yranges);
    return 0;
}