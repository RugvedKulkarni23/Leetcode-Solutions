class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        string answer = s+s;
        int res = answer.find(s,1);
        if(res<s.size() && res!= string:: npos){
              return true;
        }
        return false;
    }
};