#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

template <typename T>
void print(T x){cout<<x<<"\n";}

int chess[8][8];
bool vis[8][8];
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,2,-2,-2,2,-1,1};

bool isValid(int x,int y)
{
	if(x>=8||y>=8||x<0||y<0)
	return false;
	else if(vis[x][y]==true)
	return false;

	return true;
}

void bfs(int x,int y,int tx,int ty)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	chess[x][y]=0;
	vis[x][y]=true;

	while(!q.empty())
	{
		int currX=q.front().first;
		int currY=q.front().second;

		q.pop();
		for(int i=0;i<8;i++)
		{
			if(isValid(currX+dx[i],currY+dy[i]))
			{
				int newX=currX+dx[i];
				int newY=currY+dy[i];
				chess[newX][newY]=chess[currX][currY]+1;
				vis[newX][newY]=true;
				q.push({newX,newY});
			}
		}
	}
}

int main()
{
	ll test_case;
	cin>>test_case;
	while(test_case--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int sy=s1[0]-'a',sx=s1[1]-'1',ty=s2[0]-'a',tx=s2[1]-'1';

		bfs(sx,sy,tx,ty);
		print(chess[tx][ty]);

		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			chess[i][j]=0,vis[i][j]=0;
		}
	}
}
