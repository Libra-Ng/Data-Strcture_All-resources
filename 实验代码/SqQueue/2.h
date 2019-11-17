#define MAXQSIZE  100  //最大队列长度
typedef struct{
    QElemType  *base; // 动态分配存储空间
    int  front; // 头指针，若队列不空，
               //  指示队列头元素的位置
    int  rear;// 尾指针，若队列不空，指示
             // 队列尾元素 的下一个位置
}SqQueue;
