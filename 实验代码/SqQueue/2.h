#define MAXQSIZE  100  //�����г���
typedef struct{
    QElemType  *base; // ��̬����洢�ռ�
    int  front; // ͷָ�룬�����в��գ�
               //  ָʾ����ͷԪ�ص�λ��
    int  rear;// βָ�룬�����в��գ�ָʾ
             // ����βԪ�� ����һ��λ��
}SqQueue;
