#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>              //使用bool型, false = 0, true = 1

#define MaxSize 50                //表长最大为50

typedef int ElemType;             //元素类型用ElemType表示, 此处为int

typedef struct Sqlist{            //顺序表定义
    ElemType data[MaxSize];
    int length;
};

void InitList(Sqlist &L){         //初始化顺序表, 无返回值
    L.length = 0;
}

