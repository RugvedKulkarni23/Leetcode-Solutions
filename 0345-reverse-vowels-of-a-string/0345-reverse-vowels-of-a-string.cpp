class Solution {
public: 
    bool isvowel(char ch){
              
          ch = tolower(ch);
         return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';            
    }
    string reverseVowels(string s) {
            
         int left = 0;
         int right = s.size()-1;
        
         while(left<right){
             
                if(!isvowel(s[left])){
                     left++;
                }
              else  if(!isvowel(s[right])){
                     right--;
                }
             
             else if(left<right){
                  swap(s[left],s[right]);
                 left++;
                 right--;
             }
         }
        
        return s;
    }
};