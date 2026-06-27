# Maximum Number of Balloons (LeetCode 1189)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/maximum-number-of-balloons/)**

---

## 📝 Problem Description

Given a string `text`, you want to use the characters of `text` to form as many instances of the word **"balloon"** as possible. You can use each character in `text` at most once. Return the maximum number of instances that can be formed.

---

## 💡 Intuition & Core Logic

1. **Count Frequencies**: First, count the occurrence of each character in the input string `text` using a hashmap or a frequency array.
2. **Define Requirements**: The target word `"balloon"` requires specific frequencies of characters:
   - `b` -> 1
   - `a` -> 1
   - `l` -> 2
   - `o` -> 2
   - `n` -> 1
3. **Find the Bottleneck**: For each required character, compute how many complete copies we can form using the formula:
   $$\text{copies} = \frac{\text{count in text}}{\text{required count}}$$
   The maximum number of complete `"balloon"` instances we can form is limited by the minimum copies we can make of any single required letter (the bottleneck).

---

## 🔄 Step-by-Step Dry Run

For `text = "nlaebolko"`
1. **First Pass (Build Frequency Map)**:
   - `n` -> 1, `l` -> 2, `a` -> 1, `e` -> 1, `b` -> 1, `o` -> 2, `l` -> 2 (already updated), `k` -> 1, `o` -> 2 (already updated)
2. **Calculate Copies**:
   - `b`: `have['b'] / 1 = 1 / 1 = 1`
   - `a`: `have['a'] / 1 = 1 / 1 = 1`
   - `l`: `have['l'] / 2 = 2 / 2 = 1`
   - `o`: `have['o'] / 2 = 2 / 2 = 1`
   - `n`: `have['n'] / 1 = 1 / 1 = 1`
3. **Result**: The minimum of these counts is `1`. We return `1`.

For `text = "loonbalxballpoon"`
1. **Frequency Map**:
   - `l` -> 4, `o` -> 4, `n` -> 2, `b` -> 2, `a` -> 2, `x` -> 1, `p` -> 1
2. **Calculate Copies**:
   - `b`: `2 / 1 = 2`
   - `a`: `2 / 1 = 2`
   - `l`: `4 / 2 = 2`
   - `o`: `4 / 2 = 2`
   - `n`: `2 / 1 = 2`
3. **Result**: The minimum of these counts is `2`. We return `2`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string s) {
        unordered_map<char,int>have;
        for(int i=0;i<s.size();i++){
            have[s[i]]++;
        }
        unordered_map<char,int>need;
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;


        int ans=INT_MAX;
        for(auto i:need){
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            int times = fhave/fneed;
            ans = min(ans,times);
        }
        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` — We iterate through the string `text` of length `N` to build the frequency map. Then we loop through the 5 distinct character requirements of the word `"balloon"`, which is `O(1)`.
- **Space Complexity**: `O(1)` — The size of the frequency map is bounded by the number of unique characters in the alphabet (at most 26), which requires constant auxiliary space.
