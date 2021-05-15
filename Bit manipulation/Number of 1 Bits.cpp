int setBits(int N) {
        int cnt=0;
        for(int i=0;i<31;i++)
        if((N>>i)&1)
        cnt++;
        
        return cnt;
    }
