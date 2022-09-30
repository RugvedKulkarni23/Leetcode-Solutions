class Solution {
public:
    int hammingDistance(int x, int y) {
        int setbit = 0;
        int result = (x^y);
        while(result>0){
            setbit += result&1;
            result>>=1;
        }
        return setbit;
    }
};