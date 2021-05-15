int isVisited[100001];
    void initialise()
    {
        memset(isVisited,0,sizeof(isVisited));
    }
    bool dfs(int child,vector<int> adj[])
    {
        isVisited[child]=1;
        for(auto x: adj[child])
        {
            if(isVisited[x]==1)
            return true;
            
            if(isVisited[x]==0&&dfs(x,adj))
            return true;
        }
        isVisited[child]=2;
        return false;
    }
	bool isCyclic(int V, vector<int>adj[])
	{
	    initialise();
	    for(int i=0;i<V;i++)
	    {
	        //initialise();
	        if(isVisited[i]==0)
	        {
	            if(dfs(i,adj))
	            {
	                return true;
	            }
	        }     
	    }
	    //return dfs(2,2,adj);
	    return false;
	}
