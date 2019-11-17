Status InitStack(SqStack &S){
	//����һ����ջ
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}//InitStack

Status GetTop(SqStack S,SElemType &e){
	//��ջ���գ�����e����S��ջ��Ԫ�أ����ҷ���OK�����򷵻�ERROR
	if(S.top==S.base) return ERROR;
	e=*(S.top-1);
	return OK;
}//GetTop

Status Push(SqStack &S,SElemType e){
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	int *newbase;
	if(S.top-S.base>=S.stacksize){//ջ����׷�Ӵ洢�ռ�
		newbase=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) exit(OVERFLOW);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return OK;
}//Push

Status Pop(SqStack &S,SElemType &e){
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ�����Ԫ��e������ֵ��������OK�����򷵻�ERROR
	if(S.top==S.base)  return ERROR;
	e=*--S.top;
	return OK;
}//Pop

Status StackLength(SqStack S){
	return (S.top-S.base);
}//StackLength

Status StackEmpty(SqStack S){
	return (S.top==S.base);//����ָ���غϣ���Ϊ��ջ
}//StackEmpty

void conversion(){
	SqStack S;
	SElemType e;
	int N,r;
	InitStack(S);
	cout<<"������ԭ����������Ҫת���Ľ���:";
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



