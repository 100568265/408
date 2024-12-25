#pragma one
#include <stdlib.h>
typedef struct LNode{
    int data;              //数据域
    struct LNode *next;    //指针指向下一个节点
}LNode, *LinkList;


// 不带头结点
//bool InitList(LinkList &L){
//  L = nullptr;
//  return true;
//}

// 带头结点
bool InitList(LinkList &L){
    L = (LNode*)malloc(sizeof(LNode));
    if(L == nullptr) return false;
    L->next = nullptr;
    return true;
}

//bool Empty(LinkList L){
//    return L == nullptr;
//}

//带头结点
bool Empty(LinkList L){
    return L->next == nullptr;
}


//后插操作，在p结点之后插入元素e
bool InsertNextNode(LNode *p, int e){
    if(p==nullptr) return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if(s == nullptr) return false;	//内存分配失败
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}


//按位序插入
bool ListInsert(LinkList &L, int pos, int element){
    if(pos < 1) return false;
    LNode *p = L;    //指针p指向当前扫描到的结点
    int j = 0;
    while(p != nullptr && j < pos){
      p = p->next;    //找到第pos个结点的指针
      j++;
    }
    InsertNextNode(p,element);
    //    if(p == nullptr) return false;
    //    LNode *p2 = (LNode*)malloc(sizeof(LNode));
    //    p2->data = element;
    //    p2->next = p->next;
    //    p->next = p2;
    //    return true;
}

//前插操作 在p结点之前插入e元素
bool InsertPriorNode(LNode *p, int e){
  if(p == nullptr) return false;
  LNode *s = (LNode*)malloc(sizeof(LNode));
  if(s == nullptr) return false;    //内存分配失败

  // 偷天换日，总的来说就是新结点创建在p之后，把p的值给s，然后p去接新值e
  s->next = p->next;
  p->next = s;          //新结点s连接到p之后
  s->data = p->data;    //把p的元素复制给s
  p->data = e;
  return true;
}

//按位序删除，带头结点
bool ListDelete(LinkList &L, int pos,int &element){
    if(pos < 1) return false;
    LNode *p = L;
    int j = 0;
    while(p->next != nullptr && j < pos - 1){
      p = p->next;
      j++;
    }
    if(p == nullptr) return false;
    if(p->next == nullptr) return false;
    LNode *q = p->next;    //令q指向被删除的结点
    element = q->data;
    p->next = q->next;    //将结点q从链中断开
    free(q);
    return true;
}

//删除指定的结点p
bool DeleteNode(LNode *p){
    if(p == nullptr) return false;

    //因为找不到p结点前面的结点，除非传入头结点，所以，偷天换日
    LNode *q = p->next;            //令q指向p的后继结点
    p->data = p->next->data;       //p后面那个结点的值给p
    p->next = q->next;
    free(q);
    return true;
}










void testList(){
  LinkList L;
  InitList(L);
}

