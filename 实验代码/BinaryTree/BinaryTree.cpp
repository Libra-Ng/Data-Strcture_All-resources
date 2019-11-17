#include <iostream>
using namespace std;
#include"stdio.h"
#include"stdlib.h"
#include"Define.h"
int main(){
	BiTree T;
	printf("请直接输入字符\n");
	if(CreateBiTree(T))
	printf("先序建立二叉树成功!\n");
	printf("先序建立的二叉树深度为:%d\n",Depth(T));
	printf("先序建立的二叉树叶子总数为:%d\n",Countleaf(T));
	printf("先序建立的二叉树总结点数为:%d\n",Count(T));
	printf("先序建立的二叉树单分支结点数为:%d\n",Countone(T));
	printf("先序建立的二叉树双分支结点数为:%d\n",Counttwo(T));
	printf("先序递归遍历二叉树:\n");
	PreOrderTraverse(T,PrintTElement);
	printf("\n"); 
	printf("中序递归遍历二叉树:\n");
	InOrderTraverse(T,PrintTElement);
	printf("\n"); 
	printf("后序递归遍历二叉树:\n");
	PostOrderTraverse(T,PrintTElement);
	printf("\n"); 
	system("pause");
	return 0;
}
