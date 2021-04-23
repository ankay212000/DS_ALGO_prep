#include<bits/stdc++.h>
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define N 1000000
using namespace std;

template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

vector<int> adj[N+1];
bool visited[N+1];
int dist[N+1],cc[N+1];
int c;

void dfs(int n)
{
  visited[n]=1;
  cc[n]=c;

  for(auto x: adj[n])
  if(!visited[x])
  dfs(x);
}

signed main()
{
    io;
    int test_case;
    cin>>test_case;
    //test_case=1;
    for(int i=1;i<=test_case;i++)
    {
        for(int i=0;i<=N;i++) adj[i].clear(),visited[i]=0,dist[i]=-1;
        int n,k;
        cin>>n>>k;

        int a,b;
        string s;
        vector<pair<int,int> > unequal;
        for(int i=0;i<k;i++)
        {
          cin>>a>>s>>b;
          if(s=="=")
          adj[a].push_back(b),adj[b].push_back(a);
          else
          unequal.push_back({a,b});
        }
        c=0;

        for(int i=1;i<=n;i++)
        if(!visited[i])
        dfs(i),c++;

        string ans="YES";
        for(auto x: unequal)
        {
          if(cc[x.first]==cc[x.second])
          {
            ans="NO";
            break;
          }
        }  
        print(ans);  
    }   
}
