#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#define N 1000000
#define limit 10000
#define mod 1000000007
#define pb push_back


template <typename T>
void print(T x){cout<<x<<"\n";}
template <typename T1, typename T2>
void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
template <typename T1, typename T2,typename T3>
void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}

int n,m;
int grid[101][101],dist[101][101];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void initialise()
{
    for(int i=0;i<=101;i++)
        for(int j=0;j<=101;j++)
            dist[i][j]=INT_MAX;
}


bool isValid(int x,int y)
{
    if(x>n||y>m||x<1||y<1)
    return false;

    return true;
}

void bfs(int x, int y)
{
    queue<pair<int,int>> q;
    dist[x][y]=grid[x][y];
    
    q.push({x,y});

    while(!q.empty())
    {
        int currX=q.front().first;
        int currY=q.front().second;

        q.pop();
        for(int i=0;i<4;i++)
        {
            int newX=currX+dx[i];
            int newY=currY+dy[i];
            if(isValid(newX,newY)&&dist[newX][newY]>grid[newX][newY]+dist[currX][currY])
            {
                dist[newX][newY]=grid[newX][newY]+dist[currX][currY];
                q.push({newX,newY});
            }
        }
    }
}


int main()
{
    ll test_case;
    cin>>test_case;
    //test_case=1;
    while(test_case--)
    {
        initialise();
        cin>>n>>m;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            cin>>grid[i][j];
        }

        int tx,ty,time;
        cin>>tx>>ty>>time;

        bfs(1,1);

        if(dist[tx][ty]<=time)
        {
            print("YES");
            print(time-dist[tx][ty]);
        }
        else
        print("NO");
    }
}
