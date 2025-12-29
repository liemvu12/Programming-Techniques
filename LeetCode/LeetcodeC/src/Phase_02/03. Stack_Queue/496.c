// 496. Next Greater Element I
// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. 
// If there is no next greater element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
 
// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

// Example 2:
// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
// }
// => TRÁNH CÁC VÒNG FOR, IF CHỒNG NHAU, NÊN TÁCH RIÊNG CHO TỪNG CHỨC NĂNG .
// => GIÁ TRỊ KHỞI TẠO CỦA BIẾN LÀ GIÁ TRỊ BIẾN NÓ Ở CASE "XẤU NHẤT".

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *ans = (int*)malloc(sizeof(int)*nums1Size);
    *returnSize = nums1Size;

    for (int i = 0; i < nums1Size; i++)
    {
        ans[i] = -1;
        int indexStart = -1 ; 
        // Tìm địa chỉ của x trong nums2. 
        for (int j = 0; j < nums2Size; j++)
        {
            if(nums2[j] == nums1[i]) {
                indexStart = j;
                break;
            }
        }

        // Nếu không tìm thấy trong nums2 (theo đề thường không xảy ra), bỏ qua
        if (indexStart == -1) {
            ans[i] = -1;
            continue;
        }

        // Tìm giá trị đầu tiên lớn hơn X trong nums2.
        for (int k = indexStart + 1; k < nums2Size; k++) 
        {
            if (nums2[k] > nums2[indexStart])
            {
                ans[i] = nums2[k];
                break;
            }
        }
    }
    return ans;
}