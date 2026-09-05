class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int n=height.size();
        int j=n-1;
        int maxi=0;
        while(i<j){
            int len = min(height[i],height[j]);
            int brea = j-i;
            int area=len*brea;
            maxi=max(area,maxi);

            if(height[i]<height[j])
            i++;
            else
            j--;
        }
        return maxi;
    }
};