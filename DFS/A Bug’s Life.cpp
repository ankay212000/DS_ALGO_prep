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
    int col[N+1];
     
    bool dfs(int n,int c)
    {
        visited[n]=true;
        col[n]=c;
        for(auto x: adj[n])
        {
            if(!visited[x])
            {
              if(!dfs(x,c^1))
              return false;
            }
            else if(col[n]==col[x])
            return false;
        }
        return true;
    }
     
    signed main()
    {
        io;
        int test_case;
        cin>>test_case;
        //test_case=1;
        for(int i=1;i<=test_case;i++)
        {
            cout<<"Scenario #"<<i<<":\n";
            int n,m;
            cin>>n>>m;
     
            int a,b;
            for(int i=0;i<m;i++)
            {
              cin>>a>>b;
              adj[a].push_back(b);
              adj[b].push_back(a);
            }
            bool flag=false;
            for(int i=1;i<=n;i++)
            {
              if(!visited[i])
              if(!dfs(i,0))
              {
                print("Suspicious bugs found!");
                flag=true;
                break;
              }  
            }
            if(!flag)
            print("No suspicious bugs found!");
     
            for(int i=1;i<=N;i++) adj[i].clear();
            for(int i=1;i<=N;i++) visited[i]=0,col[i]=0;
        }   
    } 
