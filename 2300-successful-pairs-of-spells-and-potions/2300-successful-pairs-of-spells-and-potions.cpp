class Solution {
public:
     int binarySearch(int spell, vector<int>& potions, long long success) {
        int startIndex = 0; 
        int lastIndex = potions.size() - 1;
        int ansIndex = -1;
        while(startIndex <= lastIndex){
         
            int midIndex = (startIndex + (lastIndex - startIndex) / 2);
            if ((long long) spell * potions[midIndex] >= success){
                ansIndex = midIndex;
                lastIndex = midIndex - 1;
            }
            else{
                startIndex = midIndex + 1;
            }
        }
        return ansIndex;   
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;
        for (int spell : spells) {
            int countPair = 0;
            int index = binarySearch(spell, potions, success);
            if (index == -1) 
                countPair += 0;
            else
                countPair += (m - index);
            ans.push_back(countPair);
        }
        return ans;
        
    }
};