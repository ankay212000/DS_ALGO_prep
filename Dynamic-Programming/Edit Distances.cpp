int editDistance(string s, string t) {
        
        int dp[t.size()+1][s.size()+1];
        
        for(int i=0;i<=t.size();i++)
        dp[i][0]=i;
        for(int i=0;i<=s.size();i++)
        dp[0][i]=i;
        
        
        for(int i=1;i<=t.size();i++)
        {
            for(int j=1;j<=s.size();j++)
            {
                if(t[i-1]==s[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        
        return dp[t.size()][s.size()];
    }
