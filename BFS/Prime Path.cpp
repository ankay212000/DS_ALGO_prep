    #include<bits/stdc++.h>
    #define int long long
    #define io ios_base::sync_with_stdio(false);cin.tie(NULL);
    #define N 10000
    using namespace std;
     
    template <typename T>
    void print(T x){cout<<x<<"\n";}
    template <typename T1, typename T2>
    void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
    template <typename T1, typename T2,typename T3>
    void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}
     
     
    bool isprime[N+1];
    vector<int> primes;
    vector<int> adj[N+1];
    int dist[N+1];
    bool visited[N+1];
     
    void sieve()
    {
    	for(int i=2;i*i<=N;i++)
    	{
    		if(!isprime[i])
    		for(int j=2*i;j<=N;j+=i)
    			isprime[j]=true;
    	}
     
    	for(int i=1000;i<=9999;i++)
    	if(!isprime[i])
    	primes.push_back(i);
    }
     
    bool is1digit(int a,int b)
    {
    	int cnt=0;
    	while(a&&b)
    	{
    		if(a%10!=b%10)
    		cnt++;
     
    		a/=10;
    		b/=10;
    	}
    	return cnt==1?true:false;
    }
     
    void connect()
    {
    	for(int i=0;i<primes.size();i++)
    	{
    		for(int j=i+1;j<primes.size();j++)
    		if(is1digit(primes[i],primes[j]))
    		adj[primes[i]].push_back(primes[j]),adj[primes[j]].push_back(primes[i]);
    	}
    }
     
    void bfs(int start,int end)
    {
    	queue<int> node;
    	node.push(start);
    	dist[start]=0;
    	visited[start]=true;
     
    	while(!node.empty())
    	{
    		int p=node.front();
    		node.pop();
    		for(auto x: adj[p])
    		if(!visited[x])
    		node.push(x),visited[x]=true,dist[x]=dist[p]+1;
    	}
     
    	if(dist[end]==-1)
    	print("Impossible");
    	else
    	print(dist[end]);
    }
     
     
    signed main()
    {
        io;
    	sieve();
    	connect();
        int test_case;
        cin>>test_case;
        //test_case=1;
        while(test_case--)
        {
    		for(int i=0;i<=N;i++) visited[i]=0,dist[i]=-1;
            int start,end;
    		cin>>start>>end;
    		
    		bfs(start,end);
    		
        }   
    } 
