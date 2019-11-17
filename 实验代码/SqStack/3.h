Status InitStack(SqStack &S){
	//构造一个空栈
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}//InitStack

Status GetTop(SqStack S,SElemType &e){
	//若栈不空，则用e返回S的栈顶元素，并且返回OK；否则返回ERROR
	if(S.top==S.base) return ERROR;
	e=*(S.top-1);
	return OK;
}//GetTop

Status Push(SqStack &S,SElemType e){
	//插入元素e为新的栈顶元素
	int *newbase;
	if(S.top-S.base>=S.stacksize){//栈满，追加存储空间
		newbase=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) exit(OVERFLOW);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}//Push

Status Pop(SqStack &S,SElemType &e){
	//若栈不空，则删除S的栈顶元素，并用元素e返回其值，并返回OK；否则返回ERROR
	if(S.top==S.base)  return ERROR;
	e=*--S.top;
	return OK;
}//Pop

Status StackLength(SqStack S){
	return (S.top-S.base);
}//StackLength

Status StackEmpty(SqStack S){
	return (S.top==S.base);//若两指针重合，则为空栈
}//StackEmpty

void conversion(){
	SqStack S;
	SElemType e;
	int N,r;
	InitStack(S);
	cout<<"请输入原操作数及需要转换的进制:";
	cin>>N>>r;
	cout<<"Push into stack"<<endl;
	while(N){
		Push(S,N%r);
		cout<<N%r;
		N=N/r;
	}
	cout<<endl<<"Pop out stack"<<endl;
	while(!StackEmpty(S)){
		Pop(S,e);
		if(e>=0 && e<=9)
			cout<<e;
		else
			printf("%c",e-10+'A');
	}
}//conversion



