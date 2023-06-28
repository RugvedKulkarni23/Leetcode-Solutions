class comp{
public:
    bool operator()(pair<int,double> & a, pair<int, double> & b){
        return a.second < b.second;
    }
};

class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double ans = 0;
        double cur_val = 1;
        unordered_map<int, unordered_map<int, double> > graph;
        for(int i = 0 ; i< succProb.size(); i++){
            graph[edges[i][0]][edges[i][1]] = succProb[i];
            graph[edges[i][1]][edges[i][0]] = succProb[i];
        }
        vector<bool> visited(n, false);
        vector<double> dp(n, 0);
        priority_queue<pair<int,double>, vector<pair<int,double> >, comp >que;
        que.push({start,1});
        dp[start] = 1;
        while(!que.empty()){
            auto tmp = que.top();
            que.pop();
            visited[tmp.first] = 1;
            if(tmp.first == end){
                continue;
            }
            for(auto kv: graph[tmp.first]){
                if(!visited[kv.first]){
                    dp[kv.first] = max(dp[tmp.first]*kv.second, dp[kv.first]);
                    que.push({kv.first,dp[kv.first]});
                }
            }
        }
        return dp[end];
    }
};