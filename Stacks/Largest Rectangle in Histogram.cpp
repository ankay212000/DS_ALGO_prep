class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> back,front;
        int n=h.size();
        if(n==0)
            return 0;
        
        int area[n];
        for(int i=0;i<n;i++)
        {
            while(back.empty()==false&&h[back.top()]>=h[i])
                back.pop();
            area[i]=back.empty()?(i+1):(i-back.top());
            back.push(i);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(front.empty()==false&&h[front.top()]>h[i])
                front.pop();
            if(front.empty())
                area[i]+=(n-i-1);
            else
                area[i]+=(front.top()-i-1);
            front.push(i);
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
            ans=max(ans,area[i]*h[i]);
        return ans;
    }
};
