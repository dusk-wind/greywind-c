#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int line;
    int row;
    int val;
} trinode;
typedef struct {
    trinode data[100];
    int linenum;
    int rownum;
    int num;
} tritable;
void triswap(tritable target, tritable* room) {
    int arr1[100] = {0}; // 初始化arr1为0
    int arr2[100] = {0}; // 初始化arr2为0
    room->linenum = target.rownum;
    room->rownum = target.linenum;
    room->num = target.num;

    if (room->num > 0) {
        // 计算每行的非零元素个数
        for (int x = 0; x < target.num; x++) {
            arr1[target.data[x].row]++;
        }
        // 计算位置偏移量
        arr2[0] = 0;
        for (int x = 1; x < target.rownum; x++) {
            arr2[x] = arr2[x - 1] + arr1[x - 1];
        }
        // 转置数据
        for (int x = 0; x < target.num; x++) {
            int t = target.data[x].row;
            int pos = arr2[t]++;
            room->data[pos].line = target.data[x].row;
            room->data[pos].row = target.data[x].line;
            room->data[pos].val = target.data[x].val;
        }
    }
}

int main() {
    tritable s;
    printf("请输入稀疏矩阵的行数、列数和非零元素个数:");
    scanf("%d%d%d", &s.linenum, &s.rownum, &s.num);
    int val = s.num;
    for (int i = 0; i < val; i++) {
        printf("第%d个元素:", i + 1);
        scanf("%d%d%d", &s.data[i].line, &s.data[i].row, &s.data[i].val);
    }
    printf("转置前的行三元组:\n");
    for (int i = 0; i < s.num; i++) {
        printf("%d ,%d ,%d \n", s.data[i].line, s.data[i].row, s.data[i].val);
    }
    tritable t;
    triswap(s, &t);
    printf("转置后的行三元组:\n");
    for (int i = 0; i < t.num; i++) {
        printf("%d ,%d ,%d \n", t.data[i].line, t.data[i].row, t.data[i].val);
    }
    return 0;
}