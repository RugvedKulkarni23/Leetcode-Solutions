class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
          vector<int> answer(arr.size(),-1);
        
          int maxvalue = arr[arr.size()-1];
          int n = arr.size();
          for(int i= n-2;i>=0;i--){
               maxvalue = max(maxvalue,arr[i+1]);
              answer[i] = maxvalue;
          }
        
        return answer;
    }
};