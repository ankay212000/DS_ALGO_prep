#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000000
#define limit 10000

int maxsum(ll arr[],int n)
{
    int curr_sum=0;
    for(int i=0;i<n;i++)
    curr_sum+=arr[i];
    
    int curr_val=0;
    for(int i=0;i<n;i++)
    curr_val+=i*arr[i];
    
    int res=curr_val;
    for(int i=1;i<n;i++)
    {
        int next_val=curr_val-(curr_sum-arr[i-1])+arr[i-1]*(n-1);
        curr_val=next_val;
        
        res=max(res,next_val);
    }
    return res;
}

int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        ll n,sum;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<maxsum(arr,n)<<"\n";
    }
}
