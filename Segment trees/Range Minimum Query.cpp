#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000
#define mod 1000000007
 
template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}
 
 
int arr[N+1];
int Nodes[4*(N+1)];
 
void build(int start,int end,int x)
{
    if(start==end)
    {
        Nodes[x]=arr[start];
        return ;
    }
    int mid=(start+end)/2;
    build(start,mid,2*x);
    build(mid+1,end,2*x+1);
    Nodes[x]=min(Nodes[2*x],Nodes[2*x+1]);
 
    return;
}

int query(int start,int end,int l,int r,int x)
{
    if(end<l||start>r)
    return INT_MAX;
    
    if(start>=l&&end<=r) return Nodes[x];
 
    int mid=(start+end)/2;
    int left=query(start,mid,l,r,2*x);
    int right=query(mid+1,end,l,r,2*x+1);
 
    return min(left,right);
}
 
 
int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>arr[i];
        int m;
        cin>>m;
        build(1,n,1);
        int l,r;
        for(int i=0;i<m;i++)
        {
            cin>>l>>r;
            print(query(1,n,l+1,r+1,1));
        }
    }
} 
