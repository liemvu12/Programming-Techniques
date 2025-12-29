// 21. Merge Two Sorted Lists
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

#include <stddef.h> // Để dùng NULL
#include <stdlib.h> // Để dùng malloc

// Định nghĩa cấu trúc ListNode (đã có trong tài liệu của bạn)
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * @brief Trộn hai danh sách liên kết đã sắp xếp thành một danh sách duy nhất.
 * @param list1 Con trỏ tới đầu danh sách thứ nhất.
 * @param list2 Con trỏ tới đầu danh sách thứ hai.
 * @return Con trỏ tới đầu của danh sách đã được trộn.
 */
// struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//     // 1. Khởi tạo
//     // Tạo một nút giả để đơn giản hóa việc xử lý cạnh (trường hợp danh sách rỗng ban đầu)
//     struct ListNode dummy;
//     dummy.val = 0; // Giá trị không quan trọng
//     dummy.next = NULL;

//     // Con trỏ 'current' sẽ theo dõi nút cuối cùng trong danh sách đã trộn
//     struct ListNode* current = &dummy;

//     // 2. Vòng lặp chính: Trộn hai danh sách khi cả hai đều còn phần tử
//     while (list1 != NULL && list2 != NULL) {
//         if (list1->val <= list2->val) {
//             // Nối nút từ list1 vào danh sách kết quả
//             current->next = list1;
//             // Di chuyển con trỏ của list1
//             list1 = list1->next;
//         } else {
//             // Nối nút từ list2 vào danh sách kết quả
//             current->next = list2;
//             // Di chuyển con trỏ của list2
//             list2 = list2->next;
//         }
//         // Di chuyển con trỏ 'current' đến nút cuối cùng mới
//         current = current->next;
//     }

//     // 3. Xử lý phần còn lại: Nối phần còn lại của danh sách chưa rỗng
//     if (list1 != NULL) {
//         current->next = list1;
//     } else {
//         current->next = list2;
//     }

//     // 4. Kết quả: Danh sách thực sự bắt đầu sau nút giả
//     return dummy.next;
// }

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.next = NULL;
    dummy.val = 0;

    struct ListNode* current = &dummy;

    while(list1 != NULL && list2 != NULL){
        if(list1->val >= list2->val){
            current->next = list2 ; 
            list2 = list2->next; 
        }else{
            current->next = list1 ; 
            list1 = list1->next;             
        }
        current = current->next; // Di chuyển con trỏ 'current' đến nút cuối cùng mới.
    }

    if (list1 == NULL){
        current->next = list2;
    }else{
        current->next = list1;
    }

    return dummy.next;   
}