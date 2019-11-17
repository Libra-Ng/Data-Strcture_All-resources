#define STACK_INIT_SIZE 100//顺序栈存储空间的初始分配量
#define STACKINCREMENT 10//顺序栈存储空间的分配增量

typedef int SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;