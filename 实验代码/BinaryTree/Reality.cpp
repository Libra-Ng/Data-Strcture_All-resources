#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"Define.h"

//建立先序二叉树 
Status CreateBiTree(BiTree &T)
{
	TElemType ch;
	scanf("%c",&ch);
	if(ch=='#') T=NULL;
	else{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}
//先序遍历二叉树
Status PreOrderTraverse(BiTree T,Status (*visit)(TElemType e)){
	if(!T) return ERROR;
	else{
		visit(T->data);
		PreOrderTraverse(T->lchild,visit);
		PreOrderTraverse(T->rchild,visit);
	}
	return OK;
}
//中序遍历二叉树
Status InOrderTraverse(BiTree T,Status (*visit)(TElemType e)){
	if(!T) return ERROR;
	else{
		InOrderTraverse(T->lchild,visit);
		visit(T->data);
		InOrderTraverse(T->rchild,visit);
	}
	return OK;
}
//后序遍历二叉树
Status PostOrderTraverse(BiTree T,Status (*visit)(TElemType e)){
	if(!T) return ERROR;
	else{
		PostOrderTraverse(T->lchild,visit);
		PostOrderTraverse(T->rchild,visit);
		visit(T->data);
	}
	return OK;
} 
Status PrintTElement(TElemType e){
	printf("%c",e);
	return OK;
}
Status Depth(BiTree T){
	int depthval,depthleft,depthright;
	if(!T)
		depthval=0;
	else{
		depthleft=Depth(T->lchild);
		depthright=Depth(T->rchild);
		depthval=1+(depthleft>depthright?depthleft:depthright);
	}
	return depthval;
}
Status Countleaf(BiTree T){
	int leafnum;
	if(!T)
		leafnum=0;
	else{
		leafnum=Countleaf(T->lchild)+Countleaf(T->rchild);
	}
	return leafnum;
}
Status Count(BiTree T){
	int num=0,num1=0,num2=0;
	if(!T) num=0;
	else{
		num1=Count(T->lchild);
		num2=Count(T->rchild);
		num=1+num1+num2;
	}
	return num;
}
Status Counttwo(BiTree T){
	int num=0,num1=0,num2=0;
	if(!T) num=0;
	else if(T->lchild && T->rchild){
		num=1;
		num1=Counttwo(T->lchild);
		num2=Counttwo(T->rchild);
		num+=num1+num2;
	}
	return num;
}
Status Countone(BiTree T){
	if(!T) return 0;
	else if(!T->lchild && T->rchild){
		return Countone(T->rchild)+1;
	}
	else if(T->lchild && !T->rchild){
		return Countone(T->lchild)+1;
	}
	else{
		return Countone(T->lchild)+Countone(T->rchild);
	}
}




