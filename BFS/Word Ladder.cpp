bool isVisited[5001];
    vector<int> nodes[5001];
    int dist[5001];
    bool isValid(string s,string y)
    {
        int i=0;
        if(s.size()!=y.size())
            return false;
        else{
            int cnt=0;
            while(i<=s.size())
            {
                if(s[i]!=y[i])
                    cnt++;
                i++;
            }
            if(cnt==1)
                return true;
            return false;
        }
    }
    void bfs(int x,int d)
    {
        queue<int> q;
        q.push(x);
        isVisited[x]=true;
        dist[x]=d+1;
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            cout<<curr<<" ";
            for(auto p:nodes[curr])
            {
                if(!isVisited[p])
                {
                    dist[p]=dist[curr]+1;
                    q.push(p);
                    isVisited[p]=true;
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> num;
        int index=1;
        if(count(wordList.begin(),wordList.end(),beginWord)==0)
            wordList.insert(wordList.begin(),beginWord);
        
        for(auto x: wordList)
            num[x]=index++;//cout<<x<<" ";
        //cout<<"\n";
        if(num.find(endWord)==num.end())
             return 0;
        
        
        for(int i=0;i<wordList.size();i++)
        {
            for(int j=i+1;j<wordList.size();j++)
            {
                //cout<<wordList[i]<<" "<<wordList[j]<<" ";
                //cout<<isValid(wordList[i],wordList[j])<<"\n";
                if(isValid(wordList[i],wordList[j]))
                {
                    nodes[num[wordList[i]]].push_back(num[wordList[j]]);
                    nodes[num[wordList[j]]].push_back(num[wordList[i]]);
                }
            }
        }
        //cout<<"\n";
        //memset(dist,INT_MAX,sizeof(dist));
        bfs(num[beginWord],0);
        return dist[num[endWord]];
    }
