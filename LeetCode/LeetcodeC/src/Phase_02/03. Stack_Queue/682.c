// 682. Baseball Game
// You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
// You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

// An integer x.
// Record a new score of x.
// '+'.
// Record a new score that is the sum of the previous two scores.
// 'D'.
// Record a new score that is the double of the previous score.
// 'C'.
// Invalidate the previous score, removing it from the record.
// Return the sum of all the scores on the record after applying all the operations.
// The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.

// Example 1:
// Input: ops = ["5","2","C","D","+"]
// Output: 30
// Explanation:
// "5" - Add 5 to the record, record is now [5].
// "2" - Add 2 to the record, record is now [5, 2].
// "C" - Invalidate and remove the previous score, record is now [5].
// "D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
// "+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
// The total sum is 5 + 10 + 15 = 30.

// Example 2:
// Input: ops = ["5","-2","4","C","D","9","+","+"]
// Output: 27
// Explanation:
// "5" - Add 5 to the record, record is now [5].
// "-2" - Add -2 to the record, record is now [5, -2].
// "4" - Add 4 to the record, record is now [5, -2, 4].
// "C" - Invalidate and remove the previous score, record is now [5, -2].
// "D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
// "9" - Add 9 to the record, record is now [5, -2, -4, 9].
// "+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
// "+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
// The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.

// Example 3:
// Input: ops = ["1","C"]
// Output: 0
// Explanation:
// "1" - Add 1 to the record, record is now [1].
// "C" - Invalidate and remove the previous score, record is now [].
// Since the record is empty, the total sum is 0.

// int x = atoi("123");     // x = 123
// int y = atoi("-45");     // y = -45
// int z = atoi("  89abc"); // z = 89 (dừng khi gặp ký tự không phải số)

// strcmp(operations[i], "+") == 0 // so sánh chuỗi với chuỗi.


#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int calPoints(char** operations, int operationsSize) {
    int *st = (int*)malloc(sizeof(int)*operationsSize); 
    int top = 0;
    int sum = 0;

    for (int i = 0; i < operationsSize; i++)
    {
        if (strcmp(operations[i], "+") == 0) {
            st[top] = st[top - 1] + st[top - 2];
            top++;
        }else if(strcmp(operations[i], "D") == 0){
            st[top] = st[top - 1] * 2;
            top++;
        }else if(strcmp(operations[i], "C") == 0){
            st[--top] = 0;
        }else{
            st[top] = atoi(operations[i]);
            top++;
        }
    }
    
    for (int i = 0; i < top; i++)
    {
        sum += st[i];
    }
    free(st);
    return sum;  
}