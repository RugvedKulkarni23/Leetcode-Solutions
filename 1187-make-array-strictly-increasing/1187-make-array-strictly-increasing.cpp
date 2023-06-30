class Solution {
public:
    //hand made lower bound function
    int l_b(int num, vector<int>& arr2) {
        int n = arr2.size();
        int l = 0;
        int h = n - 1;
        int ans = arr2.size();

        while (l <= h) {
            int mid = (l + h) / 2;
            if (arr2[mid] == num) {
                return mid;
            } else if (arr2[mid] < num) {
                l = mid + 1;
            } else {
                ans = mid;
                h = mid - 1;
            }
        }
        return ans;
    }


    //helper function
    int f(int ind, int prev, vector<int>& arr1, vector<int>& arr2, unordered_map<string, int>& memo) {
        if (ind == arr1.size()) {
            return 0;
        }

        //"ind|prev" is our key in the memoization process.
        string key = to_string(ind) + "|" + to_string(prev);
        if (memo.count(key)) {
            return memo[key];
        }

        //rem => no switch , swc => switch.
        int rem = 1e9;
        int swc;
        
        //no switch , only when current element is already bigger than prev
        if (arr1[ind] > prev) {
            rem = f(ind + 1, arr1[ind], arr1, arr2, memo);
        }
        
        //to switch, find the eligible candidate in arr2.
        int i = l_b(prev + 1, arr2);
        //no candidate = no switch else simply switch, count 1 way and update the previous.
        if (i == arr2.size()) {
            swc = 1e9;
        } else {
            swc = 1 + f(ind + 1, arr2[i], arr1, arr2, memo);
        }
 
        //minimum of no switch and switch.
        int result = min(rem, swc);
        memo[key] = result;
        return result;
    }
    
    //main function
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        //to make binary search more efficient
        sort(arr2.begin(), arr2.end());
        
        //a cheeky way to memoize the code
        unordered_map<string, int> memo;
        int ans = f(0, -1, arr1, arr2, memo);

        //not possible for longest increasing array so -1.
        if (ans == 1e9)
            return -1;

        return ans;
    }
};