class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> nodes[]) 
	{
	    vector<int> inorder(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto x: nodes[i])
	        inorder[x]++;
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    if(inorder[i]==0)
	        q.push(i);
	    
	    vector<int> res;
	    while(!q.empty())
	    {
	        int curr=q.front();
	        //cout<<curr<<"\n";
	        res.push_back(curr);
	        q.pop();
	        
	        for(auto x: nodes[curr])
	        {
	            inorder[x]--;
	            if(inorder[x]==0)
	            q.push(x);
	        }
	    }
	    return res;
	}
};
