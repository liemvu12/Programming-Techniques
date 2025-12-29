// https://leetcode.com/problems/search-insert-position/description/
// 35. Search Insert Position
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4

// Code_______________
// int searchInsert(int* nums, int numsSize, int target) { }

int searchInsert(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1;
    int m = 0;
    while (r >= l)
    {
        m = (r - l)/2 + l; 
        if (nums[m] == target)
        {
            return m;
        }
        if (nums[m] < target)
        {   
            l = m +1 ;
        }else r = m - 1; 
    }
    return l; // xét ở vòng loop cuối xem kịch bản là như thế nào, l/r lần lượt bằng gì, áp dụng vào 3 example xem có đúng chưa.
}