class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int high=0;
        int ans=INT_MIN;
        int n=s.size();
        unordered_map<char,int>f;
        for(int high=0;high<n;high++){
            f[s[high]]++;
            int k=high-low+1;

            while(f.size()<k){
                f[s[low]]--;
                if(f[s[low]]==0)
                f.erase(s[low]);
                low++;
                k=high-low+1;
            }
            ans=max(ans,high-low+1);
        }
        if(ans==INT_MIN)
       return 0;
       return ans;
    }
};