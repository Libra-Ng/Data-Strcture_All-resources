Status InitQueue(SqQueue &Q) {
   // 构造一个空队列Q
   Q.base = (ElemType *) malloc(MAXQSIZE *sizeof (ElemType));
   if (!Q.base) exit (OVERFLOW);// 存储分配失败
   Q.front = Q.rear = 0;
   return OK;
 }//InitQueue

int QueueLength(SqQueue Q) {
   // 返回队列Q的元素个数，即队列长度
  return(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
 }//QueueLength

Status EnQueue(SqQueue &Q, ElemType e) { // 插入元素e为Q的新的队尾元素
    if ((Q.rear+1) % MAXQSIZE == Q.front) 
        return ERROR; //队列满
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXQSIZE;
    return OK;
}//EnQueue

Status DeQueue(SqQueue &Q, ElemType &e) {  // 若队列不空，则删除Q的队头元素，
   // 用e返回其值，并返回OK;  否则返回ERROR
    if (Q.front == Q.rear)  return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front+1) % MAXQSIZE;
    return OK;
}//DeQueue
