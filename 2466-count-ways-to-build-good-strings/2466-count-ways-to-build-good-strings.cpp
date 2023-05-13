class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(high + 1, 0);
        dp[0] = 1;
        long long ans = 0;
        long long MOD = 1000000007;
        for (int len = 1; len <= high; len++)
        {
            int prevZeroLen = len - zero;
            long long zeroWays = (prevZeroLen < 0)? 0 : dp[prevZeroLen];
            
            int prevOneLen = len - one;
            long long oneWays = (prevOneLen < 0)? 0 : dp[prevOneLen];
            
            dp[len] = (zeroWays + oneWays) % MOD;
            if (len >= low) ans = (ans + dp[len]) % MOD;
        }
        return ans;
    }
};