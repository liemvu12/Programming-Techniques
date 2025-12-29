// https://leetcode.com/problems/valid-parentheses/description/
// 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

// Example 4:
// Input: s = "([])"
// Output: true

// Example 5:
// Input: s = "([)]"
// Output: false

// Code_______________
// size_t n = strlen(s);
// bool isValid(char* s) { }

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    size_t n = strlen(s);
    if ((n % 2) == 1) return false;

    char *st = (char*)malloc(n*sizeof(char));
    size_t top = 0;
    char c;

    for (size_t i = 0; i < n; i++)
    {
        c = s[i];
        if (c == '(') st[top++] = ')'; // top++ gán trước dịch sau.
        else if (c == '[') st[top++] = ']';
        else if (c == '{') st[top++] = '}';
        else {
            if (top == 0 || st[--top] != c){ // --top, phải lùi lại do ở case ++ cuối top đã bị dịch lên.
                free(st);
                return false;
            }
        }
    }
    // stack ở đây là cách vận hành, stack tính từ point top chứ k cần care đến cả kiến trúc vì sau này sẽ free hết.
    free(st);
    bool result = false;
    if (top == 0) result = true;
    return result;
}
