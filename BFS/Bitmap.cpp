    #include<bits/stdc++.h>
    #define ll long long
    #define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    using namespace std;
    #define N 1000000
    #define limit 10000
    #define mod 1000000007
    #define pb push_back
     
     
    template <typename T>
    void print(T x){cout<<x<<"\n";}
    template <typename T1, typename T2>
    void print2(T1 x,T2 y){cout<<x<<" "<<y<<"\n";}
    template <typename T1, typename T2,typename T3>
    void print3(T1 x, T2 y,T3 z){cout<<x<<" "<<y<<" "<<z<<"\n";}
     
    int n,m;
    int matrix[200][200],dist[200][200];
     
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
     
    void initialise()
    {
        for(int i=0;i<=200;i++)
        for(int j=0;j<=200;j++)
        dist[i][j]=INT_MAX;
     
    }
     
    bool isValid(int x,int y)
    {
        if(x>n||y>m||x<1||y<1)
        return false;
     
        return true;
    }
     
    void bfs(int srcx,int srcy)
    {
        queue<pair<int,int>> q;
        dist[srcx][srcy]=0;                                 
        q.push({srcx,srcy});
     
        //cout<<srcx<<" "<<srcy<<"\n";
        ll cnt=0;
        while(!q.empty())
        {
            int currx=q.front().first;
            int curry=q.front().second;
            q.pop();
     
            //cout<<currx<<" "<<curry<<"\n";
            for(int i=0;i<4;i++)
            {
                //cout<<currx+dx[i]<<" "<<curry+dy[i]<<"\n";
                if(isValid(currx+dx[i],curry+dy[i])&&dist[currx+dx[i]][curry+dy[i]]>dist[currx][curry]+1&&matrix[currx+dx[i]][curry+dy[i]]==0)
                {
                    int newX=currx+dx[i];
                    int newY=curry+dy[i];
                    //cout<<currx+dx[i]<<" "<<curry+dy[i]<<"\n";
                    dist[newX][newY]=dist[currx][curry]+1;
                    q.push({newX,newY});
                }
            }
        }
    }
     
     
    int main()
    {
        ll test_case;
        cin>>test_case;
        //test_case=1;
        while(test_case--)
        {
            initialise();
            cin>>n>>m;
            vector<pair<int,int>> ones;
            string s;
            ll x,y;
            for(int i=1;i<=n;i++)
            {
                cin>>s;
                for(int j=0;j<s.size();j++)
                {
                    matrix[i][j+1]=s[j]-'0';
                    if(matrix[i][j+1]==1)
                    ones.pb({i,j+1});
                }    
            }
     
            //cout<<ones.size()<<"\n";
            for(int i=0;i<ones.size();i++)
            {
                x=ones[i].first;
                y=ones[i].second;
                bfs(x,y);
                //cout<<"\n";
            }    
     
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                cout<<dist[i][j]<<" ";
                cout<<"\n";
            }   
        }
    } 
