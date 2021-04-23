#include<bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 100000
using namespace std;

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

vector<int> adj[100001];
bool visited[100001];
int dis[100001];


void dfs(int n,int dist)
{
    visited[n]=1;
    dis[n]=dist;
    //cout<<n<<" "<<p<<"\n";
    for(auto x: adj[n])
    {
        if(!visited[x])
        dfs(x,dist+1);
    }
}

signed main()
{
    io;
    int test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        int n;
        cin>>n;

        int a,b;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=1;i<=n;i++)
        if(!visited[i])
        dfs(i,0);

        int ans=INT_MAX,res;
        int q;
        cin>>q;

        for(int i=0;i<q;i++)
        {
            cin>>a;
            if(ans>dis[a])
            {
                ans=dis[a];
                res=a;
            }
        }
        
        print(res);
    }   
}
