class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int answer = INT_MIN;
        int presum = 0;
        
        for(int i=0;i<gain.size();i++){
            answer = max(presum,answer);
            presum += gain[i];
        }
        
        if(presum>answer){
            answer= presum;
        }
        
        return answer;
    }
};