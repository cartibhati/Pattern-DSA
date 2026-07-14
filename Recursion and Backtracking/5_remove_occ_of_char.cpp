class Solution {
public:
    void removeCharacter(string &s, char c, int i = 0) {
        if (i == s.size())
            return;

        if (s[i] == c) {
            s.erase(i, 1);
            removeCharacter(s, c, i);   // stay at same index
        } else {
            removeCharacter(s, c, i + 1);
        }
    }
};