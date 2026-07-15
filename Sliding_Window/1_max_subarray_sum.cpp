class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int low=0;
        int high=k-1;
        int n=arr.size();
        int sum=0;
        for(int i=0;i<=high;i++){
            sum=sum+arr[i];
        }
        int ans=sum;
       while (high < n - 1) {
            low++;
            high++;

            sum = sum - arr[low - 1];
            sum = sum + arr[high];

            ans = max(ans, sum);
        }
        return ans;
        
    }
};
