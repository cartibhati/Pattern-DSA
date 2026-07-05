# Top K Frequent Words (LeetCode 692)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/top-k-frequent-words/)**

---

## 📝 Problem Description

Given an array of strings `words` and an integer `k`, return the `k` most frequent strings.

Return the answer **sorted** by the frequency from highest to lowest. Sort the words with the same frequency by their **lexicographical order**.

---

## 💡 Intuition & Core Logic

To find the top `k` most frequent words in `O(N log k)` time, we can combine a **frequency map** and a **Min-Heap** of size `k` with a custom comparator.

1. **Calculate Frequencies**:
   - Use `unordered_map<string, int> freq` to count occurrences of each word.
2. **Min-Heap of Size k**:
   - Use a custom comparator `cmp` for the priority queue of `pair<int, string>` (representing `{frequency, word}`):
     - **Frequency comparison**: We want a min-heap on frequency, so if frequencies differ, return `a.first > b.first` (smaller frequency has higher priority to be popped first).
     - **Lexicographical comparison**: For equal frequencies, we want lexicographically smaller words to be retained in the heap. Therefore, lexicographically larger words should have higher priority to be popped first. So we return `a.second < b.second` when frequencies are equal.
   - Loop through the map: push elements to the heap. If heap size exceeds `k`, pop the top element.
3. **Reconstruct & Reverse**:
   - Pop elements one-by-one from the heap into `ans`. Since the heap pops the least frequent (and lexicographically larger for ties) first, the elements will be in reverse order.
   - Run `reverse(ans.begin(), ans.end())` to get the correct sorted order: highest frequency first, and lexicographically smaller first for ties.

---

## 🔄 Step-by-Step Dry Run

For `words = ["i", "love", "leetcode", "i", "love", "coding"]`, `k = 2`.

1. **Build Frequency Map**:
   - `"i"` -> 2
   - `"love"` -> 2
   - `"leetcode"` -> 1
   - `"coding"` -> 1

2. **Process Frequencies using Custom Heap (size limit `k = 2`)**:
   - Push `{2, "i"}` -> `pq = [{"i", 2}]`
   - Push `{2, "love"}` -> `pq = [{"love", 2}, {"i", 2}]` (top is `{"love", 2}` since `"love" > "i"` lexicographically)
   - Push `{1, "leetcode"}` -> `pq = [{"leetcode", 1}, {"love", 2}, {"i", 2}]`
     - Size is 3 (> 2). Pop top `{"leetcode", 1}` (lowest frequency).
     - `pq = [{"love", 2}, {"i", 2}]` (top is `{"love", 2}`)
   - Push `{1, "coding"}` -> `pq = [{"coding", 1}, {"love", 2}, {"i", 2}]`
     - Size is 3 (> 2). Pop top `{"coding", 1}` (lowest frequency).
     - `pq = [{"love", 2}, {"i", 2}]` (top is `{"love", 2}`)

3. **Construct Result**:
   - Pop `{"love", 2}` -> `ans = ["love"]`
   - Pop `{"i", 2}` -> `ans = ["love", "i"]`
   - Reverse `ans` -> `ans = ["i", "love"]` (correct output: highest frequency first, alphabetical for ties).

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first != b.first)
                return a.first > b.first;      // smaller frequency has higher priority

            return a.second < b.second;        // lexicographically smaller is better,
                                               // so larger word stays at the top
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        // Count frequency
        for (string &word : words)
            freq[word]++;

        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       cmp> pq;

        for (auto &it : freq) {
            pq.push({it.second, it.first});

            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N log k)` — Counting frequencies takes `O(N * L)` where `L` is the average length of a word. Inserting all unique words into the heap takes `O(U * L log k)` where `U` is the number of unique words. Reversing the output takes `O(k * L)`.
- **Space Complexity**: `O(N * L)` — To store words in the frequency map and heap.
