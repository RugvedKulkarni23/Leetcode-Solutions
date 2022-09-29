class Solution {
public:
    bool checkIfPangram(string sentence) {
          set <char> pangram;
          for(int i=0;i<sentence.length();i++){
              pangram.insert(sentence[i]);
          }
        if(pangram.size()==26){
            return true;
        }
        return false;
    }
};