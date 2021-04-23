#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 100000000
#define mod 1000000007
#define inf LLONG_MAX
    
template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}
 
char rooms[1001][1001],vis[1001][1001];
int n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
 
bool isValid(int x,int y)
{
    if(x>n||y>m||x<1||y<1)
    return false;
    
    if(vis[x][y]==true||rooms[x][y]=='#')
    return false;
 
    return true;
}
 
void dfs(int x,int y)
{
    vis[x][y]=true;
    for(int i=0;i<4;i++)
    {
        if(isValid(x+dx[i],y+dy[i]))
        dfs(x+dx[i],y+dy[i]);
    }
}
 
 
int main()
{
    io;
    ll test_case;
    //cin>>test_case;
    test_case=1;
    while(test_case--)
    {
        cin>>n>>m;
 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            cin>>rooms[i][j];
        }
        
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(rooms[i][j]=='.' && vis[i][j]==false)
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        print(cnt);
    }
}
