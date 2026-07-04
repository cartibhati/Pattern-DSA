# Aggressive Cows (GFG)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/aggressive-cows/1)**

---

## 📝 Problem Description

You are given an array `stalls` which represents the positions of stalls on a straight line. You are also given an integer `k` representing the number of aggressive cows.

You want to assign the cows to the stalls such that the **minimum distance between any two of them is as large as possible**.

Return the *maximum possible minimum distance*.

---

## 💡 Intuition & Core Logic

1. **Sort the Stalls**:
   - The stalls are on a straight line. To easily compute distances between stalls sequentially, we first sort the array.

2. **Define Search Space**:
   - The minimum possible distance between any two cows is `0` or `1` (if they are in the same or adjacent stalls).
   - The maximum possible distance between two cows is the distance between the first and last stall: `stalls.back() - stalls.front()`.
   - Thus, the search space for the optimal minimum distance is `[0, stalls.back() - stalls.front()]`.

3. **Binary Search on Answer**:
   - The check `isPossible(mid)` is monotonic: if we can place `k` cows with a minimum distance `mid`, we might also be able to place them with a larger distance, but definitely we can place them with any smaller distance. If we *cannot* place them with `mid`, we cannot place them with any distance larger than `mid`.
   - We binary search the distance in our range `[low, high]`.
   - For a middle distance `mid = low + (high - low) / 2`:
     - Run a greedy placement check: Place the first cow at `stalls[0]`. Then iterate through the remaining stalls. If the distance from the last placed cow to the current stall is at least `mid`, place the next cow there and update the last placed position.
     - If we successfully place all `k` cows, then `mid` is a valid distance. We save it (`ans = mid`) and try for a larger distance by moving our search to the right half: `low = mid + 1`.
     - If we cannot place `k` cows, then `mid` is too large. We search for smaller distances by moving to the left half: `high = mid - 1`.

---

## 🔄 Step-by-Step Dry Run

For `stalls = [1, 2, 4, 8, 9]` and `k = 3`.

- **Initialization**:
  - Sort stalls (already sorted): `[1, 2, 4, 8, 9]`
  - `low = 0`, `high = 9 - 1 = 8`
  - `ans = -1`

1. **Iteration 1**:
   - `mid = 0 + (8 - 0) / 2 = 4`
   - Test if we can place 3 cows with min distance `4`:
     - Cow 1 placed at `stalls[0] = 1`.
     - Cow 2: next stall must be `>= 1 + 4 = 5`. Check `stalls[3] = 8`. Cow 2 placed at `8`.
     - Cow 3: next stall must be `>= 8 + 4 = 12`. No stalls found.
     - Total placed cows = 2.
   - Result: **False** (Cannot place 3 cows).
   - Update: `high = mid - 1 = 3`.

2. **Iteration 2**:
   - `low = 0`, `high = 3`
   - `mid = 0 + (3 - 0) / 2 = 1`
   - Test if we can place 3 cows with min distance `1`:
     - Cow 1 placed at `stalls[0] = 1`.
     - Cow 2: next stall must be `>= 1 + 1 = 2`. Check `stalls[1] = 2`. Cow 2 placed at `2`.
     - Cow 3: next stall must be `>= 2 + 1 = 3`. Check `stalls[2] = 4`. Cow 3 placed at `4`.
     - Total placed cows = 3.
   - Result: **True** (Valid configuration).
   - Update: `ans = 1`, `low = mid + 1 = 2`.

3. **Iteration 3**:
   - `low = 2`, `high = 3`
   - `mid = 2 + (3 - 2) / 2 = 2`
   - Test if we can place 3 cows with min distance `2`:
     - Cow 1 placed at `stalls[0] = 1`.
     - Cow 2: next stall must be `>= 1 + 2 = 3`. Check `stalls[2] = 4`. Cow 2 placed at `4`.
     - Cow 3: next stall must be `>= 4 + 2 = 6`. Check `stalls[3] = 8`. Cow 3 placed at `8`.
     - Total placed cows = 3.
   - Result: **True** (Valid configuration).
   - Update: `ans = 2`, `low = mid + 1 = 3`.

4. **Iteration 4**:
   - `low = 3`, `high = 3`
   - `mid = 3 + (3 - 3) / 2 = 3`
   - Test if we can place 3 cows with min distance `3`:
     - Cow 1 placed at `stalls[0] = 1`.
     - Cow 2: next stall must be `>= 1 + 3 = 4`. Check `stalls[2] = 4`. Cow 2 placed at `4`.
     - Cow 3: next stall must be `>= 4 + 3 = 7`. Check `stalls[3] = 8`. Cow 3 placed at `8`.
     - Total placed cows = 3.
   - Result: **True** (Valid configuration).
   - Update: `ans = 3`, `low = mid + 1 = 4`.

- **Termination**: `low (4) > high (3)`. Loop terminates.
- **Output**: `ans = 3`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:

    bool isPossible(vector<int>& arr, int mid, int k) {
        int cows = 1;
        int lastpos = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - lastpos >= mid) {
                cows++;
                lastpos = arr[i];

                if (cows == k)
                    return true;
            }
        }

        return false;
    }

    int getDis(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.back() - arr.front();
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int aggressiveCows(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        return getDis(arr, k);
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N * log(M) + N * log(N))` where `N` is the number of stalls and `M` is the maximum distance range (`stalls.back() - stalls.front()`).
  - Sorting the stalls array takes `O(N * log(N))` time.
  - The binary search takes `O(log(M))` steps.
  - In each step, checking if placement is possible takes `O(N)` time.
- **Space Complexity**: `O(1)` (excluding sorting stack space) as only a constant amount of extra memory is used.
