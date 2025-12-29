// 167. Two Sum II - Input Array Is Sorted
// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
// find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] 
// where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
// The tests are generated such that there is exactly one solution. You may not use the same element twice.
// Your solution must use only constant extra space.

// Example 1:
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

// Example 2:
// Input: numbers = [2,3,4], target = 6
// Output: [1,3]
// Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

// Example 3:
// Input: numbers = [-1,0], target = -1
// Output: [1,2]
// Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
//     int left = 0;
//     int right = numbersSize - 1;
    
//     // Cấp phát bộ nhớ cho mảng kết quả
//     int* result = (int*)malloc(2 * sizeof(int));
//     *returnSize = 2;

//     while (left < right) {
//         int currentSum = numbers[left] + numbers[right];
        
//         if (currentSum == target) {
//             result[0] = left + 1; // LeetCode yêu cầu chỉ số bắt đầu từ 1
//             result[1] = right + 1;
//             return result;
//         } else if (currentSum < target) {
//             // Tổng quá nhỏ, cần số lớn hơn -> dịch con trỏ trái
//             left++;
//         } else { // currentSum > target
//             // Tổng quá lớn, cần số nhỏ hơn -> dịch con trỏ phải
//             right--;
//         }
//     }
    
//     // Trường hợp không tìm thấy (theo đề bài luôn có lời giải)
//     *returnSize = 0;
//     free(result);
//     return NULL;
// }

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int *ans = (int*)malloc(sizeof(int)*2);

    int left = 0;
    int right = numbersSize - 1 ;

    while (left < right )
    {
        int currentSum = numbers[left] + numbers[right] ;
        if(currentSum == target){
            ans[0] = left + 1; 
            ans[1] = right + 1;
            return ans; 
        }else if(currentSum > target){
            right--;
        }else{
            left++;
        }
    }
    *returnSize = 0;
    free(ans);
    return NULL;  
    
}