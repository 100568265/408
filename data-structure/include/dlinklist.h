#pragma once
#include <stdlib.h>

typedef struct DNode{
  int data;
  struct DNode *prior, *next;
}DNode, *DLinkList;

bool InitDLinkList(DLinkList &L){
  L = (DNode*)malloc(sizeof(DNode));  //分配一个头结点
  if(L == nullptr) return false;
  L->prior = L->next = nullptr;
  return true;
}

bool Empty(DLinkList &L){
  return L->next == nullptr;
}

//在p之后插入s结点
bool InsertNextNode(DNode *p, DNode *s){
  s->next = p->next;
  if(p->next !=nullptr)
    p->next->prior = s;
  s->prior = p;
  p->next = s;
}

//删除p结点的后继结点
bool DeleteNextNode(DNode *p){
  if(p==nullptr) return false;
  DNode *q = p->next;
  if(q==nullptr) return false;
  p->next = q->next;
  if(q->next != nullptr)
    q->next->prior = p;
  free(q);
  return true;
}