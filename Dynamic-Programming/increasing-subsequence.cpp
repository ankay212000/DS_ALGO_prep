#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define vi vector<int>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)

//EDITORIAL
/*dp[i] denotes if LIS of length i can be constructed ;

 for each value x check 1/ if(lower_bound(x)) != dp.end() repalce *it=x;
 2/if it==dp.end() dp.pb(x)

 to find strictly LIS change lower_bound to upper_bound */
int32_t main()
{
    fastio;
    int n;
    cin >> n;
    vi dp;
    rep(i, n)
    {
        int x;
        cin >> x;
        auto it = lower_bound(all(dp), x);
        if (it == dp.end())
            dp.push_back(x);
        else
        {
            *it = x;
        }
    }
   cout<<dp.size()<<"\n";
}