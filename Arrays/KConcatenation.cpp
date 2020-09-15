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

ll kadane(vector<ll> a)
{
    ll curr_max=0,max_sum=LONG_MIN;
    for(int i=0;i<a.size();i++)
    {
        curr_max=max(curr_max+a[i],a[i]);
        max_sum=max(max_sum,curr_max);
        if(curr_max<0)
        curr_max=0;
    }

    return max_sum;
}

int main()
{
    io;
    ll test_case;   //test_case input
    cin>>test_case;
    //test_case=1;
    while(test_case--)
    {
        ll n,k,temp;
        cin>>n>>k;
        vector<ll> arr;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            arr.push_back(temp);
            sum+=arr[i];
        }
        if(k==1)
        {
            print(kadane(arr));
            continue;
        }    
        for(int i=0;i<n;i++)
            arr.push_back(arr[i]);

        ll ans=kadane(arr);
        //cout<<sum<<"\n";
        if(sum>0)
            ans+=sum*(k-2);
        cout<<ans<<"\n";
    }
    return 0;
}