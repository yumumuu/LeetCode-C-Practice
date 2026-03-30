#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int* data;
} Container;

// ❌ 錯誤方式：返回棧上的結構體
Container getContainer_WRONG() {
    Container c;
    c.size = 5;
    c.data = (int*)malloc(5 * sizeof(int));
    c.data[0] = 100;
    c.data[1] = 200;
    printf("函數內部：c.data = %p\n", (void*)c.data);
    printf("函數內部：c.size = %d\n", c.size);
    return c;  // 返回副本，但棧要被清空
}

// ✅ 正確方式：返回指標
Container* getContainer_RIGHT() {
    Container* c = (Container*)malloc(sizeof(Container));
    c->size = 5;
    c->data = (int*)malloc(5 * sizeof(int));
    c->data[0] = 100;
    c->data[1] = 200;
    printf("函數內部：c->data = %p\n", (void*)c->data);
    printf("函數內部：c->size = %d\n", c->size);
    return c;  // 返回指標，堆上的數據保留
}

// 這個函數會「汙染」棧
void pollute_stack() {
    int garbage[100];
    for (int i = 0; i < 100; i++) {
        garbage[i] = 0xDEADBEEF;
    }
    printf("棧已被汙染\n");
}

int main() {
    printf("===== 錯誤方式 =====\n");
    Container t1 = getContainer_WRONG();
    printf("返回後：t1.data = %p\n", (void*)t1.data);
    printf("返回後：t1.size = %d\n\n", t1.size);
    
    // 汙染棧
    pollute_stack();
    
    // 現在訪問 t1
    printf("汙染棧後：t1.size = %d (預期5, 可能被破壞!)\n", t1.size);
    printf("汙染棧後：t1.data[0] = %d (預期100)\n\n", t1.data[0]);
    
    
    printf("===== 正確方式 =====\n");
    Container* t2 = getContainer_RIGHT();
    printf("返回後：t2->data = %p\n", (void*)t2->data);
    printf("返回後：t2->size = %d\n\n", t2->size);
    
    // 汙染棧
    pollute_stack();
    
    // 現在訪問 t2
    printf("汙染棧後：t2->size = %d (始終是5)\n", t2->size);
    printf("汙染棧後：t2->data[0] = %d (始終是100)\n\n", t2->data[0]);
    
    // 清理
    free(t2->data);
    free(t2);
    
    return 0;
}
