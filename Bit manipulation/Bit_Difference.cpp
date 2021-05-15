class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        int A_mask[31],B_mask[31];
        
        memset(A_mask,0,sizeof(A_mask));
        memset(B_mask,0,sizeof(B_mask));
        
        for(int i=0;i<31;i++)
        if((a>>i)&1)
        A_mask[i]++;
        
        for(int i=0;i<31;i++)
        if((b>>i)&1)
        B_mask[i]++;
        
        int cnt=0;
        for(int i=0;i<31;i++)
        if(A_mask[i]!=B_mask[i])
        cnt++;
        
        return cnt;
    }
};
