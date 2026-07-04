class Solution {
public:

    bool isPossible(vector<int>& arr, int mid, int k) {
        int cows = 1;
        int lastpos = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastpos >= mid) {
                cows++;
                lastpos = arr[i];

                if (cows == k)
                    return true;
            }
        }

        return false;
    }

    int getDis(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.back() - arr.front();
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int aggressiveCows(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        return getDis(arr, k);
    }
};