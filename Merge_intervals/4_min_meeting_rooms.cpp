class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i=0;
        int j=0;
        int n=start.size();
        int m=end.size();
        int res=INT_MIN;
        int rooms=0;
        while(i<n && j<m){
            if(start[i]<end[j]){
                rooms++;
                res=max(res,rooms);
                i++;
            }
            else{
                rooms--;
                j++;
            }
        }
        return res;
        
    }
};
