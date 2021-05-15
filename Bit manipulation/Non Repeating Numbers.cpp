vector<int> singleNumber(vector<int> nums) 
    {
        int Xor=0;
        for(auto x:nums)
        Xor^=x;
        
        int set_bit=(Xor)&(~(Xor-1));
        vector<int> ans(2);
        for(auto x:nums)
        {
            if(x&set_bit)
            ans[0]^=x;
            else
            ans[1]^=x;
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
