class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
             
        int n = nums.size();
        vector<unordered_map<long, int>> table(n);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long d = (long)nums[i] - nums[j];
               

            
                if (table[j].find(d) != table[j].end()) {
                    ans += table[j][d];
                    table[i][d] += table[j][d];
                }

            
                table[i][d] += 1;
            }
        }
        
        return ans;
    }
};