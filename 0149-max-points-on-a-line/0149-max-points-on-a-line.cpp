class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
         if(points.size()==1||points.size()==2)
        return points.size();
        int mx=0;
        for(int i=0;i<points.size();i++){
        unordered_map<float,int> mp;
        for(int j=i+1;j<points.size();j++){
            if((points[j][0]-points[i][0])==0){
            mp[INT_MAX]++;
             mx=max(mx,mp[INT_MAX]+1);
            }
            else{
            float x=((points[j][1]-points[i][1])*1.0/(points[j][0]-points[i][0]));
            mp[x]++;
            mx=max(mx,mp[x]+1);
            }
        }
        }
        return mx;
    }
};