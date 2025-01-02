#pragma once

#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int top;									//栈顶指针
}SqStack;

void InitSqStack(SqStack *S){
  S->top = -1;
}

//新元素入栈
bool Push(SqStack &S, int element){
    if(S.top == MaxSize-1) return false;
    S.top++;
    S.data[S.top] = element;
    return true;
}

//出栈操作
bool Pop(SqStack &S, int &element){
    if(S.top == -1) return false;
    element = S.data[S.top];
    S.top--;
    return true;
}

bool GetTop(SqStack &S, int &element){
  if (S.top == -1) return false;
  element = S.data[S.top];
  return true;
}
