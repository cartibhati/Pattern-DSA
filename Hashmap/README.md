# 🔑 Hashmap / Hash Table Pattern

The Hashmap pattern uses hash tables to achieve O(1) average-time complexity for lookups, insertions, and deletions. It is essential for frequency counting, tracking indices, finding complements (like in Two Sum), and detecting duplicates.

---

## 📝 Concept Cheatsheet

### Frequency Counting Template
```cpp
unordered_map<char, int> freq;
for (char c : s) {
    freq[c]++;
}
```

### First Occurrence Index Template
```cpp
unordered_map<char, int> first_occ;
for (int i = 0; i < s.length(); i++) {
    if (first_occ.find(s[i]) == first_occ.end()) {
        first_occ[s[i]] = i;
    }
}
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **First Unique Character in a String** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/first-unique-character-in-a-string/) | [`1_first_unique_char_387.cpp`](./1_first_unique_char_387.cpp) | [Explanation & Dry Run](1_first_unique_char_387.md) |
| 2 | **Ransom Note** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/ransom-note/) | [`2_ransom_note_383.cpp`](./2_ransom_note_383.cpp) | [Explanation & Dry Run](2_ransom_note_383.md) |
| 3 | **Maximum Number of Balloons** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/maximum-number-of-balloons/) | [`3_max_num_of_ballon_1189.cpp`](./3_max_num_of_ballon_1189.cpp) | [Explanation & Dry Run](3_max_num_of_ballon_1189.md) |
| 4 | **Longest Palindrome** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/longest-palindrome/) | [`4_longest_palindrome_409.cpp`](./4_longest_palindrome_409.cpp) | [Explanation & Dry Run](4_longest_palindrome_409.md) |



---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*
