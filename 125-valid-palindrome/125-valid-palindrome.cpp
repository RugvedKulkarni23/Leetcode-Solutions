class Solution {
    private: 
        bool Valid(char ch){
            if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0'&& ch<='9')){
                return 1;
            }
            return 0;
        }
    char ToLowercase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch>='0' && ch<='9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
    int checkPalindrome(string st)
{
    int s = 0;
    int e = st.length() - 1;
    while (s <= e)
    {
        if (st[s] != st[e])
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
    }
    return 1;
}
public:
    bool isPalindrome(string s) {

           string temp ="";
        for(int j=0; j<s.length();j++){
            if(Valid(s[j])){
                temp.push_back(s[j]);
            }
        }
        for(int j=0;j<temp.length();j++){
            temp[j]= ToLowercase(temp[j]);
        }
        return checkPalindrome(temp);
    }
};