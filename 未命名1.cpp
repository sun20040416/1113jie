#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // 定义顺序表的最大长度

// 定义顺序表结构
typedef struct {
    int data[MAX_SIZE];  // 顺序表存储数据的数组
    int length;          // 顺序表的当前长度
} SeqList;

// 初始化顺序表
void initSeqList(SeqList *L) {
    L->length = 0;
}

// 输出顺序表中的元素
void printSeqList(SeqList L) {
    printf("顺序表中的元素为: ");
    for (int i = 0; i < L.length; ++i) {
        printf("%d ", L.data[i]);
    }
    printf("\n顺序表的长度为: %d\n", L.length);
}

// 在第i个位置插入元素X
int insertElement(SeqList *L, int i, int X) {
    // 检查插入位置的合法性
    if (i < 1 || i > L->length + 1) {
        printf("插入位置不合法\n");
        return 0;  // 返回插入失败
    }

    // 检查顺序表是否已满
    if (L->length >= MAX_SIZE) {
        printf("顺序表已满，无法插入\n");
        return 0;  // 返回插入失败
    }

    // 将第i个位置及其后的元素后移一位
    for (int j = L->length; j >= i; --j) {
        L->data[j] = L->data[j - 1];
    }

    // 在第i个位置插入元素X
    L->data[i - 1] = X;
    L->length++;  // 顺序表长度加1

    return 1;  // 返回插入成功
}

// 删除第i个位置的元素
int deleteElement(SeqList *L, int i) {
    // 检查删除位置的合法性
    if (i < 1 || i > L->length) {
        printf("删除位置不合法\n");
        return 0;  // 返回删除失败
    }

    // 将第i个位置及其后的元素前移一位
    for (int j = i; j < L->length; ++j) {
        L->data[j - 1] = L->data[j];
    }

    L->length--;  // 顺序表长度减1

    return 1;  // 返回删除成功
}

// 修改第i个位置的元素为X
int modifyElement(SeqList *L, int i, int X) {
    // 检查修改位置的合法性
    if (i < 1 || i > L->length) {
        printf("修改位置不合法\n");
        return 0;  // 返回修改失败
    }

    // 修改第i个位置的元素为X
    L->data[i - 1] = X;

    return 1;  // 返回修改成功
}

int main() {
    SeqList myList;
    initSeqList(&myList);

    // 插入元素
    insertElement(&myList, 1, 10);
    insertElement(&myList, 2, 20);
    insertElement(&myList, 3, 30);

    // 输出顺序表
    printSeqList(myList);

    // 删除元素
    deleteElement(&myList, 2);

    // 输出删除后的顺序表
    printSeqList(myList);

    // 修改元素
    modifyElement(&myList, 2, 40);

    // 输出修改后的顺序表
    printSeqList(myList);

    return 0;
}

