class Solution {
  public:
    int countTriplets(int target, vector<int>& arr) {
        // code here
        int n=arr.size();
        int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;

            while(left<right){
                int sum=arr[i]+arr[left]+arr[right];
                if(sum>=target)
                right--;
                else{
                    ans=ans+(right-left);
                    left++;
                }
            }
        }
        return ans;
    }
};