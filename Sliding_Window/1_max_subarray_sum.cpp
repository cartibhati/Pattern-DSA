class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int low=0;
        int high= k-1;
        int sum=0;
        for(int i=0;i<=high;i++){
            sum+=arr[i];
        }
        
        int ans=sum;
        while(high<n-1){
            high++;
            sum += arr[high];
            sum -= arr[low];
            low++;
            
            ans=max(ans,sum);
        }
        return ans;
    }
};