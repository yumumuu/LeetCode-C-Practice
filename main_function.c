#include <stdio.h>
#include <stdlib.h>
#include "leetcode.h"
#include <windows.h> // 必須加入這個標頭檔
int main() {
    // 強制設定終端機輸出為 UTF-8 (編號 65001)
    SetConsoleOutputCP(65001);

    printf("--- 開始執行 LeetCode 測試 ---\n");

    // 測試 Two Sum
    int nums[] = {3, 2, 4};
    int target = 6;
    int returnSize;
    
    int* res = twoSum(nums, 6, target, &returnSize);
    
    if (res != NULL) {
        printf("[Two Sum 結果]: [%d, %d]\n", res[0], res[1]);
        free(res);
    } else {
        printf("[Two Sum 結果]: 未找到解答\n");
    }

    printf("--- 測試結束 ---\n");
    return 0;
}