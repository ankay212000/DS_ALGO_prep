    #include<bits/stdc++.h>
    #define int long long
    #define io ios_base::sync_with_stdio(false);cin.tie(NULL);
    #define N 100000
    using namespace std;
     
    template <typename T>
    void print(T x){cout<<x<<"\n";}
    template <typename T1, typename T2>
    void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
    template <typename T1, typename T2,typename T3>
    void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}
     
    vector<int> adj[N+1];
    bool visited[N+1];
     
    void dfs(int n)
    {
        visited[n]=true;
        for(auto x: adj[n])
        {
            if(!visited[x])
            dfs(x);
        }
    }
     
    signed main()
    {
        io;
        int test_case;
        //cin>>test_case;
        test_case=1;
        while(test_case--)
        {
            int n,m;
            cin>>n>>m;
     
            int a,b;
            for(int i=0;i<m;i++)
            {
              cin>>a>>b;
              adj[a].push_back(b);
              adj[b].push_back(a);
            }
     
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
              if(!visited[i])
              dfs(i),cnt++;
            }
            if(cnt==1&&m==n-1)
            print("YES");
            else
            print("NO");
        }   
    } 
