class Solution {
public:
    void sortColors(vector<int>& nums) {
            int n = nums.size();
            int f=0,s=0,t=0;
            
            for(int i=0;i<nums.size();i++){
                  
                 if(nums[i]==0){
                     f++;
                 }
                else if(nums[i]== 1){
                    s++;
                }
                else{
                      t++;
                }
            }
        
        
        for(int i=0;i<f;i++){
              
             nums[i] = 0;
        }
        
        for(int i=f;i<s+f;i++){
             nums[i] = 1;
        }
        
        for(int i=f+s;i<t+s+f;i++){
             nums[i] = 2;
        }
    }
};