# Koko Eating Bananas (LeetCode 875)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/koko-eating-bananas/)**

---

## 📝 Problem Description

Koko loves to eat bananas. There are `n` piles of bananas, the `i`-th pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return *the minimum integer `k` such that she can eat all the bananas within `h` hours*.

---

## 💡 Intuition & Core Logic

1. **Search Space for Speed**:
   - The minimum possible eating speed is `1` banana per hour.
   - The maximum possible speed needed is the maximum value in `piles` (say `max(piles)`), because eating at any speed greater than this won't save any more hours for that pile (each pile will still take at least 1 hour).
   - Thus, the search space for the eating speed `k` is `[1, max(piles)]`.

2. **Binary Search on Answer**:
   - The hours required to finish all bananas is monotonically decreasing as speed `k` increases (higher speed $\rightarrow$ fewer or equal hours).
   - We can binary search for the minimum viable speed `k` in the range `[1, max(piles)]`.
   - For a middle speed `mid = s + (e - s) / 2`:
     - Calculate the total hours `hr` required to eat all piles at speed `mid`.
     - For each pile `p`, hours needed = `ceil(p / mid)` which is mathematically equal to `p / mid + (p % mid != 0 ? 1 : 0)`.
     - If `hr > h`, the speed `mid` is too slow (she cannot finish in time). We must increase the speed, so we search in the right half: `s = mid + 1`.
     - If `hr <= h`, the speed `mid` is sufficient. But we want the *minimum* speed, so we record `mid` as a potential result (`res = mid`) and try to find a smaller valid speed by searching in the left half: `e = mid - 1`.

3. **Termination**:
   - When the search range `s` exceeds `e`, our binary search terminates, and `res` holds the minimum valid speed.

---

## 🔄 Step-by-Step Dry Run

For `piles = [3, 6, 7, 11]` and `h = 8`.

- **Initialization**: 
  - `s = 1`, `e = max(piles) = 11`
  - `res = -1`

1. **Iteration 1**:
   - `mid = 1 + (11 - 1) / 2 = 6`
   - Calculate total hours required at speed `6`:
     - Pile 3: `3 / 6` $\rightarrow$ `1` hour
     - Pile 6: `6 / 6` $\rightarrow$ `1` hour
     - Pile 7: `7 / 6` $\rightarrow$ `2` hours (1 full hour + 1 remainder hour)
     - Pile 11: `11 / 6` $\rightarrow$ `2` hours (1 full hour + 5 remainder hour)
     - `hr = 1 + 1 + 2 + 2 = 6` hours
   - Compare `hr (6) <= h (8)`: **True** (Valid speed).
   - Record `res = 6`, update `e = mid - 1 = 5`.

2. **Iteration 2**:
   - `s = 1`, `e = 5`
   - `mid = 1 + (5 - 1) / 2 = 3`
   - Calculate total hours required at speed `3`:
     - Pile 3: `3 / 3` $\rightarrow$ `1` hour
     - Pile 6: `6 / 3` $\rightarrow$ `2` hours
     - Pile 7: `7 / 3` $\rightarrow$ `3` hours
     - Pile 11: `11 / 3` $\rightarrow$ `4` hours
     - `hr = 1 + 2 + 3 + 4 = 10` hours
   - Compare `hr (10) <= h (8)`: **False** (Too slow).
   - Update `s = mid + 1 = 4`.

3. **Iteration 3**:
   - `s = 4`, `e = 5`
   - `mid = 4 + (5 - 4) / 2 = 4`
   - Calculate total hours required at speed `4`:
     - Pile 3: `3 / 4` $\rightarrow$ `1` hour
     - Pile 6: `6 / 4` $\rightarrow$ `2` hours
     - Pile 7: `7 / 4` $\rightarrow$ `2` hours
     - Pile 11: `11 / 4` $\rightarrow$ `3` hours
     - `hr = 1 + 2 + 2 + 3 = 8` hours
   - Compare `hr (8) <= h (8)`: **True** (Valid speed).
   - Record `res = 4`, update `e = mid - 1 = 3`.

- **Termination**: `s (4) > e (3)`. Loop terminates.
- **Output**: `res = 4`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    long long fun(vector<int>& a, int n, int speed) {
        long long h = 0;
        for (int i = 0; i < n; i++) {
            h = h + a[i] / speed;
            if (a[i] % speed != 0)
                h++;
        }
        return h;
    }

    int max(vector<int>& a) {
        int maxi = INT_MIN;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > maxi)
                maxi = a[i];
        }
        return maxi;
    }

    int minEatingSpeed(vector<int>& a, int h) {
        int res = -1;
        int s = 1;
        int e = max(a);
        int n = a.size();
        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long hr = fun(a, n, mid);
            if (hr > h)
                s = mid + 1;
            else {
                res = mid;
                e = mid - 1;
            }
        }
        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N * log(M))` where `N` is the number of piles and `M` is the maximum number of bananas in a single pile (`max(piles)`).
  - The binary search takes `O(log(M))` steps.
  - In each step, we iterate through all piles to calculate hours, taking `O(N)` time.
- **Space Complexity**: `O(1)` as only a constant amount of extra memory is used.
