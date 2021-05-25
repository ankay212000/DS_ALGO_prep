class Solution
{
    public:
    //Function to find the number of islands.
    
    bool isValid(int x,int y,vector<vector<char>>& grid,vector<vector<bool>>& isVisited)
    {
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size())
        return false;
        else if(isVisited[x][y]==true||grid[x][y]=='0')
        return false;
        
        return true;
    }
    
    void dfs(int srcx,int srcy,vector<vector<char>>& grid,vector<vector<bool>>& isVisited)
    {
        isVisited[srcx][srcy]=true;
        
        if(isValid(srcx+1,srcy,grid,isVisited))
        dfs(srcx+1,srcy,grid,isVisited);
        
        if(isValid(srcx-1,srcy,grid,isVisited))
        dfs(srcx-1,srcy,grid,isVisited);
        
        if(isValid(srcx,srcy+1,grid,isVisited))
        dfs(srcx,srcy+1,grid,isVisited);
        
        if(isValid(srcx,srcy-1,grid,isVisited))
        dfs(srcx,srcy-1,grid,isVisited);
        
        if(isValid(srcx+1,srcy+1,grid,isVisited))
        dfs(srcx+1,srcy+1,grid,isVisited);
        
        if(isValid(srcx-1,srcy-1,grid,isVisited))
        dfs(srcx-1,srcy-1,grid,isVisited);
        
        if(isValid(srcx+1,srcy-1,grid,isVisited))
        dfs(srcx+1,srcy-1,grid,isVisited);
        
        if(isValid(srcx-1,srcy+1,grid,isVisited))
        dfs(srcx-1,srcy+1,grid,isVisited);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        vector<vector<bool>> isVisited(grid.size(),vector<bool>(grid[0].size(),false));
        int cnt=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(isVisited[i][j]==false&&grid[i][j]=='1')
                dfs(i,j,grid,isVisited),cnt++;
            }
        }
        
        return cnt;
    }
};
