class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>neg;
        vector<int>pos;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else
            pos.push_back(nums[i]);
        }

        for(int i=0;i<neg.size();i++){
            neg[i]=neg[i]*neg[i];
        }
        reverse(neg.begin(), neg.end());
        for(int i=0;i<pos.size();i++){
            pos[i]=pos[i]*pos[i];
        }
        vector<int> ans;
        
        int i=0;
        int j=0;
        int n=pos.size();
        int m=neg.size();

        ans.reserve(m + n);

        while(i<n && j<m){
            if(pos[i]<neg[j]){
                ans.push_back(pos[i]);
                i++;
            }
            else{
                ans.push_back(neg[j]);
                j++;
            }
        }
        while(i<n){
            ans.push_back(pos[i]);
            i++;
        }
        while(j<m){
            ans.push_back(neg[j]);
            j++;
        }
        return ans;

    }
};