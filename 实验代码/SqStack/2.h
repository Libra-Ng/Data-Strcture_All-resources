#define STACK_INIT_SIZE 100//˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 10//˳��ջ�洢�ռ�ķ�������

typedef int SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;