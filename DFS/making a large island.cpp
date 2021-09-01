class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int dfs(int i,int j,vector<vector<int>>& grid,int index)
    {
        grid[i][j]=index;
        int cnt=1;
        int n=grid.size();
        for(int p=0;p<4;p++)
        {
            if(i+dx[p]>=0&&i+dx[p]<n&&j+dy[p]>=0&&j+dy[p]<n&&grid[i+dx[p]][j+dy[p]]==1)
                cnt+=dfs(i+dx[p],j+dy[p],grid,index);
        }
        return cnt;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int index=-1;
        int n=grid.size();
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    mp[index]=dfs(i,j,grid,index),index--;
            }
        }
        
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    int cnt=1;
                    unordered_map<int,int> vis;
                    for(int p=0;p<4;p++)
                    {
                        if(i+dx[p]>=0&&i+dx[p]<n&&j+dy[p]>=0&&j+dy[p]<n)
                        {
                            int ind=grid[i+dx[p]][j+dy[p]];
                            if(vis.find(ind)==vis.end())
                            {
                                cnt+=mp[ind];
                                vis[ind]=1;
                            }
                        }
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        if(ans==INT_MIN)
            return n*n;
        return ans;
    }
};
