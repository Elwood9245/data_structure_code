#include <stdio.h>
#include <stdlib.h>

#define InitSize 20               //表长初始值为20

typedef int ElemType;             //元素类型用ElemType表示, 此处为int

typedef struct{                   //顺序表定义
    ElemType *data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
    int MaxLength; 
    int length;
}Seqlist;

bool InitList(Seqlist &L){         //初始化顺序表, 成功返回true
    L.length = 0;
    L.MaxLength = InitSize;
    return true;
}

bool DestroyList(Seqlist &L){
    free(L.data);
    L.data = NULL;
    L.length = 0;
    L.MaxLength = 0;
    return true;
}

bool IncreaseSize(Seqlist &L, int len){
    ElemType *p = L.data;
    L.data = (ElemType *)malloc(sizeof(ElemType)*(L.MaxLength + len));
    for (int i = 0; i < L.length; ++i){
        L.data[i] = p[i];
    }
    L.MaxLength += len;
    free(p);
    p = NULL;
    return true;
}

bool InsertData(Seqlist &L, int i, ElemType e){       //在为序为i的位置插入数据e
    if (i < 1 || i > L.length + 1) return false;
    if (L.length >= L.MaxLength) return false;
    for (int j = L.length; j >= i; --j){
        L.data[j] = L.data[j - 1];    
    }
    L.data[i-1] = e;
    ++L.length;
    return true;
}

int Length(Seqlist L){             //求顺序表长度
    return L.length;
}

void OutputList(Seqlist L){
    int i = 0;
    while (i < L.length)
    {
        printf("%d ",L.data[i]);
        ++i;
    }
    
}
