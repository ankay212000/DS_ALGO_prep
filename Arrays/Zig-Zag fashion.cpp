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
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        ll minnum,maxnum,med;
        int i;
        for(i=0;i<n;i+=2)
        {
            if(i>n-1||i+1>n-1||i+2>n-1)
            break;
            else
            {
                maxnum=max(arr[i],max(arr[i+1],arr[i+2]));
                minnum=min(arr[i],min(arr[i+1],arr[i+2]));
                med=(arr[i]+arr[i+1]+arr[i+2])-(minnum+maxnum);

                arr[i]=minnum;
                arr[i+1]=maxnum;
                arr[i+2]=med;
            }
        }
        if(i!=n-1)
        {
            if(arr[i]>arr[i+1])
            {
                ll temp;
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }    
        }
        for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<"\n";
    }
}