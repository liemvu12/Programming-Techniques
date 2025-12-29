#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUE_MAX_SIZE 5 // Chọn kích thước nhỏ để dễ thấy hiệu ứng "quấn"

// Định nghĩa cấu trúc Queue vòng
typedef struct {
    int items[QUEUE_MAX_SIZE];
    int head;   // Chỉ số của phần tử đầu hàng (để dequeue)
    int tail;   // Chỉ số của vị trí trống tiếp theo (để enqueue)
    int size;   // Số lượng phần tử hiện tại trong queue
} Queue;

// Hàm khởi tạo một Queue mới
Queue* queue_create() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        perror("Failed to allocate memory for queue");
        return NULL;
    }
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return q;
}

// Kiểm tra Queue có rỗng không
int queue_is_empty(const Queue* q) {
    return q->size == 0;
}

// Kiểm tra Queue có đầy không
int queue_is_full(const Queue* q) {
    return q->size == QUEUE_MAX_SIZE;
}

// Thêm một phần tử vào cuối Queue (enqueue)
void queue_enqueue(Queue* q, int value) {
    // Pitfall: Kiểm tra queue đầy trước khi enqueue
    if (queue_is_full(q)) {
        printf("Error: Queue overflow! Khong the enqueue %d.\n", value);
        return;
    }
    // Chú ý: tail là vị trí sẽ thêm vào tiếp theo
    q->items[q->tail] = value;
    // Đây là lúc tail "quấn" quanh mảng
    q->tail = (q->tail + 1) % QUEUE_MAX_SIZE;
    q->size++;
    printf("Enqueued %d vao queue. (head=%d, tail=%d, size=%d)\n", value, q->head, q->tail, q->size);
}

// Lấy một phần tử ra khỏi đầu Queue (dequeue)
int queue_dequeue(Queue* q) {
    // Pitfall: Kiểm tra queue rỗng trước khi dequeue
    if (queue_is_empty(q)) {
        printf("Error: Queue underflow! Queue dang rong.\n");
        return INT_MIN;
    }
    int dequeued_value = q->items[q->head];
    // Đây là lúc head "quấn" quanh mảng
    q->head = (q->head + 1) % QUEUE_MAX_SIZE;
    q->size--;
    printf("Dequeued %d khoi queue. (head=%d, tail=%d, size=%d)\n", dequeued_value, q->head, q->tail, q->size);
    return dequeued_value;
}

// Xem giá trị ở đầu Queue mà không lấy ra (front)
int queue_front(const Queue* q) {
    if (queue_is_empty(q)) {
        printf("Error: Queue is empty!\n");
        return INT_MIN;
    }
    return q->items[q->head];
}

// Hàm main để kiểm tra
int main() {
    printf("--- KIEM TRA QUEUE VONG ---\n");
    Queue* my_queue = queue_create();

    // Enqueue cho đến khi đầy
    queue_enqueue(my_queue, 10);
    queue_enqueue(my_queue, 20);
    queue_enqueue(my_queue, 30);
    queue_enqueue(my_queue, 40);
    queue_enqueue(my_queue, 50); // Queue đầy
    queue_enqueue(my_queue, 60); // Sẽ báo lỗi

    printf("\nPhan tu dau hang (front): %d\n\n", queue_front(my_queue)); // Dự kiến: 10

    // Dequeue vài phần tử để tạo chỗ trống
    queue_dequeue(my_queue); // Lấy ra 10
    queue_dequeue(my_queue); // Lấy ra 20

    printf("\nPhan tu dau hang moi: %d\n\n", queue_front(my_queue)); // Dự kiến: 30

    // Enqueue thêm để thấy tail "quấn" vòng
    // Lúc này head=2, tail=0 (vì 5 % 5 = 0), size=3
    queue_enqueue(my_queue, 60); // Thêm vào vị trí 0
    queue_enqueue(my_queue, 70); // Thêm vào vị trí 1

    printf("\n--- Trang thai cuoi cung cua Queue ---\n");
    while (!queue_is_empty(my_queue)) {
        queue_dequeue(my_queue);
    }
    
    free(my_queue);
    return 0;
}