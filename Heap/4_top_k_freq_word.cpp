class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first != b.first)
                return a.first > b.first;      // smaller frequency has higher priority

            return a.second < b.second;        // lexicographically smaller is better,
                                               // so larger word stays at the top
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        // Count frequency
        for (string &word : words)
            freq[word]++;

        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       cmp> pq;

        for (auto &it : freq) {
            pq.push({it.second, it.first});

            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};