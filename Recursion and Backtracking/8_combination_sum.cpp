class Solution {
public:
    void fun(vector<int>& a, int n, int idx, vector<int>& diary, int sum,
             vector<vector<int>>& res, int target) {
        
        if (sum == target) {
            res.push_back(diary);
            return;
        }
        
        if (idx == n || sum > target) return;

        // Not pick
        fun(a, n, idx + 1, diary, sum, res, target);

        // Pick (stay at same index because unlimited use allowed)
        diary.push_back(a[idx]);
        fun(a, n, idx, diary, sum + a[idx], res, target);
        diary.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> diary;

        fun(candidates, candidates.size(), 0, diary, 0, res, target);

        return res;
    }
};