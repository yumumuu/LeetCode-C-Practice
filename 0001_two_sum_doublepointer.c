#include <stdlib.h>
#include <string.h>
#include "leetcode.h"
// 用於排序時保存原始索引的結構體
typedef struct {
    int value;
    int index;
} Node;

int compare(const void* a, const void* b) {
    return ((Node*)a)->value - ((Node*)b)->value;
}

int *twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 創建一個 Node 陣列來保存數值和原始索引
    Node* nodes = (Node*)malloc(numsSize * sizeof(Node));
    for (int i = 0; i < numsSize; i++) {
        nodes[i].value = nums[i];
        nodes[i].index = i;
    }
    
    // 根據數值對 Node 陣列進行排序
    qsort(nodes, numsSize, sizeof(Node), compare);
    
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int sum = nodes[left].value + nodes[right].value;
        if (sum == target) {
            int* res = (int*)malloc(2 * sizeof(int));
            res[0] = nodes[left].index;
            res[1] = nodes[right].index;
            *returnSize = 2;
            free(nodes); // 別忘了釋放內存
            return res;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    // 都沒找到
    *returnSize = 0;
    free(nodes); // 別忘了釋放內存
    return malloc(sizeof(int) * 0);
}
