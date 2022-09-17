class Solution {
public:
    
    void reverse(vector<char> &str,int i,int j){
        if(i>j){
            return;
        }
        swap(str[i],str[j]);
        i++;
        j--;
        reverse(str,i,j);
    }
    void reverseString(vector<char>& s) {
        reverse(s,0,s.size()-1);
        
    }
};