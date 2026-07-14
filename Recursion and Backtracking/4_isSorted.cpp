class Solution {
public:
    bool isSorted(vector<int>& arr, int i = 0) {
        int n = arr.size();

        if (i >= n - 1)
            return true;

        if (arr[i] > arr[i + 1])
            return false;

        return isSorted(arr, i + 1);
    }
};