class Solution {
public:
    vector<int> sumZero(int n) {
         vector<int> answer;
         int x = n/2;
         while(x>0){
             answer.push_back(x);
             answer.push_back(-x);
             x--;
         }
        if(n%2!=0)
            answer.push_back(0);
        
    
        return answer;
    }
};