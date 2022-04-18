/* 
 * Sequential List
 * author: elwood
 * date: March, 18th
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define InitSize 20               //表长初始值为20

typedef struct{
    //顺序表定义
    int *data = (int*)malloc(sizeof(int)*InitSize);
    int MaxLength; 
    int length;
}Seqlist;

bool InitList(Seqlist &L){
    //初始化顺序表, 成功返回true
    L.length = 0;
    L.MaxLength = InitSize;
    return true;
}

bool DestroyList(Seqlist &L){
    //销毁表
    free(L.data);
    L.data = NULL;
    L.length = 0;
    L.MaxLength = 0;
    return true;
}

bool IncreaseSize(Seqlist &L, int len){
    //增加表长
    int *p = L.data;
    L.data = (int *)malloc(sizeof(int)*(L.MaxLength + len));
    for (int i = 0; i < L.length; ++i){
        L.data[i] = p[i];
    }
    L.MaxLength += len;
    free(p);
    p = NULL;
    return true;
}

bool ListInsert(Seqlist &L, int i, int e){
    //在为序为i的位置插入数据e
    if (i < 1 || i > L.length + 1) return false;
    if (L.length >= L.MaxLength) return false;
    for (int j = L.length; j >= i; --j){
        L.data[j] = L.data[j - 1];    
    }
    L.data[i-1] = e;
    ++L.length;
    return true;
}

int Length(Seqlist L){        //求顺序表长度
    return L.length;
}

void OutputList(Seqlist L){   //输出顺序表内值
    int i = 0;
    while (i < L.length){
        printf("%d ",L.data[i]);
        ++i;
    }   
}

bool ChangeElem(Seqlist &L, int i, int e){
    //将表中位序为i的元素值改为e.
    if(i < 1 || i > L.length) return false;
    L.data[i-1] = e;
    return true;
}

int GetElem(Seqlist L, int i){
    //按位查找, 返回位序为i的元素值.
    if(i < 1 || i > L.length) return 0;
    else return L.data[i-1];
}

int LocateElem(Seqlist L, int e){
    //按值查找, 返回值为e的元素在表中的位置.
    for (int i = 0; i < L.length; i++)
        if(L.data[i] == e) return ++i;
    return 0;
}

