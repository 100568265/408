#pragma once

#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int length;
}SqList;

void InitList(SqList &L){
    for(int i = 0; i<MaxSize;i++)
        L.data[i] = 0;
    L.length = 0;
}