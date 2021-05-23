class Solution {
public:
    
    bool canReach(string s, int minjump, int maxjump) {
        int maxreach=0;
        queue<int> q;
        q.push(0);
        int n=s.size();
        
        while(!q.empty())
        {
            int curr=q.front();
            if(curr==n-1)
                return true;
            q.pop();
            
            for(int i=max(maxreach,curr+minjump);i<=min(n-1,curr+maxjump);i++)
                if(s[i]=='0')
                    q.push(i);
           
            maxreach=max(maxreach,curr+maxjump);
        }
        
        return false;
    }
};
