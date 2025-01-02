#pragma once
//队列的顺序表示

#define MaxSize 10
typedef struct{
  int data[MaxSize];
  int front, rear;
 }SqQueue;

//入队时，队尾指针会往后移动
//出队时，队头指针会往后移动
bool EnQueue(SqQueue &Q, int data){
    if((Q.rear+1)%MaxSize == Q.front) return false;    //这里只能牺牲一个队列的存储空间，用来判断队列是否已满(主要是区分队里已满和队列为空两种不同的状态)
    Q.data[Q.rear] = data;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, int &data){
  if(Q.rear == Q.front) return false;    //队列为空，不能再出队了
  data = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  return true;
}

bool GetHead(SqQueue &Q, int &data){
    if(Q.rear == Q.front) return false;    //队列为空，不能再出队了
    data = Q.data[Q.front];
    return true;
}