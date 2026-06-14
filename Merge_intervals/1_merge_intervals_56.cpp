class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        if (a.empty()) return {};

        sort(a.begin(), a.end());

        vector<vector<int>> res;

        int st1 = a[0][0];
        int end1 = a[0][1];

        for (int i = 1; i < a.size(); i++) {
            int st2 = a[i][0];
            int end2 = a[i][1];

            if (end1 >= st2) {
                end1 = max(end1, end2);
            } else {
                res.push_back({st1, end1});
                st1 = st2;
                end1 = end2;
            }
        }

        res.push_back({st1, end1});

        return res;
    }
};