// 387. First Unique Character in a String
// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
 
// Example 1:
// Input: s = "leetcode"
// Output: 0
// Explanation:
// The character 'l' at index 0 is the first character that does not occur at any other index.

// Example 2:
// Input: s = "loveleetcode"
// Output: 2

// Example 3:
// Input: s = "aabb"
// Output: -1
#include <string.h>

int firstUniqChar(char* s) {
    size_t size_s = strlen(s);
    int alphabet[26]; 
    for (int i = 0; i < 26; i++)
    {
        alphabet[i] = 0;
    }
    
    for (int j = 0; j < size_s; j++)
    {
        alphabet[s[j] - 'a'] ++;
    }

    for (size_t k = 0; k < size_s; k++)
    {
        if(alphabet[s[k] - 'a'] == 1) return k;
    }
    
    return -1;
}