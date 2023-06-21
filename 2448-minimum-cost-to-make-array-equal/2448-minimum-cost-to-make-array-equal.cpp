class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs)
    {
        int left = *std::min_element(nums.begin(), nums.end());
        int right = *std::max_element(nums.begin(), nums.end());
        long long ans = 0;
        while (left < right)
        {
            int mid = (left + right) / 2;
            long long leftCost = cost(nums, costs, mid);
            long long rightCost = cost(nums, costs, mid + 1);
            if (leftCost > rightCost)
            {
                left = mid + 1;
                ans = rightCost;
            }
            else
            {
                right = mid;
                ans = leftCost;
            }
        }
        return ans;
    }

    long long cost(vector<int>& nums, vector<int>& costs, int level)
    {
        long long total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += ((long long) costs[i]) * abs(nums[i] - level);
        }
        return total;
    }

};