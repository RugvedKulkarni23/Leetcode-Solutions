class Solution {
    struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
        return hash1;
    }
};
public:
    unordered_map<string, vector<string>> map;
    unordered_map<pair<string, string>, double, hash_pair> ratio;
    double helper(string& s1, string& s2, set<string>& vis){
        if(s1==s2) return 1.0;
        vis.insert(s1);
        for(auto it:map[s1]){
            if(!vis.count(it)){
                double temp=helper(it, s2, vis);
                if(temp!=-1){
                    return temp*ratio[{s1, it}];
                }}
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(auto it: equations){
            map[it[0]].push_back(it[1]);
            map[it[1]].push_back(it[0]);
        }
        for(int i=0;i<equations.size();i++){
            ratio[{equations[i][0], equations[i][1]}]=values[i];
            ratio[{equations[i][1], equations[i][0]}]=1/values[i];
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            if(!map.count(queries[i][0]) || !map.count(queries[i][1])){
                ans.push_back(-1);
                continue;
            }
            set<string> vis;
            ans.push_back(helper(queries[i][0], queries[i][1], vis));
        }
        return ans;

    }
};