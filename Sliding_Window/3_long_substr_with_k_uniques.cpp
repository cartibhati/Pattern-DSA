class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int low=0;
        int n=s.size();
        int high=0;
        int res=-1;
        unordered_map<char,int>f;
        for(high=0;high<n;high++){
            f[s[high]]++;
            while(f.size()>k){
                f[s[low]]--;
                if(f[s[low]]==0)
                f.erase(s[low]);
                low++;
            }
            
            if(f.size()==k){
                int len=high-low+1;
                res=max(res,len);
            }
        }
        return res;
    }
};
