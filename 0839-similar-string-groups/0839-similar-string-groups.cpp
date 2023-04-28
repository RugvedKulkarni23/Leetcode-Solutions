class Solution {
public:
    bool areSame(vector<string>&strs, int i, int j){
        int count = 0;
        for(int k = 0; k<strs[i].size(); k++){
            if(strs[i][k] != strs[j][k]) count++;
            if(count > 2) return false;
        }

        return count<=2;
    }
    void dfs(vector<string>&strs, int index, vector<bool>&vs){
        vs[index] = false;
        for(int i = 0; i<strs.size(); i++){
            if(vs[i] && (strs[index] == strs[i] || areSame(strs, index, i))){
                dfs(strs,i, vs);
            }
        }

    }
    int numSimilarGroups(vector<string>& strs) {
        
        vector<bool>vs(strs.size(), true);
        int count = 0;
        for(int i = 0; i<strs.size(); i++){
            if(vs[i]){
                count++;
                dfs(strs, i, vs);
            }
        }

        return count;
    }
};