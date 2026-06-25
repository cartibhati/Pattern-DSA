# Ransom Note (LeetCode 383)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/ransom-note/)**

---

## 📝 Problem Description

Given two strings `ransomNote` and `magazine`, return `true` if `ransomNote` can be constructed by using the letters from `magazine` and `false` otherwise.

Each letter in `magazine` can only be used once in `ransomNote`.

---

## 💡 Intuition & Core Logic

1. **Character Counting**: Count the frequency of each character needed in `ransomNote` (stored in `need`) and the frequency of each character available in `magazine` (stored in `have`).
2. **Frequency Verification**: Iterate through each character needed for the ransom note. If the available frequency in the magazine (`have[c]`) is less than the required frequency (`need[c]`), we cannot construct the ransom note, so return `false`.
3. **Success**: If all required character frequencies are satisfied, return `true`.

---

## 🔄 Step-by-Step Dry Run

For `ransomNote = "aa"`, `magazine = "aab"`.
1. **Count frequencies**:
   - `need` (ransomNote): `a` -> 2
   - `have` (magazine): `a` -> 2, `b` -> 1
2. **Verification (`fun` function)**:
   - Check character `a`:
     - `fneed` (need['a']) = 2
     - `fhave` (have['a']) = 2
     - Since `fhave (2) >= fneed (2)`, check passes.
3. **Return**: `true`.

For `ransomNote = "a"`, `magazine = "b"`.
1. **Count frequencies**:
   - `need`: `a` -> 1
   - `have`: `b` -> 1
2. **Verification**:
   - Check character `a`:
     - `fneed` = 1
     - `fhave` (have['a']) = 0
     - Since `fhave (0) < fneed (1)`, return `false`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    bool fun(unordered_map<char,int>have,unordered_map<char,int>need ){
        for(auto i:need){
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            if(fhave<fneed)
            return false;
        }
        return true;
    }
    bool canConstruct(string ransom, string magzine) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        for(int i=0;i<ransom.size();i++){
            need[ransom[i]]++;
        }
        for(int i=0;i<magzine.size();i++){
            have[magzine[i]]++;
        }
        return fun(have,need);
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N + M)` — where `N` is the length of `ransomNote` and `M` is the length of `magazine`. We iterate through both strings once to build the frequency tables, then iterate over unique characters in the ransom note.
- **Space Complexity**: `O(1)` — The hashmaps store at most 26 unique lowercase English letters, which consumes constant extra space.
