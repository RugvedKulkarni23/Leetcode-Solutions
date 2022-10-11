class Solution {
    private:
       void solve(string digits,string output,int index,vector<string> &answer, string mapping[]){
           // base case 
           if(index>=digits.length()){
               answer.push_back(output);
               return;
           }
           int number = digits[index]- '0';
           string value = mapping[number];
           for(int i=0;i<value.length();i++){
               output.push_back(value[i]);
               solve(digits,output,index+1,answer,mapping);
               output.pop_back();
           }
       }
public:
    vector<string> letterCombinations(string digits) {
         vector<string> answer;
         if(digits.length()==0){
             return answer;
         }
          string output = "";
          int index = 0;
          string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
          solve(digits,output,index,answer,mapping);
          return answer;
              
    }
};