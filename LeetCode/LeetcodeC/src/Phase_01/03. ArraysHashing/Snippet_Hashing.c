// 1. Hiểu cách hoạt động của HashSet (Separate Chaining)
// Bạn không cần phải code lại, nhưng việc hiểu được ý tưởng cốt lõi là rất quan trọng. 
// HashSet trong snippet của bạn rất có thể được triển khai bằng kỹ thuật Separate Chaining (Nối kết riêng rẽ), 
// hoạt động dựa trên ý tưởng về một "mảng các danh sách liên kết".
// Hãy tưởng tượng bạn có một tủ đựng hồ sơ với 10 ngăn kéo, được đánh số từ 0 đến 9.

// Mảng chính (The Buckets - Các "Xô"): Tủ hồ sơ của bạn chính là mảng chính. 
// Kích thước của mảng này (số ngăn kéo) được quyết định trước.
// [Ngăn 0] ->
// [Ngăn 1] ->
// [Ngăn 2] ->
// ...
// [Ngăn 9] ->


// Hàm Hash (The Filing Rule - Quy tắc xếp hồ sơ): Bây giờ, bạn có một tập hồ sơ (các số nguyên) cần cất đi. 
// Để quyết định cất số N vào ngăn nào, bạn dùng một quy tắc đơn giản gọi là hàm hash. 
// Một hàm hash phổ biến là phép toán modulo (chia lấy dư).

// vị_trí_ngăn = N % số_lượng_ngăn
// Ví dụ: Nếu bạn muốn cất số 25, bạn sẽ tính 25 % 10 = 5. Vậy hồ sơ số 25 sẽ được cho vào Ngăn 5.
// Nếu bạn muốn cất số 17, bạn sẽ tính 17 % 10 = 7. Hồ sơ số 17 sẽ vào Ngăn 7.


// Xử lý xung đột (Collision Handling): Vấn đề xảy ra khi hai số khác nhau lại cùng được chỉ định vào một ngăn.

// Ví dụ: Số 35 cũng sẽ được tính là 35 % 10 = 5. Ngăn 5 đã có hồ sơ 25 rồi! Đây gọi là một sự xung đột (collision).
// Giải pháp (Separate Chaining): Thay vì chỉ để một hồ sơ trong mỗi ngăn, mỗi ngăn sẽ chứa một danh sách liên kết (linked list). 
// Khi có một hồ sơ mới cần cất vào ngăn đã có hồ sơ cũ, bạn chỉ cần móc nối hồ sơ mới vào danh sách liên kết đó.

// Tủ hồ sơ của bạn bây giờ sẽ trông như thế này:
// [Ngăn 0] -> (danh sách rỗng)
// ...
// [Ngăn 5] -> [Hồ sơ 25] -> [Hồ sơ 35] -> [Hồ sơ 5] -> NULL
// ...
// [Ngăn 7] -> [Hồ sơ 17] -> [Hồ sơ 7] -> NULL
// ...



// Tóm tắt các thao tác:

// Thêm một số (Add):
// Dùng hàm hash để tính ra chỉ số index (số ngăn).
// Đi đến mảng[index].
// Duyệt qua danh sách liên kết ở đó để chắc chắn số này chưa tồn tại (HashSet không cho phép trùng lặp).
// Nếu chưa có, thêm số đó vào đầu danh sách liên kết.


// Kiểm tra tồn tại (Contains):
// Dùng hàm hash để tính ra chỉ số index.
// Đi đến mảng[index].
// Duyệt qua danh sách liên kết và tìm xem có số đó không.


// Xóa một số (Remove):
// Dùng hàm hash để tính ra chỉ số index.
// Đi đến mảng[index].
// Tìm và xóa nút tương ứng trong danh sách liên kết.



// Kết luận: Bằng cách này, thay vì phải duyệt qua toàn bộ các số đã lưu, 
// bạn chỉ cần duyệt qua một danh sách liên kết nhỏ tại "ngăn" tương ứng. 
// Nếu hàm hash đủ tốt và kích thước mảng hợp lý, các danh sách này sẽ rất ngắn, 
// giúp thao tác tìm kiếm, thêm, xóa cực kỳ nhanh (trung bình là O(1)).

// 2. Viết hàm đếm tần suất ký tự
// Đây là phần thực hành quan trọng, áp dụng ý tưởng "hashing" đơn giản nhất: dùng chính ký tự để làm "key" cho một mảng đếm.
// Mở file main.c của bạn và thêm vào nội dung sau:
// Mã nguồn main.c

