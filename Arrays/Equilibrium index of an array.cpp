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

void equipoint(ll arr[],ll n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];

    int sum1=0;
    for(int i=1;i<n;i++)
    {
        sum1+=arr[i-1];
        if(sum1==sum-(sum1+arr[i]))
        {
            cout<<i<<"\n";
            return ;
        }

    }
    cout<<"No equilibrium point\n";
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
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        subarray(arr,n);
    }
    return 0;
}