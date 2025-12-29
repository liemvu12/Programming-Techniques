#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 1. Định nghĩa cấu trúc ListNode
/**
 * @brief Định nghĩa cấu trúc cho một nút trong danh sách liên kết đơn.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

// 2. Các hàm tiện ích và hàm kinh điển

/**
 * @brief Hàm tiện ích: Tạo một nút mới.
 */
struct ListNode* createNode_List(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Hàm tiện ích: In danh sách liên kết.
 */
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * @brief Hàm kinh điển: Đảo ngược một danh sách liên kết (phiên bản lặp).
 * @param head Con trỏ tới đầu danh sách.
 * @return Con trỏ tới đầu danh sách mới đã được đảo ngược.
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *cur = head;
    while (cur) {
        struct ListNode *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

/**
 * @brief Hàm kinh điển: Kiểm tra xem danh sách có vòng lặp hay không (thuật toán Rùa và Thỏ).
 * @param head Con trỏ tới đầu danh sách.
 * @return true nếu có vòng lặp, false nếu không.
 */
bool hasCycle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    // 3. Tạo danh sách ví dụ và minh họa
    
    // Ví dụ 1: Danh sách không có vòng lặp
    printf("--- VI DU 1: DAO NGUOC DANH SACH ---\n");
    struct ListNode* head = createNode_List(1);
    head->next = createNode_List(2);
    head->next->next = createNode_List(3);
    head->next->next->next = createNode_List(4);

    printf("Danh sach ban dau: ");
    printList(head);

    bool cycle_res1 = hasCycle(head);
    printf("Ket qua cua hasCycle(head): %s\n", cycle_res1 ? "true" : "false");
    printf("-> Giai thich: Danh sach khong co vong lap.\n\n");

    head = reverseList(head);
    printf("Danh sach sau khi dao nguoc: ");
    printList(head);
    printf("-> Giai thich: Phan tu cuoi (4) tro thanh dau, va cac con tro next duoc dao chieu.\n\n");
    
    // Dọn dẹp bộ nhớ cho danh sách 1
    // (Lưu ý: head bây giờ đang trỏ tới 4)
    struct ListNode* current = head;
    while(current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }

    // Ví dụ 2: Danh sách có vòng lặp
    printf("--- VI DU 2: KIEM TRA VONG LAP ---\n");
    struct ListNode* head_cycle = createNode_List(10);
    struct ListNode* node20 = createNode_List(20);
    struct ListNode* node30 = createNode_List(30);
    
    head_cycle->next = node20;
    node20->next = node30;
    node30->next = node20; // Tạo vòng lặp: 30 -> 20

    printf("Danh sach vi du 2: 10 -> 20 -> 30 -> 20...\n");
    bool cycle_res2 = hasCycle(head_cycle);
    printf("Ket qua cua hasCycle(head_cycle): %s\n", cycle_res2 ? "true" : "false");
    printf("-> Giai thich: Con tro 'fast' va 'slow' se gap nhau tai mot diem trong vong lap.\n");

    // Dọn dẹp bộ nhớ cho danh sách 2
    free(head_cycle);
    free(node20);
    free(node30);

    return 0;
}