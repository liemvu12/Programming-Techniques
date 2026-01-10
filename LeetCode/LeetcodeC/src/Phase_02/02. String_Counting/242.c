// 242. Valid Anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

#include <string.h>
#include <stdbool.h>

// bool isAnagram(char* s, char* t) {
//     int len_s = strlen(s);
//     int len_t = strlen(t);

//     // 1. Kiểm tra độ dài
//     if (len_s != len_t) {
//         return false;
//     }

//     // 2. Tạo mảng đếm cho 26 ký tự alphabet thường
//     int char_counts[26] = {0};

//     // 3. Đếm tần suất ký tự trong chuỗi s
//     for (int i = 0; i < len_s; i++) {
//         char_counts[s[i] - 'a']++;
//     }

//     // 4. Giảm tần suất dựa trên chuỗi t
//     for (int i = 0; i < len_t; i++) {
//         char_counts[t[i] - 'a']--;
//         // Tối ưu: Nếu tại bất kỳ thời điểm nào, số đếm bị âm,
//         // có nghĩa là t có ký tự mà s không có (hoặc có nhiều hơn).
//         if (char_counts[t[i] - 'a'] < 0) {
//             return false;
//         }
//     }
    
//     // 5. Nếu tất cả các bước trên đều qua, chúng là đảo chữ.
//     // Không cần phải duyệt lại mảng đếm vì tổng số lần tăng và giảm bằng nhau.
//     return true;
// }

bool isAnagram(char* s, char* t) {
    size_t size_s = strlen(s);
    size_t size_t = strlen(t);

    if (size_s != size_t)
    {
        return false;
    }
    
    int alphabet[26]; 
    for (int i = 0; i < 26; i++)
    {
        alphabet[i] = 0;
    }
    
    for (int j = 0; j < size_s; j++)
    {
        alphabet[s[j] - 'a'] ++;
    }

    for (int k = 0; k < size_t; k++)
    {
        alphabet[t[k] - 'a']--;
        if(alphabet[t[k] - 'a'] < 0) return false ; 
    }
    
    return true;
}