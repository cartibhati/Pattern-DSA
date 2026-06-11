class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        int one=0;
        unordered_map<int,int>f;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
            else{
                one++;
            }

            int diff=zero-one;
            if(diff==0){
                ans=max(ans,i+1);
                continue;
            }
            if(f.find(diff)==f.end()){
                f[diff]=i;
            }
            else{
                int idx=f[diff];
                int length=i-idx;
                ans=max(length,ans);
            }
        }
        return ans;
    }
};