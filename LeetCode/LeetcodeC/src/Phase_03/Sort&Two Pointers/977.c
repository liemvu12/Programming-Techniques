// 977. Squares of a Sorted Array
// Given an integer array nums sorted in non-decreasing order, 
// return an array of the squares of each number sorted in non-decreasing order.

// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

// 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
// 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
// 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
// So the maximum possible sum is 4.

// Example 2:
// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int sum = 0;
    for (int i = 0; i < numsSize ; i++)
    {
        nums[i] = nums[i] * nums[i];
    }

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i; j < numsSize; j++)
        {
            if(nums[i] > nums[j]){
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t; 
            }
        }
    }

    return nums;   
}