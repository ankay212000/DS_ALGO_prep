void generate(string s,vector<string> &res,string temp="",int start=-1)
	    {
	        if(start==s.size())
	        {
	            return ;
	        }
	        
	        if(temp.size()!=0)
	        res.push_back(temp);
	        for(int i=start+1;i<s.size();i++)
	        {
	            temp+=s[i];
	            generate(s,res,temp,i);
	            temp.erase(temp.size()-1);
	        }
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string> res;
		    generate(s,res);
		    sort(res.begin(),res.end());
		    return res;
	}
