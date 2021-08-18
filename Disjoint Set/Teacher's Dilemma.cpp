#include<bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 100000
#define mod 1000000007
using namespace std;

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

int parent[N+1];

void Union(int a,int b)
{
    parent[a]+=parent[b];
    parent[b]=a;
}

int find(int a)
{
    if(parent[a]<0)
    return a;

    return parent[a]=find(parent[a]);
}

signed main()
{
    io;

        int n,m;
        cin>>n>>m;
        
        for(int i=1;i<=n;i++) parent[i]=-1;

        int a,b;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            a=find(a);
            b=find(b);

            if(a!=b)
            Union(a,b);
        }    
        
        int res=1;
        for(int i=1;i<=n;i++)
        {
            if(parent[i]<0)
                res=(res%mod*abs(parent[i])%mod)%mod;
        }

        print(res);      
}
