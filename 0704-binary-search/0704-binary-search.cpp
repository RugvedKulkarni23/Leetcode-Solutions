class Solution {
public:
    
    int solve(vector<int> &arr, int s, int e, int key)
{
    
    if (s > e)
    {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)

        return mid;

    if (arr[mid] < key)
    {
        return solve(arr, mid + 1, e, key);
    }
    else if (arr[mid] > key)
    {
        return solve(arr, s, mid - 1, key);
    }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int answer = solve(nums,0,nums.size()-1,target);
        return answer;
    }
};