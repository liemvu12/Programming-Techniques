// 2558. Take Gifts From the Richest Pile
// You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:
// Choose the pile with the maximum number of gifts.
// If there is more than one pile with the maximum number of gifts, choose any.
// Reduce the number of gifts in the pile to the floor of the square root of the original number of gifts in the pile.
// Return the number of gifts remaining after k seconds.

// Example 1:
// Input: gifts = [25,64,9,4,100], k = 4
// Output: 29
// Explanation: 
// The gifts are taken in the following way:
// - In the first second, the last pile is chosen and 10 gifts are left behind.
// - Then the second pile is chosen and 8 gifts are left behind.
// - After that the first pile is chosen and 5 gifts are left behind.
// - Finally, the last pile is chosen again and 3 gifts are left behind.
// The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.

// Example 2:
// Input: gifts = [1,1,1,1], k = 4
// Output: 4
// Explanation: 
// In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile. 
// That is, you can't take any pile with you. 
// So, the total gifts remaining are 4.
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    long long *a;
    int size;
    int cap;
} MaxHeapLL;

static void heap_init(MaxHeapLL *h, int cap) {
    h->size = 0;
    h->cap = (cap > 0 ? cap : 1);
    h->a = (long long*)malloc(sizeof(long long) * h->cap);
}

static void heap_free(MaxHeapLL *h) {
    free(h->a);
    h->a = NULL;
    h->size = h->cap = 0;
}

static void heap_swap(long long *x, long long *y) {
    long long t = *x; *x = *y; *y = t;
}

static void heap_ensure(MaxHeapLL *h, int need) {
    if (need <= h->cap) return;
    int newCap = h->cap * 2;
    if (newCap < need) newCap = need;
    h->a = (long long*)realloc(h->a, sizeof(long long) * newCap);
    h->cap = newCap;
}

static void heap_push(MaxHeapLL *h, long long val) {
    heap_ensure(h, h->size + 1);
    int i = h->size++;
    h->a[i] = val;
    // sift up
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->a[p] >= h->a[i]) break;
        heap_swap(&h->a[p], &h->a[i]);
        i = p;
    }
}

static long long heap_top(const MaxHeapLL *h) {
    return h->size ? h->a[0] : 0;
}

static long long heap_pop(MaxHeapLL *h) {
    if (h->size == 0) return 0;
    long long ret = h->a[0];
    h->a[0] = h->a[--h->size];
    // sift down
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

long long pickGifts(int* gifts, int giftsSize, int k) {
    MaxHeapLL h; heap_init(&h, giftsSize);
    for (int i = 0; i < giftsSize; ++i) heap_push(&h, (long long)gifts[i]);

    for (int t = 0; t < k; ++t) {
        long long x = heap_pop(&h);
        long long r = (long long)(sqrt((double)x)); // floor(sqrt(x))
        heap_push(&h, r);
    }

    long long sum = 0;
    while (h.size) sum += heap_pop(&h);
    heap_free(&h);
    return sum;
}

