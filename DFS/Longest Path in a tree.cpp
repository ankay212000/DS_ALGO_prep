    #include<bits/stdc++.h>
    #define int long long
    #define io ios_base::sync_with_stdio(false);cin.tie(NULL);
    #define N 100000
    #define mod 1000000007
    using namespace std;
     
    template <typename T>
    void print(T x){cout<<x<<"\n";}
    template <typename T1, typename T2>
    void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
    template <typename T1, typename T2,typename T3>
    void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}
     
    vector<int> adj[N+1];
    bool visited[N+1];
    int maxD,maxNode;
     
    void dfs(int n,int d)
    {
        visited[n]=true;
        //cout<<d<<"\n";
        if(d>maxD) maxD=d,maxNode=n;
        for(auto x: adj[n])
        {
          if(!visited[x])
          dfs(x,d+1);
        }
        
    }
     
    signed main()
    {
        io;
        int test_case;
        //cin>>test_case;
        test_case=1;
        for(int i=1;i<=test_case;i++)
        {
            int n;
            cin>>n;
     
            int a,b;
            for(int i=0;i<n-1;i++)
            {
              cin>>a>>b;
              adj[a].push_back(b);
              adj[b].push_back(a);
            }
            maxD=-1;
            dfs(1,0);
            //cout<<maxD<<"\n";
            maxD=-1;
            //cout<<maxNode<<"\n";
            for(int i=1;i<N+1;i++) visited[i]=0;
            dfs(maxNode,0);
            print(maxD);
        }   
    } 
