#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000000
#define limit 10000

bool pair_sum(ll arr[],int sum,int n)
{
    unordered_map<int,int> keys;
    for(int i=0;i<n;i++)
    {
        if(keys.find(sum-arr[i])!=keys.end())
        return true;

        keys[arr[i]]=1;
    }

    return false;
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
        cin>>sum;
        pair_sum(arr,sum,n)==1?cout<<"True\n":cout<<"False\n";
    }
}
