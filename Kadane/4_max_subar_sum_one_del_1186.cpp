class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete=arr[0];
        int onedelete= INT_MIN;
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            int prevnodelete = nodelete;
            int prevonedelete = onedelete;

            nodelete = max(arr[i],nodelete+arr[i]);
            int v2;
            if(onedelete==INT_MIN){
                v2=arr[i];
            }
            else{
                v2= prevonedelete+arr[i];
            }

            onedelete  = max(v2,prevnodelete);
            ans = max(ans,max(onedelete,nodelete));
        }
        return ans;
    }
};