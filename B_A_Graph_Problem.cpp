#include <bits/stdc++.h>
using namespace std;

#define int long long
#define setbits(x) __builtin_popcountll(x) // give the count of total set bits in a number
#define backzero(x) __builtin_ctzll(x)
#define frontzero(x) (32 - __builtin_clz(x - 1))
#define biggestpower2(x) (31 - __builtin_clz(x))
#define mod 1000000007
#define mod2 998244353
#define mem0(x) memset(x, 0, sizeof x)
#define mem1(x) memset(x, -1, sizeof x)
#define pb push_back
#define pr pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpr vector<pr>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rev(a) reverse(all(a))
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
const int infi = 9e18;

// Can be used to find power a raise to b
int pwr(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a);
        }
        a = (a * a);
        b = b >> 1;
    }
    return ans;
}

// Used when mod is included in power
int modpwr(int a, int b, int M)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b = b >> 1;
    }
    return ans;
}

// Multiplicative Inverse
int modInverse(int a, int M)
{
    return modpwr(a, M - 2, M);
}

// Square Root
int bs_sqrt(int x)
{
    int left = 0, right = 1e10 + 1;
    while (right > left)
    {
        int mid = (left + right) / 2;
        if (mid * mid > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}

void solve()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ar[n - x] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (ar[i] < ar[i - 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}