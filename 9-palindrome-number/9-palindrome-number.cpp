class Solution {
public:
    bool isPalindrome(int x) {
        string numStr = to_string(x);
        reverse(numStr.begin(), numStr.end());
        string notReverse = to_string(x);
        return numStr == notReverse;
    }
};