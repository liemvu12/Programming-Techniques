#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // Để dùng CHAR_BIT

// 1. Các hàm thao tác bit phổ biến

/**
 * @brief Lấy giá trị của bit tại vị trí pos (0-indexed từ phải sang trái).
 * @return true nếu bit là 1, false nếu bit là 0.
 */
bool get_bit(int n, int pos) {
    return (n >> pos) & 1;
}

/**
 * @brief Thiết lập (set) bit tại vị trí pos lên 1.
 * @return Số nguyên mới sau khi đã set bit.
 */
int set_bit(int n, int pos) {
    return n | (1 << pos);
}

/**
 * @brief Xóa (clear) bit tại vị trí pos về 0.
 * @return Số nguyên mới sau khi đã xóa bit.
 */
int clear_bit(int n, int pos) {
    return n & (~(1 << pos));
}

/**
 * @brief Đảo (toggle) giá trị của bit tại vị trí pos (0->1, 1->0).
 * @return Số nguyên mới sau khi đã đảo bit.
 */
int toggle_bit(int n, int pos) {
    return n ^ (1 << pos);
}

// Hàm tiện ích để in ra dạng nhị phân của một số nguyên
void print_binary(int n) {
    // CHAR_BIT là số bit trong một byte (thường là 8)
    for (int i = sizeof(n) * CHAR_BIT - 1; i >= 0; i--) {
        putchar((n & (1 << i)) ? '1' : '0');
        if (i % 4 == 0) putchar(' '); // Ngăn cách cho dễ đọc
    }
    printf("\n");
}


int main() {
    // 2. Tạo số ví dụ và minh họa
    int number = 10; // Dạng nhị phân là 0...1010
    
    printf("So vi du: %d\n", number);
    printf("Dang nhi phan: ");
    print_binary(number);
    printf("\n");

    // Minh họa get_bit
    int pos_get = 1;
    bool bit_val = get_bit(number, pos_get);
    printf("Ket qua cua get_bit(%d, %d): %s\n", number, pos_get, bit_val ? "true" : "false");
    printf("-> Giai thich: Bit o vi tri %d cua 10 (1010) la 1.\n\n", pos_get);

    // Minh họa set_bit
    int pos_set = 2;
    int num_set = set_bit(number, pos_set);
    printf("Ket qua cua set_bit(%d, %d): %d\n", number, pos_set, num_set);
    printf("Dang nhi phan cua %d: ", num_set);
    print_binary(num_set);
    printf("-> Giai thich: Bat bit o vi tri %d cua 10 (1010) len 1, ta duoc 14 (1110).\n\n", pos_set);

    // Minh họa clear_bit
    int pos_clear = 3;
    int num_clear = clear_bit(number, pos_clear);
    printf("Ket qua cua clear_bit(%d, %d): %d\n", number, pos_clear, num_clear);
    printf("Dang nhi phan cua %d: ", num_clear);
    print_binary(num_clear);
    printf("-> Giai thich: Tat bit o vi tri %d cua 10 (1010) ve 0, ta duoc 2 (0010).\n\n", pos_clear);

    // Minh họa toggle_bit
    int pos_toggle = 0;
    int num_toggle = toggle_bit(number, pos_toggle);
    printf("Ket qua cua toggle_bit(%d, %d): %d\n", number, pos_toggle, num_toggle);
    printf("Dang nhi phan cua %d: ", num_toggle);
    print_binary(num_toggle);
    printf("-> Giai thich: Dao bit o vi tri %d cua 10 (1010) tu 0 thanh 1, ta duoc 11 (1011).\n\n", pos_toggle);

    return 0;
}