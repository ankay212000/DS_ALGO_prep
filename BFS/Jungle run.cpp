    #include<bits/stdc++.h>
    #define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    using namespace std;
    #define inf INT_MAX
     
    char jungle[31][31];
    bool vis[31][31];
    int dis[31][31];
    int n;
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
     
    bool isValid(int x,int y)
    {
    	if(x>=n||x<0||y>=n||y<0)
    	return false;
    	else if(vis[x][y]==true||jungle[x][y]=='T')
    	return false;
     
    	return true;
    }
     
    void bfs(int x,int y)
    {
    	queue<pair<int,int>> q;
    	dis[x][y]=0;
        vis[x][y]=true;
    	q.push({x,y});
     
    	while(!q.empty())
    	{
    		int currX=q.front().first;
    		int currY=q.front().second;
            //cout<<currX<<" "<<currY<<"\n";
    		q.pop();
    		for(int i=0;i<4;i++)
    		{
                //cout<<currX<<" "<<currY<<" ";
                //cout<<isValid(currX+dx[i],currY+dy[i])<<" "<<currX+dx[i]<<" "<<currY+dy[i]<<" "<<jungle[currX+dx[i]][currY+dy[i]]<<" "<<vis[currX+dx[i]][currY+dy[i]]<<"\n";
    			if(isValid(currX+dx[i],currY+dy[i]))
    			{
                    int newX=currX+dx[i];
    			    int newY=currY+dy[i];
    				vis[newX][newY]=true;
    				dis[newX][newY]=dis[currX][currY]+1;
    				q.push({newX,newY});
    			}
    		}
    	}
    }
     
    int main()
    {
        io;
    	cin>>n;
     
    	int srcx,srcy,tarx,tary;
     
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			cin>>jungle[i][j];
    			if(jungle[i][j]=='S')
    			srcx=i,srcy=j;
    			else if(jungle[i][j]=='E')
    			tarx=i,tary=j;
     
    		}	
    	}
     
    	
     
        //cout<<srcx<<" "<<srcy<<"\n";
    	bfs(srcx,srcy);
    	cout<<dis[tarx][tary];
    }
