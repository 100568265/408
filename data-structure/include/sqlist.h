//顺序表的静态分配
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

//插入操作，pos为位序
bool ListInsert(SqList &L, int pos, int data) {
    if (pos < 1 || pos > L.length+1) return false;
    if (L.length >= MaxSize) return false;

    for(int i = L.length; i >= pos; i--) {  //将第pos元素及之后的元素往后移
        L.data[i] = L.data[i-1];
    }
    L.data[pos-1] = data;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int pos, int &data) {
    if (pos < 1 || pos > L.length) return false;
    data = L.data[pos-1];
    for (int i = pos; i < L.length; i++) {
        L.data[i-1] = L.data[i];
    }
    L.length--;
    return true;
}

// 按位查找
int GetElem(SqList &L, int pos) {
    if (pos < 1 || pos > L.length) return -1;
    return L.data[pos - 1];
}

// 按值查找
int LocateElem(SqList L, int value){
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == value)
            return value;
    }
    return 0;
}



//顺序表测试
void SqListTest() {
    SqList L;
    InitList(L);
    ListInsert(L,1,3);
    ListInsert(L,2,4);
    ListInsert(L,1,9);
    int e = -1;
    ListDelete(L,1,e);
}

