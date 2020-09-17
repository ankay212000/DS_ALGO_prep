#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000
#define limit 10000

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

int main()
{
    io;
    ll test_case;
    cin>>test_case;
    while(test_case--)
    {
        ll n,s;
        cin>>n>>s;
        ll arr[n];
        for(int i=1;i<=n;i++) cin>>arr[i];

        int i=1,j=1,sum=0;
        while(j<=n)
        {
            while(sum>s&&i<=j)
            sum-=arr[i],i++;

            if(sum==s)
            break;

            else
            sum+=arr[j],j++;
        }
        while(sum>s&&i<=j)
            sum-=arr[i],i++;

        if(sum!=s)
        print(-1);
        else
        print2(i,j-1);
    }
}
