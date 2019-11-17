typedef struct QNode {// 结点类型
    QElemType      data;
    struct QNode  *next;
  } QNode, *QueuePtr;
typedef struct { // 链队列类型
    QueuePtr  front;  // 队头指针
    QueuePtr  rear;   // 队尾指针
} LinkQueue;
