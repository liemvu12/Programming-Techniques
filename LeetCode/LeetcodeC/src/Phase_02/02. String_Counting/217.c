// 217. Contains Duplicate
// Given an integer array nums, return true if any value appears at least twice in the array, 
// and return false if every element is distinct.

// Example 1:
// Input: nums = [1,2,3,1]
// Output: true
// Explanation:
// The element 1 occurs at the indices 0 and 3.

// Example 2:
// Input: nums = [1,2,3,4]
// Output: false
// Explanation:
// All elements are distinct.

// Example 3:
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

#include <string.h>
#include <stdbool.h>

bool containsDuplicate(int* nums, int numsSize) {
    int largest = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > largest)
        {
            largest = nums[i];
        }
    }
    
    int* ans = (int*)calloc(largest + 1, sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        ans[nums[i]]++;
        if(ans[nums[i]] > 1) return true;
    }
    
    return false;
}