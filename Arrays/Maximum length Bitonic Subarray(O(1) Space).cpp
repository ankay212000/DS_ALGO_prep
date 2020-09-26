int bitonic(int *arr, int n) {
	    int start=0,start2=0;
	    int j=start;
	    int ans=1;
	    while(j<n-1)
	    {
	       while(j<n-1&&arr[j]<=arr[j+1])
	       j++;
	       
	       while(j<n-1&&arr[j]>=arr[j+1])
	       {
	            if(j<n-1&&arr[j]>arr[j+1])   
	            start2=j+1;
	            
	           j++; 
	       }
	       ans=max(ans,j-(start-1));
	       start=start2;
	    }    
	   return ans;   
	}
