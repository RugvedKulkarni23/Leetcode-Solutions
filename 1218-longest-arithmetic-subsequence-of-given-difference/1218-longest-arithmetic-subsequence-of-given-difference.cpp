class Solution
{
public:
    vector<vector<int>> dp;
    int longestSubsequence(vector<int> &arr, int difference)
    {
        // Storing the Arithmetic Progression with the help of an unordered_map
        unordered_map<int, int> Terms_till_now;
        // Storing the final answer as 1
        // Since there will be atleast 1 element in the sequence
        int max_length = 1;
        for(int curr_element : arr)
        {
            /*
            Find the number of terms, till curr_element - difference , say terms
            Mapping 1 + n to the current term of the sequence, i.e. curr_element 
            */
            Terms_till_now[curr_element] = Terms_till_now[curr_element - difference] + 1;
            // Checking for the max length of the sequence
            max_length = max(max_length, Terms_till_now[curr_element]); 
        }
        return max_length;
    }
};