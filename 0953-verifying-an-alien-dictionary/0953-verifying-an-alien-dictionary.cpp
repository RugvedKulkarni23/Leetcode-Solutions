class Solution {
public:
    unordered_map<char, int> m;
    bool compare(string one, string two){
        int n = min(one.length(), two.length());
        for(int i=0;i<n;i++){
            if(m[one[i]]<m[two[i]]) return true;
            else if(m[one[i]]>m[two[i]]) return false;
        }
        if(one.size()>two.size()) return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.length();i++){
            m[order[i]] = i+1;
        }
        for(int i=0; i<words.size()-1;i++){
            bool ans = compare(words[i], words[i+1]);
            if(ans==false) return false;
        }
        return true;

    }
};