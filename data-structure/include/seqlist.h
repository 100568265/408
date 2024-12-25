#pragma once

#include <stdlib.h>
#define InitSize 10    //默认的最大长度

typedef struct{
    int *data;						//动态的数组存放数据元素
    int length;						//顺序表的当前长度
    int MaxSize;					//顺序表的最大容量
}SeqList;


void InitList(SeqList &L){
    L.data = (int*)malloc(sizeof(int) * InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len){
    int *p = L.data;
    L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));
    for(int i = 0; i < L.length; i++){

    }
}


