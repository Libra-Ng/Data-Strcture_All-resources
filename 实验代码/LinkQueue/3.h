Status InitQueue(LinkQueue &Q) {
   // 构造一个空队列Q
   Q.front = Q.rear =
               (QueuePtr)malloc(sizeof(QNode));
   if (!Q.front) exit (OVERFLOW);                   
                                            //存储分配失败
   Q.front->next = NULL;
   return OK;
}//InitQueue

Status EnQueue(LinkQueue &Q,QElemType e) {
    // 插入元素e为Q的新的队尾元素
    p = (QueuePtr) malloc (sizeof (QNode));
    if (!p)  exit (OVERFLOW);   //存储分配失败
    p->data = e;   p->next = NULL;
    Q.rear->next = p;    Q.rear = p;
    return OK;
}//EnQueue

Status DeQueue(LinkQueue &Q,QElemType &e) {
  // 若队列不空，则删除Q的队头元素，
  //用 e 返回其值，并返回OK；否则返回ERROR
   if (Q.front == Q.rear)    return ERROR;
   p = Q.front->next;   e = p->data;
   Q.front->next = p->next;
   if (Q.rear == p)  Q.rear = Q.front;
   free (p);      return OK;
}//DeQueue

Status DestroyQueue(LinkQueue &Q) {
   // 销毁队列Q
    while(Q.front) {
       P=Q.front->next;
       free(Q.front);   
       Q.front =P;
     }   
  Q.rear=Q.front;
  return OK;
}//DestroyQueue







