class Solution {
  public:
    bool ispal(string &s, int low, int high) {
        int len = high - low + 1;

        if (len == 0 || len == 1)
            return true;

        if (s[low] != s[high])
            return false;

        return ispal(s, low + 1, high - 1);
    }

    bool isPalindrome(string &s) {
        return ispal(s, 0, s.size() - 1);
    }
};