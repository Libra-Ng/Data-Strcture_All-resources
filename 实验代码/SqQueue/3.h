Status InitQueue(SqQueue &Q) {
   // ����һ���ն���Q
   Q.base = (ElemType *) malloc(MAXQSIZE *sizeof (ElemType));
   if (!Q.base) exit (OVERFLOW);// �洢����ʧ��
   Q.front = Q.rear = 0;
   return OK;
 }//InitQueue

int QueueLength(SqQueue Q) {
   // ���ض���Q��Ԫ�ظ����������г���
  return(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
 }//QueueLength

Status EnQueue(SqQueue &Q, ElemType e) { // ����Ԫ��eΪQ���µĶ�βԪ��
    if ((Q.rear+1) % MAXQSIZE == Q.front) 
        return ERROR; //������
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXQSIZE;
    return OK;
}//EnQueue

Status DeQueue(SqQueue &Q, ElemType &e) {  // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ�
   // ��e������ֵ��������OK;  ���򷵻�ERROR
    if (Q.front == Q.rear)  return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front+1) % MAXQSIZE;
    return OK;
}//DeQueue
