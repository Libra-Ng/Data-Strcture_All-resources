#include <iostream>
using namespace std;
#include"stdio.h"
#include"stdlib.h"
#include"Define.h"
int main(){
	BiTree T;
	printf("��ֱ�������ַ�\n");
	if(CreateBiTree(T))
	printf("�������������ɹ�!\n");
	printf("�������Ķ��������Ϊ:%d\n",Depth(T));
	printf("�������Ķ�����Ҷ������Ϊ:%d\n",Countleaf(T));
	printf("�������Ķ������ܽ����Ϊ:%d\n",Count(T));
	printf("�������Ķ���������֧�����Ϊ:%d\n",Countone(T));
	printf("�������Ķ�����˫��֧�����Ϊ:%d\n",Counttwo(T));
	printf("����ݹ����������:\n");
	PreOrderTraverse(T,PrintTElement);
	printf("\n"); 
	printf("����ݹ����������:\n");
	InOrderTraverse(T,PrintTElement);
	printf("\n"); 
	printf("����ݹ����������:\n");
	PostOrderTraverse(T,PrintTElement);
	printf("\n"); 
	system("pause");
	return 0;
}
