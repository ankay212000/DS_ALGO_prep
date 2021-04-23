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
bool visited[N+1];
int dist[N+1];

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
        queue<int> node;
        node.push(1);
        visited[1]=1;
        while(!node.empty())
        {
          int p=node.front();
          node.pop();

          for(auto x: adj[p])
          {
            if(!visited[x])
            node.push(x),visited[x]=1,dist[x]=dist[p]+1;;
          }
        }

        cout<<dist[n]<<"\n";

        for(int i=0;i<=N;i++) adj[i].clear(),visited[i]=0,dist[i]=0;
    }   
}
