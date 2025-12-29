#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút cây
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


// Hàm nội bộ để tạo nút mới
static struct TreeNode* create_node(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* bst_add_node(struct TreeNode* root, int val) {
    if (root == NULL) return create_node(val);
    if (val < root->val) {
        root->left = bst_add_node(root->left, val);
    } else if (val > root->val) {
        root->right = bst_add_node(root->right, val);
    }
    return root;
}

void bst_print_inorder(struct TreeNode* root) {
    if (root == NULL) return;
    bst_print_inorder(root->left);
    printf("%d ", root->val);
    bst_print_inorder(root->right);
}

bool bst_search(struct TreeNode* root, int val) {
    if (root == NULL) return false;
    if (root->val == val) return true;
    return val < root->val ? bst_search(root->left, val) : bst_search(root->right, val);
}

void bst_release(struct TreeNode** root_ref) {
    if (*root_ref == NULL) return;
    bst_release(&((*root_ref)->left));
    bst_release(&((*root_ref)->right));
    free(*root_ref);
    *root_ref = NULL;
}

int main() {
    struct TreeNode* myTree = NULL;

    printf("--- XAY DUNG CAY NHI PHAN TIM KIEM ---\n");
    // Sử dụng hàm add_node để xây dựng cây
    myTree = bst_add_node(myTree, 50);
    bst_add_node(myTree, 30);
    bst_add_node(myTree, 70);
    bst_add_node(myTree, 20);
    bst_add_node(myTree, 40);
    bst_add_node(myTree, 60);
    bst_add_node(myTree, 80);
    printf("Da them cac phan tu 50, 30, 70, 20, 40, 60, 80 vao cay.\n\n");
    
    printf("--- DUYET CAY (IN-ORDER) ---\n");
    printf("Ket qua duyet In-order: ");
    bst_print_inorder(myTree);
    printf("\n-> Giai thich: Duyet In-order tren BST luon cho ra day so da duoc sap xep tang dan.\n\n");

    printf("--- TIM KIEM PHAN TU ---\n");
    int key_to_find = 40;
    bool found = bst_search(myTree, key_to_find);
    printf("Ket qua tim kiem gia tri %d: %s\n", key_to_find, found ? "Tim thay" : "Khong tim thay");
    
    key_to_find = 99;
    found = bst_search(myTree, key_to_find);
    printf("Ket qua tim kiem gia tri %d: %s\n\n", key_to_find, found ? "Tim thay" : "Khong tim thay");

    printf("--- GIAI PHONG BO NHO ---\n");
    bst_release(&myTree);
    printf("Da goi bst_release. Gia tri goc cua cay bay gio la %s.\n", myTree == NULL ? "NULL" : "Not NULL");

    return 0;
}