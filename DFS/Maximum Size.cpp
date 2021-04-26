#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define mod 1000000007
#define pb push_back


template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}


void initialise(vector<vector<bool>> &arr,int n,int m)
{
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            arr[i].pb(false);
}

bool isValid(int x,int y,int n,int m,vector<vector<bool>> &isVisited,vector<vector<int>> &grid)
{
    if(x>n||y>m||x<1||y<1)
    return false;
    else if(isVisited[x][y]||grid[x][y]==0)
    return false;

    return true;
}

int dfs(vector<vector<int>> &grid,int x,int y,vector<vector<bool>> &isVisited,int n,int m)
{
    isVisited[x][y]=true;
    int cnt=1;

    if(isValid(x+1,y,n,m,isVisited,grid))
    cnt+=dfs(grid,x+1,y,isVisited,n,m);

    if(isValid(x,y+1,n,m,isVisited,grid))
    cnt+=dfs(grid,x,y+1,isVisited,n,m);
    
    if(isValid(x-1,y,n,m,isVisited,grid))
    cnt+=dfs(grid,x-1,y,isVisited,n,m);

    if(isValid(x,y-1,n,m,isVisited,grid))
    cnt+=dfs(grid,x,y-1,isVisited,n,m);

    return cnt;
}

int main()
{
    ll test_case;
    cin>>test_case;
    //test_case=1;
    while(test_case--)
    {
        int n,m;
        cin>>n>>m;

        vector<vector<int>> grid(n+1);
        vector<vector<bool>> isVisited(n+1);

        initialise(isVisited,n,m);

        string a;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            grid[i].pb(-1);
        }

        for(int i=1;i<=n;i++)
        {
            cin>>a;
            for(int j=0;j<a.size();j++)
            grid[i][j+1]=a[j]-'0';
        }

        vector<int> scores;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(isVisited[i][j]==false&&grid[i][j]==1)
                scores.pb(dfs(grid,i,j,isVisited,n,m));
            }
        }
        
        sort(scores.begin(),scores.end(),greater<int>());
        
        int res=0;
        for(int i=1;i<scores.size();i+=2)
        res+=scores[i];

        cout<<res<<"\n";
    }
}
