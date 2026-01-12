// https://leetcode.com/problems/binary-search/description/
// 704. Binary Search

// Given an array of integers nums which is sorted in ascending order, and an integer target,
// write a function to search target in nums. 
// If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

// Example 2:
// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
// Code_______________
// int search(int* nums, int numsSize, int target) {  }

int search(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1; // khớp giữa size và index. 
    while (l <= r) { // điều kiện thực thi là <=, tránh case input numsize = 1.
        int m = l + (r - l) / 2;
        if (nums[m] == target) return m;
        if (nums[m] < target)  l = m + 1; // bỏ qua m để tránh case l=1, r=2, m=1 → lại l=m=1 ⇒ kẹt (không tiến).
        else                   r = m - 1; // bỏ qua m để tránh case l=1, r=2, m=1 → lại l=m=1 ⇒ kẹt (không tiến).
    }
    return -1;
}