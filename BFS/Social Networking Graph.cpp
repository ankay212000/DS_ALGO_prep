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

vector<int> adj[N+1];
bool vis[N+1];
int dist[N+1];

int bfs(int i,int j,int n)
{
    queue<int> node;
    node.push(i);
    vis[i]=true;
    dist[i]=0;
    while(!node.empty())
    {
        int p=node.front();
        node.pop();
        for(auto x: adj[p])
        {
            if(!vis[x])
            vis[x]=true,dist[x]=dist[p]+1,node.push(x);
        }
    }

    int cnt=0;

    for(int i=0;i<=n;i++)
    if(dist[i]==j)
    cnt++;


    return cnt;
}

signed main()
{
    io;
    int test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        int n,e;
        cin>>n>>e;
        int a,b;
        for(int i=0;i<e;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int q;
        cin>>q;

        for(int i=0;i<q;i++)
        {
            for(int j=0;j<=n;j++) dist[j]=0,vis[j]=0;
            cin>>a>>b;
            print(bfs(a,b,n));
        }
    }   
}
