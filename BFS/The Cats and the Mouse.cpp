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
char grid[101][101];
int distCat[101][101],distMouse[101][101];
bool isVisited[101][101];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void initialise()
{
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
        distCat[i][j]=INT_MAX,distMouse[i][j]=INT_MAX,isVisited[i][j]=false;
    }
}

bool isValidCat(int x,int y)
{
    if(x>n||y>m||x<1||y<1)
    return false;
    
    return true;
}

bool isValidMouse(int x,int y)
{
    if(x>n||y>m||x<1||y<1)
    return false;
    else if(isVisited[x][y]==true)
    return false;

    return true;
}

void bfsCat(int x,int y)
{
    queue<pair<int,int>> q;
    distCat[x][y]=0;
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

            if(isValidCat(newX,newY)&&distCat[newX][newY]>distCat[currX][currY]+1&&grid[newX][newY]!='c')
            {
                distCat[newX][newY]=distCat[currX][currY]+1;
                q.push({newX,newY});
            }
        }
    }
}


void bfsMouse(int x,int y)
{
    queue<pair<int,int>> q;
    distMouse[x][y]=0;
    isVisited[x][y]=true;
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

            if(isValidMouse(newX,newY))
            {
                distMouse[newX][newY]=distMouse[currX][currY]+1;
                q.push({newX,newY});
                isVisited[newX][newY]=true;
            }
        }
    }
}

bool isEscape()
{
    for(int i=1;i<=n;i++)
    {
        if(distMouse[i][1]<distCat[i][1]||distMouse[i][m]<distCat[i][m])
        return true;
    }
    for(int j=1;j<=m;j++)
    {
        if(distMouse[1][j]<distCat[1][j]||distMouse[n][j]<distCat[n][j])
        return true;
    }

    return false;
}


int main()
{
    cin>>n>>m;

    ll test_case;
    cin>>test_case;
    //test_case=1;
    while(test_case--)
    {
        initialise();
        int cat1x,cat1y,mouse_x,mouse_y,cat2x,cat2y;
        cin>>mouse_x>>mouse_y>>cat1x>>cat1y>>cat2x>>cat2y;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            grid[i][j]='a';
        }

        distCat[cat1x][cat1y]=0;
        distCat[cat2x][cat2y]=0;
        distMouse[mouse_x][mouse_y]=0;
        grid[cat1x][cat1y]='c';
        grid[cat2x][cat2y]='c';
        grid[mouse_x][mouse_y]='m';

        bfsCat(cat1x,cat1y);
        bfsCat(cat2x,cat2y);
        bfsMouse(mouse_x,mouse_y);

        /*cout<<"Mouse: \n";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            cout<<distMouse[i][j]<<" ";
            cout<<"\n";
        }
        
        cout<<"\nCat: \n";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            cout<<distCat[i][j]<<" ";
            cout<<"\n";
        }

        cout<<"\n";*/

        if(isEscape())
        print("YES");
        else
        print("NO");
    }
}
