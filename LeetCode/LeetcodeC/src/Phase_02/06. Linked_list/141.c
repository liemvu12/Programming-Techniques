// 141. Linked List Cycle
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
// Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.
 
// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.
#include <stdbool.h>

#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Đây chính là hàm hasCycle kinh điển
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // Điều kiện lặp: fast và fast->next phải tồn tại để fast có thể nhảy 2 bước
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Rùa đi 1 bước
        fast = fast->next->next;    // Thỏ đi 2 bước
        
        // Nếu Thỏ đuổi kịp Rùa, có vòng lặp
        if (slow == fast) {
            return true;
        }
    }
    
    // Nếu Thỏ về đích (NULL), không có vòng lặp
    return false;
}