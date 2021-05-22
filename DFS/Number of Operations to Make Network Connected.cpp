bool isVisited[100000];
    vector<int> nodes[100000];
    
    void dfs(int i)
    {
        isVisited[i]=true;
        for(auto x: nodes[i])
        {
            if(!isVisited[x])
                dfs(x);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cnt=0;
        for(int i=0;i<connections.size();i++)
        {
            nodes[connections[i][0]].push_back(connections[i][1]);
            nodes[connections[i][1]].push_back(connections[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!isVisited[i])
                dfs(i),cnt++;
        }
        
        int min_edges=connections.size()-n+cnt;
        if(min_edges>=cnt-1)
            return cnt-1;
        else
            return -1;
    }
