class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
         vector <vector <int>> ans,ans1;
        vector <int> v;
        solution(0,nums,ans,v);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        int flag=0;
        for(int i=0;i<ans.size();i++){
            for(int j=1;j<ans[i].size();j++){
                if(ans[i][j]<ans[i][j-1]){
                    flag=1;
                    break;
                }
            }
            if(flag==0) ans1.push_back(ans[i]);
            flag=0;
        }
        return ans1;
    }
    void solution(int i,vector<int>& nums,vector <vector <int>> &ans,vector <int> &v){
        if(i>=nums.size() ){
            if(v.size()>=2)
                ans.push_back(v);
            return;
        }
       v.push_back(nums[i]);
        solution(i+1,nums,ans,v);
        v.pop_back();
        solution(i+1,nums,ans,v);
    }
};