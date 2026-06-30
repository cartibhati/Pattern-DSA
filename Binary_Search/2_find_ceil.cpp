class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int s=0;
        int e=n-1;
        int res=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]<x)
            s=mid+1;
            else{
                res=mid;
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return res;
    }
};