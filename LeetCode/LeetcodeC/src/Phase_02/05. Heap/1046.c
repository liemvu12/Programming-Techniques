// 1046. Last Stone Weight
// You are given an array of integers stones where stones[i] is the weight of the ith stone.
// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. 
// Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the weight of the last remaining stone. If there are no stones left, return 0.

 

// Example 1:
// Input: stones = [2,7,4,1,8,1]
// Output: 1
// Explanation: 
// We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
// we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
// we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
// we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

// Example 2:
// Input: stones = [1]
// Output: 1


#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    long long *a;
    int size;   // số lượng phần tử hiện có trong heap
    int cap;    // dung lượng (capacity) của mảng lưu heap
} MaxHeapLL;

// Khởi tạo Max-heap với dung lượng ban đầu là cap
static void heap_init(MaxHeapLL *h, int cap) {
    h->size = 0;
    h->cap = (cap > 0 ? cap : 1);
    h->a = (long long*)malloc(sizeof(long long) * h->cap);  // cấp phát bộ nhớ cho mảng
}

// Giải phóng bộ nhớ đã cấp phát cho heap
static void heap_free(MaxHeapLL *h) {
    free(h->a);
    h->a = NULL;
    h->size = h->cap = 0;
}

// Hoán đổi giá trị giữa hai biến kiểu long long, hỗ trợ thao tác sift up/down trong heap
static void heap_swap(long long *x, long long *y) {
    long long t = *x; *x = *y; *y = t;
}

// Đảm bảo heap có đủ dung lượng để chứa ít nhất 'need' phần tử
// Nếu không đủ, tăng gấp đôi dung lượng hoặc tăng thẳng đến need nếu lớn hơn
static void heap_ensure(MaxHeapLL *h, int need) {
    if (need <= h->cap) return;
    int newCap = h->cap * 2;
    if (newCap < need) newCap = need;
    h->a = (long long*)realloc(h->a, sizeof(long long) * newCap);
    h->cap = newCap;
}

// Đẩy một phần tử mới vào Max-heap và duy trì tính chất heap
// Cụ thể: thêm phần tử vào cuối mảng, sau đó sift up để đưa phần tử đến vị trí thích hợp
static void heap_push(MaxHeapLL *h, long long val) {
    heap_ensure(h, h->size + 1); // đảm bảo dung lượng đủ
    int i = h->size++;
    h->a[i] = val;
    // sift up: so sánh với cha và đổi chỗ nếu phần tử cha nhỏ hơn để duy trì max-heap
    while (i > 0) {
        int p = (i - 1) / 2; // vị trí cha của node i
        if (h->a[p] >= h->a[i]) break; // nếu cha >= con thì heap đúng cấu trúc
        heap_swap(&h->a[p], &h->a[i]);
        i = p;
    }
}

// Lấy giá trị phần tử lớn nhất (root) trong heap mà không xóa nó
// Trả về 0 nếu heap rỗng
static long long heap_top(const MaxHeapLL *h) {
    return h->size ? h->a[0] : 0;
}

// Lấy và loại bỏ phần tử lớn nhất trong heap
// Thực hiện sift down để duy trì cấu trúc max-heap sau khi lấy root ra
// Trả về 0 nếu heap rỗng
static long long heap_pop(MaxHeapLL *h) {
    if (h->size == 0) return 0;
    long long ret = h->a[0]; // phần tử lớn nhất (root)
    h->a[0] = h->a[--h->size]; // đưa phần tử cuối lên root
    // sift down: so sánh node hiện tại với các con, đổi chỗ với con lớn nhất nếu cần thiết để giữ heap
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, best = i;
        if (l < h->size && h->a[l] > h->a[best]) best = l;
        if (r < h->size && h->a[r] > h->a[best]) best = r;
        if (best == i) break;
        heap_swap(&h->a[i], &h->a[best]);
        i = best;
    }
    return ret;
}


int lastStoneWeight(int* stones, int stonesSize) {
    MaxHeapLL h; heap_init(&h, stonesSize);
    for (int i = 0; i < stonesSize; ++i) {
        heap_push(&h, (long long)stones[i]);
    }
    while (h.size > 1) {
        long long x = heap_pop(&h);
        long long y = heap_pop(&h);
        if (x != y) heap_push(&h, x - y);
        // nếu x == y, cả hai đều vỡ hết, không push gì
    }
    int ans = (int)heap_top(&h);
    heap_free(&h);
    return ans; // nếu heap trống => ans = 0
}
