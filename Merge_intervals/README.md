# 📦 Merge Intervals Pattern

Merge Intervals is a pattern used to deal with overlapping intervals. Typically, intervals are sorted by start time, and then we iterate through them to merge or find intersections.

---

## 📝 Concept Cheatsheet

### Merge Intervals Template
```cpp
sort(intervals.begin(), intervals.end());
vector<vector<int>> merged;
merged.push_back(intervals[0]);or (int i = 1; i < intervals.size(); i++) {
    if (merged.back()[1] >= intervals[i][0]) {
        merged.back()[1] = max(merged.back()[1], intervals[i][1]);
    } else {
        merged.push_back(intervals[i]);
    }
}
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Check if Any Two Intervals Overlap** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://www.geeksforgeeks.org/check-if-any-two-intervals-overlap/) | [`0_is_intersect.cpp`](./0_is_intersect.cpp) | [Explanation & Dry Run](0_is_intersect.md) |
| 2 | **Merge Intervals** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/merge-intervals/) | [`1_merge_intervals_56.cpp`](./1_merge_intervals_56.cpp) | [Explanation & Dry Run](1_merge_intervals_56.md) |
| 3 | **Insert Interval** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/insert-interval/) | [`2_insert_interval_57.cpp`](./2_insert_interval_57.cpp) | [Explanation & Dry Run](2_insert_interval_57.md) |
| 4 | **Interval List Intersections** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/interval-list-intersections/) | [`3_interval_list_intersection_986.cpp`](./3_interval_list_intersection_986.cpp) | [Explanation & Dry Run](3_interval_list_intersection_986.md) |
| 5 | **Meeting Rooms II** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1) | [`4_min_meeting_rooms.cpp`](./4_min_meeting_rooms.cpp) | [Explanation & Dry Run](4_min_meeting_rooms.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*