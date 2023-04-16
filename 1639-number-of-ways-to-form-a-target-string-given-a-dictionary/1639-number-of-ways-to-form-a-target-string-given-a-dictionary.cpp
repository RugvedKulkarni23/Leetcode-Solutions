class Solution {
public:
     const int M=1e9+7;
    int f(int i,int j,string &t,int l,vector<vector<long long int>> &ct,vector<vector<long long int>> &dp){
        if(j==t.size()) return 1;
        if(i==l) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long int take=((ct[i][t[j]-'a']%M)*(f(i+1,j+1,t,l,ct,dp)%M))%M;
        long long int notake=f(i+1,j,t,l,ct,dp)%M;
        return dp[i][j]=((take%M)+(notake%M))%M;
    }
    int numWays(vector<string>& w, string t) {
        vector<vector<long long int>> ct(w[0].size(),vector<long long int> (26,0));
        for(int i=0;i<w.size();i++){
            for(int j=0;j<w[i].size();j++) ct[j][w[i][j]-'a']++;
        }
        vector<vector<long long int>> dp(w[0].size(),vector<long long int> (t.size(),-1));
        return f(0,0,t,w[0].size(),ct,dp)%M;
    }
};