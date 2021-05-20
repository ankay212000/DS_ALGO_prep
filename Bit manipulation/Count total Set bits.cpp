int countSetBits(int n)
    {
        if(n<=0) return 0;
        int p=0;
        while(pow(2,p)<=n) p++;
        p--;
        
        return p*(pow(2,p)/2)+(n-pow(2,p)+1)+countSetBits(n-pow(2,p));
    }
