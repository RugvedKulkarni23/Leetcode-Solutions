class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>>ans;

        
        for(auto currentInterval:intervals){
        
        if(currentInterval[1]<newInterval[0]){ans.push_back(currentInterval);}
       
        else if(newInterval[1]<currentInterval[0]){
                    ans.push_back(newInterval);
                    
                    newInterval = currentInterval;
        }
       
        else{
           
            newInterval[0] = min(currentInterval[0],newInterval[0]);
            newInterval[1] = max(currentInterval[1],newInterval[1]);

        }

        }
        
        ans.push_back(newInterval);

        return ans;
    }
};