bool isValid(int x,int y,int n,vector<vector<int>> m,bool isVisited[][5]){
        if(x<0||x>=n||y<0||y>=n)
        return false;
        else if(isVisited[x][y]||m[x][y]==0)
        return false;
        
        return true;
    }
    
    void dfs(int x,int y,int n,vector<string>&res,vector<vector<int>> m,string temp,bool isVisited[][5]){
        
        if(x<0||x>=n||y<0||y>=n)
        return ;
        if(isVisited[x][y]||m[x][y]==0)
        return ;
        
        if(x==n-1&&y==n-1)
        {
            res.push_back(temp);
            return ;
        }
        
        isVisited[x][y]=true;
        if(isValid(x+1,y,n,m,isVisited))
        temp.push_back('D'),dfs(x+1,y,n,res,m,temp,isVisited),temp.pop_back();
        
        if(isValid(x,y-1,n,m,isVisited))
        temp.push_back('L'),dfs(x,y-1,n,res,m,temp,isVisited),temp.pop_back();
        
        if(isValid(x,y+1,n,m,isVisited))
        temp.push_back('R'),dfs(x,y+1,n,res,m,temp,isVisited),temp.pop_back();
        
        if(isValid(x-1,y,n,m,isVisited))
        temp.push_back('U'),dfs(x-1,y,n,res,m,temp,isVisited),temp.pop_back();
        
        isVisited[x][y]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        string temp;
        bool isVisited[n][5];
        memset(isVisited,false,sizeof(isVisited));
        dfs(0,0,n,res,m,temp,isVisited);
        
        return res;
    }