#include <stdio.h>
#include <string.h> // Để dùng strlen
#include <ctype.h>  // Để dùng tolower

/**
 * @brief Đếm và in ra tần suất xuất hiện của mỗi ký tự chữ cái trong chuỗi.
 *        Hàm này không phân biệt chữ hoa và chữ thường.
 * 
 * @param str Chuỗi đầu vào (const char*).
 */
void print_char_frequency(const char* str) {
    // 1. Khởi tạo mảng đếm cho 26 chữ cái (a-z)
    //    Tất cả các phần tử được tự động khởi tạo bằng 0.
    int counts[26] = {0};

    printf("Phan tich chuoi: \"%s\"\n", str);

    // 2. Duyệt qua từng ký tự của chuỗi
    for (int i = 0; i < strlen(str); i++) {
        char current_char = str[i];
        
        // Chuyển ký tự về dạng chữ thường để xử lý đồng nhất
        char lower_char = tolower(current_char);

        // 3. Kiểm tra xem ký tự có phải là chữ cái (a-z) hay không
        if (lower_char >= 'a' && lower_char <= 'z') {
            // 4. "Hash" ký tự thành một chỉ số mảng (0-25)
            //    'a' -> 0, 'b' -> 1, ..., 'z' -> 25
            int index = lower_char - 'a';
            
            // Tăng biến đếm tại chỉ số đó
            counts[index]++;
        }
    }

    // 5. In kết quả
    printf("--- Tan suat xuat hien cac ky tu ---\n");
    for (int i = 0; i < 26; i++) {
        // Chỉ in những ký tự có xuất hiện (biến đếm > 0)
        if (counts[i] > 0) {
            // Chuyển chỉ số ngược lại thành ký tự
            char character = 'a' + i;
            printf("Ky tu '%c' xuat hien %d lan\n", character, counts[i]);
        }
    }
}

int main() {
    const char* test_string = "The quick brown fox jumps over the lazy dog";
    
    print_char_frequency(test_string);

    printf("\n"); // In thêm một dòng trống cho đẹp

    const char* another_string = "Hello World! This is a simple test.";
    print_char_frequency(another_string);

    return 0;
}

// Giải thích chi tiết mã nguồn:
// int counts[26] = {0};: Đây là mảng đếm của chúng ta. Vị trí counts[0] sẽ lưu số lần xuất hiện của ký tự 'a', 
// counts[1] cho 'b', và cứ thế đến counts[25] cho 'z'. Việc = {0} đảm bảo tất cả 26 phần tử đều được khởi tạo bằng 0.
// for (int i = 0; i < strlen(str); i++): Vòng lặp tiêu chuẩn để duyệt qua mọi ký tự trong chuỗi str.
// char lower_char = tolower(current_char);: Để xử lý "Hello" và "hello" như nhau, 
// ta chuyển mọi ký tự về dạng chữ thường trước khi đếm.
// if (lower_char >= 'a' && lower_char <= 'z'): Bước này để đảm bảo chúng ta chỉ đếm các ký tự chữ cái, 
// bỏ qua khoảng trắng, dấu chấm, dấu chấm than, v.v.
// int index = lower_char - 'a';: Đây là "phép màu" của phương pháp này. 
// Trong C, các ký tự được biểu diễn bằng mã ASCII, và các chữ cái được xếp liền kề nhau.

// 'a' - 'a' sẽ cho kết quả là 0.
// 'b' - 'a' sẽ cho kết quả là 1.
// 'z' - 'a' sẽ cho kết quả là 25.
// Chúng ta đã biến đổi một ký tự thành một chỉ số mảng hợp lệ một cách hoàn hảo. 
// Đây là dạng hashing đơn giản và hiệu quả nhất cho trường hợp này.

// counts[index]++;: Tăng giá trị tại vị trí tương ứng trong mảng đếm.
// Vòng lặp cuối cùng: Sau khi đã đếm xong, chúng ta duyệt qua mảng counts từ 0 đến 25. 
// Nếu counts[i] lớn hơn 0, có nghĩa là ký tự tương ứng đã xuất hiện, và chúng ta in nó ra. Phép biến đổi ngược char character = 'a' + i; giúp lấy lại ký tự từ chỉ số.


