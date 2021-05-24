#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, W;
    cin >> n >> W;
    int cost[n], w[n];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];
 
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (j - w[i - 1] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], cost[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][W];
}