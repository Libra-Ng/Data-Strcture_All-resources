Status InitQueue(LinkQueue &Q) {
   // ����һ���ն���Q
   Q.front = Q.rear =
               (QueuePtr)malloc(sizeof(QNode));
   if (!Q.front) exit (OVERFLOW);                   
                                            //�洢����ʧ��
   Q.front->next = NULL;
   return OK;
}//InitQueue

Status EnQueue(LinkQueue &Q,QElemType e) {
    // ����Ԫ��eΪQ���µĶ�βԪ��
    p = (QueuePtr) malloc (sizeof (QNode));
    if (!p)  exit (OVERFLOW);   //�洢����ʧ��
    p->data = e;   p->next = NULL;
    Q.rear->next = p;    Q.rear = p;
    return OK;
}//EnQueue

Status DeQueue(LinkQueue &Q,QElemType &e) {
  // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ�
  //�� e ������ֵ��������OK�����򷵻�ERROR
   if (Q.front == Q.rear)    return ERROR;
   p = Q.front->next;   e = p->data;
   Q.front->next = p->next;
   if (Q.rear == p)  Q.rear = Q.front;
   free (p);      return OK;
}//DeQueue

Status DestroyQueue(LinkQueue &Q) {
   // ���ٶ���Q
    while(Q.front) {
       P=Q.front->next;
       free(Q.front);   
       Q.front =P;
     }   
  Q.rear=Q.front;
  return OK;
}//DestroyQueue







