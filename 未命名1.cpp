#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // ����˳������󳤶�

// ����˳���ṹ
typedef struct {
    int data[MAX_SIZE];  // ˳���洢���ݵ�����
    int length;          // ˳���ĵ�ǰ����
} SeqList;

// ��ʼ��˳���
void initSeqList(SeqList *L) {
    L->length = 0;
}

// ���˳����е�Ԫ��
void printSeqList(SeqList L) {
    printf("˳����е�Ԫ��Ϊ: ");
    for (int i = 0; i < L.length; ++i) {
        printf("%d ", L.data[i]);
    }
    printf("\n˳���ĳ���Ϊ: %d\n", L.length);
}

// �ڵ�i��λ�ò���Ԫ��X
int insertElement(SeqList *L, int i, int X) {
    // ������λ�õĺϷ���
    if (i < 1 || i > L->length + 1) {
        printf("����λ�ò��Ϸ�\n");
        return 0;  // ���ز���ʧ��
    }

    // ���˳����Ƿ�����
    if (L->length >= MAX_SIZE) {
        printf("˳����������޷�����\n");
        return 0;  // ���ز���ʧ��
    }

    // ����i��λ�ü�����Ԫ�غ���һλ
    for (int j = L->length; j >= i; --j) {
        L->data[j] = L->data[j - 1];
    }

    // �ڵ�i��λ�ò���Ԫ��X
    L->data[i - 1] = X;
    L->length++;  // ˳����ȼ�1

    return 1;  // ���ز���ɹ�
}

// ɾ����i��λ�õ�Ԫ��
int deleteElement(SeqList *L, int i) {
    // ���ɾ��λ�õĺϷ���
    if (i < 1 || i > L->length) {
        printf("ɾ��λ�ò��Ϸ�\n");
        return 0;  // ����ɾ��ʧ��
    }

    // ����i��λ�ü�����Ԫ��ǰ��һλ
    for (int j = i; j < L->length; ++j) {
        L->data[j - 1] = L->data[j];
    }

    L->length--;  // ˳����ȼ�1

    return 1;  // ����ɾ���ɹ�
}

// �޸ĵ�i��λ�õ�Ԫ��ΪX
int modifyElement(SeqList *L, int i, int X) {
    // ����޸�λ�õĺϷ���
    if (i < 1 || i > L->length) {
        printf("�޸�λ�ò��Ϸ�\n");
        return 0;  // �����޸�ʧ��
    }

    // �޸ĵ�i��λ�õ�Ԫ��ΪX
    L->data[i - 1] = X;

    return 1;  // �����޸ĳɹ�
}

int main() {
    SeqList myList;
    initSeqList(&myList);

    // ����Ԫ��
    insertElement(&myList, 1, 10);
    insertElement(&myList, 2, 20);
    insertElement(&myList, 3, 30);

    // ���˳���
    printSeqList(myList);

    // ɾ��Ԫ��
    deleteElement(&myList, 2);

    // ���ɾ�����˳���
    printSeqList(myList);

    // �޸�Ԫ��
    modifyElement(&myList, 2, 40);

    // ����޸ĺ��˳���
    printSeqList(myList);

    return 0;
}

