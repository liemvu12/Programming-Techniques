#include <stdio.h>
#include <stdlib.h>

// 1. Định nghĩa cấu trúc TreeNode
/**
 * @brief Định nghĩa cấu trúc cho một nút trong cây nhị phân.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 2. Các hàm tiện ích và các hàm duyệt cây phổ biến

/**
 * @brief Hàm tiện ích: Tạo một nút mới.
 */
struct TreeNode* createNode_Tree(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * @brief Hàm phổ biến: Duyệt cây theo thứ tự trước (Pre-order: Node -> Left -> Right).
 */
void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

/**
 * @brief Hàm phổ biến: Duyệt cây theo thứ tự giữa (In-order: Left -> Node -> Right).
 */
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

/**
 * @brief Hàm phổ biến: Duyệt cây theo thứ tự sau (Post-order: Left -> Right -> Node).
 */
void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->val);
}

/**
 * @brief Hàm tiện ích: Giải phóng bộ nhớ của cây (dùng duyệt sau).
 */
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // 3. Tạo cây ví dụ và minh họa
    /*
            Cây ví dụ:
                4
               / \
              2   6
             / \ / \
            1  3 5  7
    */
    struct TreeNode* root = createNode_Tree(4);
    root->left = createNode_Tree(2);
    root->right = createNode_Tree(6);
    root->left->left = createNode_Tree(1);
    root->left->right = createNode_Tree(3);
    root->right->left = createNode_Tree(5);
    root->right->right = createNode_Tree(7);

    printf("Cay nhi phan vi du da duoc tao.\n\n");

    printf("Ket qua cua preorderTraversal: ");
    preorderTraversal(root);
    printf("\n");
    printf("-> Giai thich: Duyet theo thu tu Goc -> Trai -> Phai (4 -> 2 -> 1 -> 3 -> 6 -> 5 -> 7).\n\n");

    printf("Ket qua cua inorderTraversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("-> Giai thich: Duyet theo thu tu Trai -> Goc -> Phai (1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7). Voi cay tim kiem nhi phan, phep duyet nay cho ra day duoc sap xep.\n\n");

    printf("Ket qua cua postorderTraversal: ");
    postorderTraversal(root);
    printf("\n");
    printf("-> Giai thich: Duyet theo thu tu Trai -> Phai -> Goc (1 -> 3 -> 2 -> 5 -> 7 -> 6 -> 4). Thuong dung de xoa cay.\n\n");
    
    // Dọn dẹp bộ nhớ
    freeTree(root);
    printf("Da giai phong bo nho cho cay.\n");

    return 0;
}