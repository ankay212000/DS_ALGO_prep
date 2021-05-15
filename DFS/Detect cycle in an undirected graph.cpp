bool isVisited[100001];
    void initialise()
    {
        memset(isVisited,false,sizeof(isVisited));
    }
    bool dfs(int child,int parent,vector<int> adj[])
    {
        isVisited[child]=true;
        for(auto x: adj[child])
        {
            if(!isVisited[x])
            {
                if(dfs(x,child,adj))
                {
                    return true;
                }
            }    
            else if(x!=parent)
            return true;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    initialise();
	    for(int i=0;i<V;i++)
	    {
	        if(!isVisited[i])
	        {
	            if(dfs(i,i,adj))
	            {
	                return true;
	            }
	        }     
	    }     
	    return false;
	}
