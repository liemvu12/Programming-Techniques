// 349. Intersection of Two Arrays
// Given two integer arrays nums1 and nums2, return an array of their intersection. 
// Each element in the result must be unique and you may return the result in any order.

// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]

// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = 0; // MUST: khởi tạo trước

    int max = nums1[0];
    // lấy max trên cả nums1 và nums2
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] > max) max = nums1[i];
    }
    for (int i = 0; i < nums2Size; i++) {
        if (nums2[i] > max) max = nums2[i];
    }

    // giả định tất cả giá trị >= 0
    // calloc max + 1 do index mong muốn = max nhưng nếu chỉ khai báo max thì index chỉ có max - 1 vì tốn slot cho index 0.
    int* ans = (int*)calloc(max + 1, sizeof(int)); // 0: chưa thấy, 1: thấy ở nums1, 2: intersection

    // đánh dấu unique từ nums1
    for (int j = 0; j < nums1Size; j++) {
        int v = nums1[j];
        if (ans[v] == 0) ans[v] = 1;
    }

    // nâng trạng thái nếu cũng có trong nums2
    for (int k = 0; k < nums2Size; k++) {
        int v = nums2[k];
        if (ans[v] == 1) ans[v] = 2;
    }

    // đếm kết quả: duyệt tới <= max
    for (int m = 0; m <= max; m++) {
        if (ans[m] == 2) (*returnSize)++;
    }

    int *output = (int*)malloc(sizeof(int) * (*returnSize));
    int index = 0;
    for (int m = 0; m <= max; m++) { // <= là do bây giờ có max +1 phần tử, duyệt hết thì phải <=.
        if (ans[m] == 2) {
            output[index++] = m; // ghi GIÁ TRỊ m
        }
    }

    free(ans);
    return output;
}
