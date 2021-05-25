#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
 
int n = 1000000;
ll dp[1000001][2];

//EDITORIAL
// dp[i][0]=number of ways to reach n th height if i-1th pos had 2 tiles of width 1
 
//dp[i][1]=if i-1 th pos had a tile of width 2
int main()
{
    fast_io;
    int t = 1; //cin >> t;
    while (t--)
    {
        dp[n + 1][0] = dp[n + 1][1] = 1;
 
        for (int i = n; i >= 2; i--)
        {
            ll op1 = (dp[i + 1][1] + dp[i + 1][0]) % mod;
            ll op2 = dp[i + 1][0];
            ll op3 = (2 * dp[i + 1][0]) % mod;
            ll op4 = dp[i + 1][1];
 
            dp[i][0] = (op1 + op2 + op3) % mod;
            dp[i][1] = (op1 + op4) % mod;
        }
 
        int q;
        cin >> q;
        while (q--)
        {
            int query;
            cin >> query;
            cout << (dp[1000000 - query + 2][1] + dp[1000000 - query + 2][0]) % mod << '\n';
        }
    }
    return 0;