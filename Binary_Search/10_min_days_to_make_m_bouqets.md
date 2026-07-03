# Minimum Number of Days to Make m Bouquets (LeetCode 1482)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)**

---

## 📝 Problem Description

You are given an integer array `bloomDay`, an integer `m` and an integer `k`.

You want to make `m` bouquets. To make a bouquet, you need to use `k` **adjacent** flowers from the garden.

The garden consists of `n` flowers, the `i`-th flower will bloom in the `bloomDay[i]` and then can be used in **exactly one** bouquet.

Return *the minimum number of days you need to wait to be able to make `m` bouquets from the garden*. If it is impossible to make `m` bouquets, return `-1`.

---

## 💡 Intuition & Core Logic

1. **Possibility Check**:
   - Each bouquet requires `k` flowers, and we need `m` bouquets. So we need at least `m * k` total flowers.
   - If the total flowers available in the garden `n = bloomDay.size()` is less than `m * k`, it is mathematically impossible to make the bouquets. In this case, we can return `-1` directly.
   - Since the code initializes the result `res = -1` and only updates it if a valid day is found, it naturally handles this. However, adding an early exit condition `if ((long long)m * k > bloomDay.size()) return -1;` is a standard optimization.

2. **Search Space for Days**:
   - The minimum possible day we could wait is `1` day.
   - The maximum possible day we need to wait is `max(bloomDay)` because on that day, all flowers in the garden will have bloomed.
   - Thus, the search space for the minimum days is `[1, max(bloomDay)]`.

3. **Binary Search on Answer**:
   - The number of bouquets we can make is a monotonically increasing function of the days we wait (more days $\rightarrow$ more flowers bloom $\rightarrow$ more bouquets can be made).
   - Therefore, we can binary search the minimum valid day in the range `[1, max(bloomDay)]`.
   - For a candidate day `mid`:
     - Run a helper function `canMake(bloomDay, mid, m, k)` to check if we can make at least `m` bouquets of `k` adjacent bloomed flowers by day `mid`.
     - In `canMake`:
       - Iterate through `bloomDay`. If `bloomDay[i] <= mid`, the flower has bloomed. Increment our consecutive flower count `flowers`.
       - If the flower hasn't bloomed, reset `flowers = 0` (since we need *adjacent* flowers).
       - If `flowers == k`, we successfully form a bouquet: increment `bouquets` and reset `flowers = 0`.
       - If at the end of the iteration `bouquets >= m`, return `true`. Otherwise, `false`.
     - If `canMake` returns `true`, day `mid` is possible. We save it in `res = mid` and try to search for a smaller day: `high = mid - 1`.
     - If `canMake` returns `false`, day `mid` is too early. We need to search for a larger day: `low = mid + 1`.

---

## 🔄 Step-by-Step Dry Run

For `bloomDay = [1, 10, 3, 10, 2]`, `m = 3`, `k = 1`.

- **Initialization**: 
  - `low = 1`, `high = max(bloomDay) = 10`
  - `res = -1`

1. **Iteration 1**:
   - `mid = 1 + (10 - 1) / 2 = 5`
   - Check `canMake(bloomDay, 5, 3, 1)`:
     - `bloomDay[0] = 1 <= 5` (Bloomed) $\rightarrow$ `flowers = 1 == k` $\rightarrow$ `bouquets = 1`, reset `flowers = 0`
     - `bloomDay[1] = 10 > 5` (Not bloomed) $\rightarrow$ `flowers = 0`
     - `bloomDay[2] = 3 <= 5` (Bloomed) $\rightarrow$ `flowers = 1 == k` $\rightarrow$ `bouquets = 2`, reset `flowers = 0`
     - `bloomDay[3] = 10 > 5` (Not bloomed) $\rightarrow$ `flowers = 0`
     - `bloomDay[4] = 2 <= 5` (Bloomed) $\rightarrow$ `flowers = 1 == k` $\rightarrow$ `bouquets = 3`, reset `flowers = 0`
     - Total `bouquets = 3 >= m (3)` $\rightarrow$ Returns `true`.
   - Update `res = 5`, search left: `high = mid - 1 = 4`.

2. **Iteration 2**:
   - `low = 1`, `high = 4`
   - `mid = 1 + (4 - 1) / 2 = 2`
   - Check `canMake(bloomDay, 2, 3, 1)`:
     - `bloomDay[0] = 1 <= 2` (Bloomed) $\rightarrow$ `flowers = 1 == k` $\rightarrow$ `bouquets = 1`, reset `flowers = 0`
     - `bloomDay[1] = 10 > 2` (Not bloomed) $\rightarrow$ `flowers = 0`
     - `bloomDay[2] = 3 > 2` (Not bloomed) $\rightarrow$ `flowers = 0`
     - `bloomDay[3] = 10 > 2` (Not bloomed) $\rightarrow$ `flowers = 0`
     - `bloomDay[4] = 2 <= 2` (Bloomed) $\rightarrow$ `flowers = 1 == k` $\rightarrow$ `bouquets = 2`, reset `flowers = 0`
     - Total `bouquets = 2 < m (3)` $\rightarrow$ Returns `false`.
   - Search right: `low = mid + 1 = 3`.

3. **Iteration 3**:
   - `low = 3`, `high = 4`
   - `mid = 3 + (4 - 3) / 2 = 3`
   - Check `canMake(bloomDay, 3, 3, 1)`:
     - `bloomDay[0] = 1 <= 3` (Bloomed) $\rightarrow$ `bouquets = 1`
     - `bloomDay[1] = 10 > 3` (Not bloomed)
     - `bloomDay[2] = 3 <= 3` (Bloomed) $\rightarrow$ `bouquets = 2`
     - `bloomDay[3] = 10 > 3` (Not bloomed)
     - `bloomDay[4] = 2 <= 3` (Bloomed) $\rightarrow$ `bouquets = 3`
     - Total `bouquets = 3 >= m (3)` $\rightarrow$ Returns `true`.
   - Update `res = 3`, search left: `high = mid - 1 = 2`.

- **Termination**: `low (3) > high (2)`. Loop terminates.
- **Output**: `res = 3`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int max(vector<int>& a) {
        int maxi = INT_MIN;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > maxi)
                maxi = a[i];
        }
        return maxi;
    }

    bool canMake(vector<int>& bloomDay, int day, int m, int k) {
        int flowers = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) { // if flower has bloomed
                flowers++;
            } else {
                flowers = 0;
            }

            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = max(bloomDay);
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, mid, m, k)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N * log(D))` where `N` is the number of flowers (`bloomDay.size()`) and `D` is the maximum bloom day (`max(bloomDay)`).
  - The binary search range is from `1` to `D`, requiring `O(log(D))` iterations.
  - In each iteration, we run `canMake` which scans the `bloomDay` array of size `N`, taking `O(N)` time.
- **Space Complexity**: `O(1)` as we do not use any extra space.
