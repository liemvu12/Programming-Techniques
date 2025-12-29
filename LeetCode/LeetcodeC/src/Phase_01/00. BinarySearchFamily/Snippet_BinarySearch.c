#include <stdio.h>
#include <stdlib.h> // Để sử dụng qsort

/**
 * @brief Hàm so sánh cho qsort để sắp xếp mảng số nguyên tăng dần.
 * 
 * @param a Con trỏ void* tới phần tử thứ nhất.
 * @param b Con trỏ void* tới phần tử thứ hai.
 * @return int 
 *         < 0 nếu *a < *b
 *         = 0 nếu *a == *b
 *         > 0 nếu *a > *b
 */
int compare_int(const void *a, const void *b) {
    int val1 = *(const int *)a;
    int val2 = *(const int *)b;
    if (val1 < val2) {
        return -1;
    } else if (val1 > val2) {
        return 1;
    } else {
        return 0;
    }
}

// 3. Bộ ba hàm Binary Search family

/**
 * @brief Tìm kiếm vị trí của phần tử đầu tiên KHÔNG NHỎ HƠN key.
 *        Tương đương với std::lower_bound trong C++.
 * 
 * @param arr Mảng đã được sắp xếp.
 * @param size Kích thước của mảng.
 * @param key Giá trị cần tìm.
 * @return int Chỉ số của phần tử đầu tiên >= key. Trả về size nếu mọi phần tử đều nhỏ hơn key.
 */
int lower_bound_int(const int arr[], int size, int key) {
    int low = 0, high = size - 1;
    int ans = size; // Giá trị mặc định nếu không tìm thấy

    while (low <= high) {
        int mid = low + (high - low) / 2; // Tránh tràn số khi low, high lớn
        if (arr[mid] >= key) {
            ans = mid;       // Tìm thấy một ứng viên, thử tìm vị trí tốt hơn ở bên trái
            high = mid - 1;
        } else {
            low = mid + 1;   // Phần tử hiện tại quá nhỏ, tìm ở bên phải
        }
    }
    return ans;
}

/**
 * @brief Tìm kiếm vị trí của phần tử đầu tiên LỚN HƠN key.
 *        Tương đương với std::upper_bound trong C++.
 * 
 * @param arr Mảng đã được sắp xếp.
 * @param size Kích thước của mảng.
 * @param key Giá trị cần tìm.
 * @return int Chỉ số của phần tử đầu tiên > key. Trả về size nếu không có phần tử nào lớn hơn key.
 */
int upper_bound_int(const int arr[], int size, int key) {
    int low = 0, high = size - 1;
    int ans = size; // Giá trị mặc định nếu không tìm thấy

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > key) {
            ans = mid;       // Tìm thấy một ứng viên, thử tìm vị trí tốt hơn ở bên trái
            high = mid - 1;
        } else {
            low = mid + 1;   // Phần tử hiện tại không lớn hơn key, tìm ở bên phải
        }
    }
    return ans;
}

/**
 * @brief Tìm kiếm chính xác một giá trị trong mảng.
 * 
 * @param arr Mảng đã được sắp xếp.
 * @param size Kích thước của mảng.
 * @param key Giá trị cần tìm.
 * @return int Chỉ số của phần tử nếu tìm thấy, ngược lại trả về -1.
 */
int binary_search_int(const int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid; // Tìm thấy
        } else if (arr[mid] < key) {
            low = mid + 1; // Tìm ở nửa bên phải
        } else {
            high = mid - 1; // Tìm ở nửa bên trái
        }
    }
    return -1; // Không tìm thấy
}


int main() {
    // 4. Tạo mảng ví dụ và in kết quả
    int arr[] = {2, 3, 5, 5, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mang vi du: {2, 3, 5, 5, 8, 10}\n");
    printf("Chi so:      0  1  2  3  4  5\n\n");

    // Mảng này đã được sắp xếp. Nếu chưa, ta sẽ gọi qsort như sau:
    // qsort(arr, n, sizeof(int), compare_int);

    // Thực hiện tìm kiếm và in kết quả
    int key1 = 5;
    int res_lower = lower_bound_int(arr, n, key1);
    printf("Ket qua cua lower_bound(arr, 6, 5): %d\n", res_lower);
    printf("-> Giai thich: Chi so dau tien cua phan tu >= 5 la %d (gia tri arr[%d] = %d).\n\n", res_lower, res_lower, arr[res_lower]);

    int res_upper = upper_bound_int(arr, n, key1);
    printf("Ket qua cua upper_bound(arr, 6, 5): %d\n", res_upper);
    printf("-> Giai thich: Chi so dau tien cua phan tu > 5 la %d (gia tri arr[%d] = %d).\n\n", res_upper, res_upper, arr[res_upper]);

    int key2 = 7;
    int res_binary = binary_search_int(arr, n, key2);
    printf("Ket qua cua binary_search(arr, 6, 7): %d\n", res_binary);
    printf("-> Giai thich: Khong tim thay gia tri 7 trong mang, nen tra ve -1.\n");

    return 0;
}