#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000000
#define limit 10000

int search(ll arr[],int k,int n)
{
    int start=0,end=n-1;
    while(start<end)
    {
        int mid=(start+end)/2;
        //cout<<start<<" "<<end<<" "<<mid<<"\n";
        if(end-start==1)
        {
            if(arr[end]>arr[end+1])
            start=end;
            break;
        }
        if(arr[mid]<arr[start])
        end=mid-1;
        else
        start=mid;
    }
    
    if(arr[0]<=k&&arr[start]>=k)
    {
        end=start;
        start=0;

        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]==k)
            return mid;
            else if(arr[mid]>k)
            end=mid-1;
            else
            start=mid+1;
        }

        return -1;
    }
    else if(arr[start+1]<=k&&arr[n-1]>=k)
    {
        end=n-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]==k)
            return mid;
            else if(arr[mid]>k)
            end=mid-1;
            else
            start=mid+1;
        }
        return -1;
    }
    return -1;
}

int main()
{
    io;
    ll test_case;
    cin>>test_case;
    while(test_case--)
    {
        ll n,k;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cin>>k;
        cout<<search(arr,k,n)<<"\n";
    }
}
