void generate(string s,vector<string> &res)
	    {
	        int power=pow(2,s.size());
	        for(int i=0;i<power;i++)
	        {
	            string temp="";
	            for(int j=0;j<s.size();j++)
	            {
	                if((i>>j)&1)
	                temp.push_back(s[j]);
	            }
	            if(temp.size()>0)
	            res.push_back(temp);
	        }
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string> res;
		    generate(s,res);
		    sort(res.begin(),res.end());
		    return res;
