#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int k = i; k > 0; k /= 10)
        {
            int dig = k % 10;
            if (i - dig >= 0)
                dp[i] = min(dp[i], 1 + dp[i - dig]);
        }
    }
    cout << dp[n];
}