#include <bits/stdc++.h>
using namespace std;

int indegree[100001];
vector<int> nodes[100001];

bool bfs(int n)
{
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    
    vector<int> res;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        res.push_back(curr);
        
        for(auto x: nodes[curr])
        {
            if(indegree[x]!=0)
            {
                indegree[x]--;
                if(indegree[x]==0)
                q.push(x);
            }
        }
    }
    
    
    
    if(res.size()==n)
    return true;
    return false;
}


int main() {
	int n,e;
	cin>>n>>e;
	int a,b;
	for(int i=0;i<e;i++)
	{
	    cin>>a>>b;
	    nodes[a].push_back(b);
	    indegree[b]++;
	}
	
	cout<<bfs(n)<<"\n";
	return 0;
}
