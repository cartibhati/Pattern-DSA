class Solution {
public:
    int totalFruit(vector<int>& s) {
        int low=0;
        int high=0;
        int n=s.size();
        int ans=-1;
        int k=2;
        unordered_map<int,int>f;
        for(int high=0;high<n;high++){
            f[s[high]]++;
            while(f.size()>k){
                f[s[low]]--;
                if(f[s[low]]==0)
                f.erase(s[low]);
                low++;
            }
            if (f.size() == k || f.size()<k) {
                ans = max(ans, high - low + 1);
            }
        }

        return ans;
    }
};