#include<bits/stdc++.h>
using namespace std;

bool isVisited[100001];
vector<int> node[100001],trans[100001];
vector<int> scc,order;

void dfs(int par)
{
	isVisited[par]=true;
	//cout<<par<<"\n";
	for(auto x: node[par])
	if(!isVisited[x])
	dfs(x);

	order.push_back(par);
}

void dfs1(int par)
{
	isVisited[par]=true;
	//cout<<par<<" ";
	for(auto x: trans[par])
	if(!isVisited[x])
	dfs1(x);

	scc.push_back(par);
}


int main()
{
	int n,m;
	cin>>n>>m;

	vector<int> res(n+1);
	fill(res.begin(),res.end(),0);

	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		node[a].push_back(b);
		trans[b].push_back(a);
	}

	for(int i=1;i<=n;i++)
	{
		if(!isVisited[i])
		dfs(i);
	}

	memset(isVisited,false,sizeof(isVisited));

    reverse(order.begin(),order.end());
	for(auto i:order)
	{
		if(!isVisited[i])
		{
			scc.clear();
			dfs1(i);
			if(scc.size()==1) continue;
			for(auto x: scc)
			res[x]=1;
		}
	}
	for(int i=1;i<=n;i++)
	cout<<res[i]<<" ";
}
