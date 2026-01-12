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


// Không dùng stdbool.h, không dùng NULL
// Trả về 1 nếu có vòng, 0 nếu không có vòng.

struct ListNode {
    int val;
    struct ListNode *next;
};

int hasCycle(struct ListNode *head) {
    if (head == 0) return 0;  // 0 là null pointer constant

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Điều kiện dừng dùng so sánh với 0 thay cho NULL
    while (fast != 0 && fast->next != 0) {
        slow = slow->next;           // đi 1 bước
        fast = fast->next->next;     // đi 2 bước
        if (slow == fast) {          // gặp nhau => có vòng
            return 1;
        }
    }
    return 0;                        // tới null => không có vòng
}
