class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        int den=2*k+1;
        vector<long long> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(i+k >= n || i-k < 0){
                ans[i]=-1;
                continue;
            }
            long long s1=prefix[i+k],s2=0;
            if(i-k-1 >= 0){
                s2=prefix[i-k-1];
            }
            ans[i]=(s1-s2)/den;
        }
        return ans;
    }
};