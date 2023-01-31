class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> players(n);
        for(int i=0; i<n ;i++){
            players[i] = {ages[i], scores[i]};
        }
        sort(players.begin(), players.end());

        vector<int> dp(n);
        int res = 0;
        for(int i=n-1; i>=0; i--){
            int curScore = players[i].second;
            dp[i] = curScore;
            for(int j=i+1; j<n; j++){
                if(players[j].second >= curScore){
                    dp[i] = max(dp[i], curScore + dp[j]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};