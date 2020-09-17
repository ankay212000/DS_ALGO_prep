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
    //test_case=1;
    while(test_case--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        int left[n],right[n];
        
        left[0]=arr[0];
        for(int i=1;i<n;i++)
        left[i]=max(left[i-1],arr[i]);

        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        right[i]=max(right[i+1],arr[i]);

        int res=0;
        for(int i=0;i<n;i++)
        res+=min(left[i],right[i])-arr[i];

        print(res);
    }
}
