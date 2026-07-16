class Solution {
public:
    void fun(string &s, int n, int idx, string &diary, 
             vector<string>& res, unordered_map<char,string>& f) {
        
        if (idx == n) {
            res.push_back(diary);
            return;
        }

        string choice = f[s[idx]];
        for (int j = 0; j < choice.size(); j++) {
            diary.push_back(choice[j]);
            fun(s, n, idx + 1, diary, res, f);
            diary.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> f;
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        vector<string> res;
        string diary = "";

        fun(digits, digits.size(), 0, diary, res, f);
        return res;
    }
};