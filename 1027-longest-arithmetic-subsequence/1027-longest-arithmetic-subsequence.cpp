class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
       int n=nums.size();
        vector<unordered_map<int,int>> dp(n);

        if (n <= 2)
        return n;

        int maxLength=2;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){

                int diff=nums[i]-nums[j];

                if(dp[j].count(diff)){
                  dp[i][diff]=dp[j][diff]+1;
                }
                else{
                    dp[i][diff]=2;
                }
            maxLength=max(maxLength,dp[i][diff]);
            }

        }

    return maxLength;
    }
};