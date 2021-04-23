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

vector<int> adj[N+1];
bool visited[N+1];

void dfs(int n,int *c)
{
    visited[n]=true;
    *c=(*c%mod+1%mod)%mod;
    for(auto x: adj[n])
    {
      if(!visited[x])
      dfs(x,c);
    }
    
}

signed main()
{
    io;
    int test_case;
    cin>>test_case;
    //test_case=1;
    for(int i=1;i<=test_case;i++)
    {
        int n,m;
        cin>>n>>m;

        int a,b;
        for(int i=0;i<m;i++)
        {
          cin>>a>>b;
          adj[a].push_back(b);
          adj[b].push_back(a);
        }
        int ways=1,cnt=0,c=0;
        for(int i=1;i<=n;i++)
        { 
          if(!visited[i])
          {
            c=0;
            dfs(i,&c);
            ways=(ways%mod*c%mod)%mod;
            cnt++;
          }  
        }
        print2(cnt,ways);
        for(int i=1;i<=N;i++) adj[i].clear();
        for(int i=1;i<=N;i++) visited[i]=0;
    }   
}
