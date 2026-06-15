class Solution {
  public:
    bool isIntersect(vector<vector<int>> a) {
        // Code Here
        sort(a.begin(),a.end());
        int start1 = a[0][0];
        int end1 = a[0][1];
        
        for(int i=1;i<a.size();i++){
            int start2 = a[i][0];
            int end2 = a[i][1];
            
            if(end1>=start2)
            return true;
            
            start1 = start1;
            end1 = max(end1,end2);
        }
        return false;
        
    }
};