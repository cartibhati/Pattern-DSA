class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // vector<int>ans;
        int i=0;
        int n=numbers.size();
        int j=n-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                return vector<int>{i + 1, j + 1};//cause it is one indexed
                i++;
                j--;
            }
            else if(numbers[i]+numbers[j]>target)
            j--;
            else
            i++;
        }
        return vector<int>{i + 1, j + 1};
    }
};