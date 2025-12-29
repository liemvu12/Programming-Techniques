#include <stdio.h>
#include <stdlib.h> // For malloc
#include <limits.h> // For INT_MIN

#define STACK_MAX_SIZE 10

// Định nghĩa cấu trúc Stack
typedef struct {
    int items[STACK_MAX_SIZE];
    int top; // Chỉ số của phần tử trên cùng, -1 nếu stack rỗng
} Stack;

// Hàm khởi tạo một Stack mới
Stack* stack_create() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        perror("Failed to allocate memory for stack");
        return NULL;
    }
    s->top = -1; // Khởi tạo stack rỗng
    return s;
}

// Kiểm tra Stack có rỗng không
int stack_is_empty(const Stack* s) {
    return s->top == -1;
}

// Kiểm tra Stack có đầy không
int stack_is_full(const Stack* s) {
    return s->top == STACK_MAX_SIZE - 1;
}

// Thêm một phần tử vào đỉnh Stack (push)
void stack_push(Stack* s, int value) {
    // Pitfall: Kiểm tra stack đầy trước khi push
    if (stack_is_full(s)) {
        printf("Error: Stack overflow! Khong the push %d.\n", value);
        return;
    }
    s->top++;
    s->items[s->top] = value;
    printf("Pushed %d vao stack.\n", value);
}

// Lấy một phần tử ra khỏi đỉnh Stack (pop)
int stack_pop(Stack* s) {
    // Pitfall: Kiểm tra stack rỗng trước khi pop
    if (stack_is_empty(s)) {
        printf("Error: Stack underflow! Stack dang rong.\n");
        return INT_MIN; // Trả về giá trị đặc biệt để báo lỗi
    }
    int popped_value = s->items[s->top];
    s->top--;
    return popped_value;
}

// Xem giá trị ở đỉnh Stack mà không lấy ra (peek/top)
int stack_peek(const Stack* s) {
    if (stack_is_empty(s)) {
        printf("Error: Stack is empty! Khong co phan tu nao de xem.\n");
        return INT_MIN;
    }
    return s->items[s->top];
}

// Hàm main để kiểm tra
int main() {
    printf("--- KIEM TRA STACK MANG ---\n");
    Stack* my_stack = stack_create();

    // Push vài phần tử
    stack_push(my_stack, 10);
    stack_push(my_stack, 20);
    stack_push(my_stack, 30);

    // In ra phần tử trên đỉnh
    printf("\nPhan tu tren dinh (top/peek): %d\n", stack_peek(my_stack)); // Dự kiến: 30

    // Pop một phần tử ra
    int popped = stack_pop(my_stack);
    printf("Da pop ra phan tu: %d\n", popped); // Dự kiến: 30

    // In lại phần tử trên đỉnh
    printf("Phan tu tren dinh moi: %d\n", stack_peek(my_stack)); // Dự kiến: 20
    
    // Pop tiếp
    popped = stack_pop(my_stack);
    printf("Da pop ra phan tu: %d\n", popped); // Dự kiến: 20
    
    // Pop nốt phần tử cuối cùng
    popped = stack_pop(my_stack);
    printf("Da pop ra phan tu: %d\n", popped); // Dự kiến: 10
    
    // Thử pop khi stack rỗng
    popped = stack_pop(my_stack); // Sẽ in ra lỗi "Stack underflow"

    free(my_stack); // Giải phóng bộ nhớ
    return 0;
}