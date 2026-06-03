#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int n = numbers.size();
        int j = n - 1;

        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                return vector<int>{i + 1, j + 1}; // 1-indexed
            }
            else if (numbers[i] + numbers[j] > target) {
                j--;
            }
            else {
                i++;
            }
        }

        return vector<int>{-1, -1}; // no solution found
    }
};

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    Solution obj;
    vector<int> ans = obj.twoSum(numbers, target);

    cout << "Indices: ";
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}