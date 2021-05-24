#include <bits/stdc++.h>
using namespace std;
 
int a[5005];
long long int dp[5005][5005];
 
long long int getAns(int i, int j)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
 
    long long int op1 = a[i] + min(getAns(i + 2, j), getAns(i + 1, j - 1));
    long long int op2 = a[j] + min(getAns(i, j - 2), getAns(i + 1, j - 1));
    return dp[i][j] = max(op1, op2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << getAns(1, n);
}