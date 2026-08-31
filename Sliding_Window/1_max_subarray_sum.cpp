class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int low = 0;
        int n = arr.size();
        int high = k - 1;
        int ans = 0;
        int sum = 0;

        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }

        ans = sum;

        while(high < n - 1) {
            low++;
            high++;

            sum -= arr[low - 1];
            sum += arr[high];

            ans = max(ans, sum);
        }

        return ans;
    }
};
