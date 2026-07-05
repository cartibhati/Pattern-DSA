class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.first < b.first;   // larger distance has higher priority
        }
    };

    int dist(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for (int i = 0; i < points.size(); i++) {
            pq.push({dist(points[i]), i});

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]); // second is the index
            pq.pop();
        }

        return ans;
    }
};