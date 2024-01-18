class Solution {
public:
    int climbStairs(int n) {
          return ((1 / sqrt(5)) * (pow((sqrt(5) + 1) / 2, n + 1) - pow((sqrt(5) - 1) / 2, n + 1)) + 0.5); 
         
    }
};