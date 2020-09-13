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

void subarray(ll arr[],ll n,int k)
{
    ll sum=0;
    map<int,int> num;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==k)
        {
            cout<<0<<" "<<i<<"\n";
            return;
        }
        if(num.find(sum-k)!=num.end())
        {
            //cout<<"sum: "<<sum<<"\n";
            cout<<num[sum-k]<<" "<<i<<"\n";
            return;
        }

        num[sum]=i+1;
    }

    cout<<"No Subarray found\n";
    return ;
}

int main()
{
    io;
    ll test_case;   //test_case input
    cin>>test_case;
    //test_case=1;
    while(test_case--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        subarray(arr,n,k);
    }
    return 0;
}