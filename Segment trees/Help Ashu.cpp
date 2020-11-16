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
vector<pair<int,int> > Nodes(4*(N+1));

void build(int start,int end,int x)
{
    if(start==end)
    {
        if(arr[start]%2)
        {
            Nodes[x].first=0;
            Nodes[x].second=1;
        }
        else
        {
            Nodes[x].first=1;
            Nodes[x].second=0;
        }
        
        return ;
    }
    int mid=(start+end)/2;
    build(start,mid,2*x);
    build(mid+1,end,2*x+1);
    Nodes[x].first=(Nodes[2*x].first+Nodes[2*x+1].first);
    Nodes[x].second=(Nodes[2*x].second+Nodes[2*x+1].second);

    return;
}

void update(int start,int end,int index,int value,int x)
{
    if(start==end)
    {
        if(value%2)
        Nodes[x].first=0,Nodes[x].second=1;
        else
        Nodes[x].first=1,Nodes[x].second=0;
        return ;
    }
    int mid=(start+end)/2;
    if(mid>=index)
    update(start,mid,index,value,2*x);
    else
    update(mid+1,end,index,value,2*x+1);

    Nodes[x].first=(Nodes[2*x].first+Nodes[2*x+1].first);
    Nodes[x].second=(Nodes[2*x].second+Nodes[2*x+1].second);

    return;
}

int evenquery(int start,int end,int l,int r,int x)
{
    if(end<l||start>r)
    return 0;
    
    if(start>=l&&end<=r) return Nodes[x].first;

    int mid=(start+end)/2;
    int left=evenquery(start,mid,l,r,2*x);
    int right=evenquery(mid+1,end,l,r,2*x+1);

    return left+right;
}

int oddquery(int start,int end,int l,int r,int x)
{
    if(end<l||start>r)
    return 0;
    
    if(start>=l&&end<=r) return Nodes[x].second;

    int mid=(start+end)/2;
    int left=oddquery(start,mid,l,r,2*x);
    int right=oddquery(mid+1,end,l,r,2*x+1);

    return left+right;
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
        int a,l,r;
        for(int i=0;i<m;i++)
        {
            cin>>a>>l>>r;
            if(a==0) update(1,n,l,r,1);
            else if(a==1)
            print(evenquery(1,n,l,r,1));
            else
            print(oddquery(1,n,l,r,1));
        }
    }
}
