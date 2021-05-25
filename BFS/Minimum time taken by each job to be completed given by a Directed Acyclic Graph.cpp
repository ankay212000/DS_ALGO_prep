#include <bits/stdc++.h>
using namespace std;

int indegree[100001];
vector<int> nodes[100001];
int times[100001];

void dfs(int n)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            times[i]=1;
            q.push(i);
        }
    }
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto x: nodes[curr])
        {
            if(indegree[x]!=0)
            {
                indegree[x]--;
                if(indegree[x]==0)
                q.push(x),times[x]=times[curr]+1;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    cout<<times[i]<<" ";
    cout<<"\n";
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
	
	dfs(n);
	return 0;
}
