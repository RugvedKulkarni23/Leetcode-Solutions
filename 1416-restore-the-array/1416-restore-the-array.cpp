class Solution {
public:
    int mod = 1e9+7;
    int dp[100001];
    int helper(string&s,int &k,int i)
    {
        
        if(i==s.size())
        {
            return 1;
        }
        
        if(i>s.size())
        {
            return 0;
        }
      
        if(dp[i]!=-1)
        {
            return dp[i];
        }
       
        int res = 0;
       
        unsigned long long int num = 0;
        
        for(int start=i;start<s.size();start++)
        {
          
            int digit = (int(s[start])-48);
            num = num*10+digit;
           
            if(num > k)
                break;
            
            if(s[start+1]!='0' && num<=k)
            {
               
                res = (res%mod + helper(s,k,start+1)%mod)%mod;
            }
        }
        return dp[i] = res%mod;
    }
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(s,k,0)%mod;
    }
};