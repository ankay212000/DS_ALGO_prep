#include<bits/stdc++.h>
#define N 100000
using namespace std;

bool isVisited[N+1];
vector<int> node[N+1];

void dfs(int parent)
{
	isVisited[parent]=true;
	for(auto x: node[parent])
	if(!isVisited[x])
	dfs(x);
}

int main()
{
	int n,e;
	cin>>n>>e;

	int a,b;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!isVisited[i])
		dfs(i),cnt++;
	}

	cout<<cnt<<"\n";
}
