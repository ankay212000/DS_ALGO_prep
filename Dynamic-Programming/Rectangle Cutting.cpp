#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int w, h;
    cin >> w >> h;
    vector<vector<int>> dp(w + 1, vector<int>(h + 1));
    for (int i = 0; i <= w; i++)
    {
        for (int j = 0; j <= h; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 1e9;
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                }
                for (int k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
                }
            }
        }
    }
    cout << dp[w][h] << endl;
}