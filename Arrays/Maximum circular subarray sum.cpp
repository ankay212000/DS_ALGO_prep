#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
#define N 100000
#define mod 1000000007
 
template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

int kadanes(ll arr[],ll n)
{
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];

    ll curr_max_sum=arr[0],max_sum=arr[0],min_sum=arr[0],curr_min_sum=arr[0];
    for(int i=1;i<n;i++)
    {
        curr_max_sum=max(curr_max_sum+arr[i],arr[i]);
        curr_min_sum=min(curr_min_sum+arr[i],arr[i]);

        max_sum=max(curr_max_sum,max_sum);
        min_sum=min(min_sum,curr_min_sum);
    }

    if(min_sum==sum)
    return max_sum;

    else
    return max(max_sum,sum-min_sum);
}

int main()
{
    io;
    ll test_case;   //test_case input
    cin>>test_case;
    //test_case=1;
    while(test_case--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        
        print(kadanes(arr,n));
    }
    return 0;
}
