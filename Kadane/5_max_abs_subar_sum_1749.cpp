class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0;
        int bestend=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=bestend+nums[i];
            int v2=nums[i];
            bestend=max(v1,v2);
            ans=max(ans,bestend);
        }
        return ans;
    }
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int i=0;
        int bestend=a[0];
        int ans=a[0];
        for(int i=1;i<a.size();i++){
            int v1=bestend+a[i];
            int v2=a[i];
            bestend=min(v1,v2);
            ans=min(ans,bestend);
        }
        return ans;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=maxSubArray(nums);
        int mini=smallestSumSubarray(nums);
        int ans=max(maxi,mini);
        return max(maxi, abs(mini));
    }
};