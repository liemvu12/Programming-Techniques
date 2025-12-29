#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
}; 

// Hàm nội bộ để tạo nút mới
static struct ListNode* create_node(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* list_add_node_end(struct ListNode* head, int val) {
    struct ListNode* newNode = create_node(val);
    if (head == NULL) {
        return newNode;
    }
    struct ListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void list_print(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

void list_release(struct ListNode** head_ref) {
    struct ListNode* current = *head_ref;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    *head_ref = NULL; // Cập nhật con trỏ gốc về NULL
}

struct ListNode* list_reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *cur = head;
    while (cur) {
        struct ListNode *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

bool list_has_cycle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    struct ListNode* myList = NULL; // Khởi tạo danh sách rỗng

    printf("--- XAY DUNG DANH SACH ---\n");
    // Sử dụng hàm add_node để xây dựng danh sách
    myList = list_add_node_end(myList, 10);
    myList = list_add_node_end(myList, 20);
    myList = list_add_node_end(myList, 30);
    myList = list_add_node_end(myList, 40);

    printf("Danh sach ban dau: ");
    list_print(myList);
    printf("-> Giai thich: Da them 4 phan tu vao cuoi danh sach.\n\n");

    printf("--- THUC HIEN DAO NGUOC ---\n");
    myList = list_reverse(myList);
    printf("Danh sach sau khi dao nguoc: ");
    list_print(myList);
    printf("-> Giai thich: Ham list_reverse da dao chieu cac con tro next.\n\n");

    printf("--- GIAI PHONG BO NHO ---\n");
    list_release(&myList); // Sử dụng hàm giải phóng
    printf("Da goi list_release. Danh sach bay gio la: ");
    list_print(myList);
    printf("-> Giai thich: Toan bo bo nho da duoc giai phong va con tro myList da duoc set ve NULL.\n");

    return 0;
}