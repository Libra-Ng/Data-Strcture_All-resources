#include <stdio.h>
#include <stdlib.h>
 
typedef char DataType;
 
typedef struct node		/*�������Ĵ洢�ṹ*/ 
{
	DataType data;
 	struct node *Lchild;
 	struct node *Rchild;
}BiTNode,*BiTree;
 
int Count1=0;	/*ͳ�ƽ����Ŀ��ȫ�ֱ���*/
 
int Count2=0;	/*ͳ��Ҷ�ӽ����Ŀ��ȫ�ֱ���*/ 
 
int depth = 0;	/*��¼��ǰ��õ������*/ 
 
BiTNode *Create_BiTree();	/*������������*/	
 
void  PreOrder(BiTree root);	/*�������������*/
 
void InOrder(BiTree root);	 /*�������������*/
 
void PostOrder(BiTree root);	 /*�������������*/
 
void PreOrder_CalNode(BiTree root);		/*ͳ�ƶ������Ľ��*/
 
void InOrder_PrintLeaf(BiTree root); 	/*�����������Ҷ�ӽ��*/
 
void PostOrder_CalLeaf(BiTree root);	/*����1-ͳ��Ҷ�ӽ�����Ŀ*/
 
int CalLeaf(BiTree root);	/*����2-ͳ��Ҷ�ӽ�����Ŀ*/
 
void TreeDepth(BiTree root,int h);	/*����1-��������ĸ߶�*/
 
int PostOrder_TreeDepth(BiTree root);	/*����2-��������ĸ߶�*/
 
BiTree Parent(BiTree root,BiTree current);	/*���������ĳ������˫��*/ 
 
void PrintTree(BiTree root,int h);		/*����״��ӡ������*/ 
 
int main()
{
	BiTree root;
	/*-----------------�������Ľ���-----------------*/ 
	printf("�������������������(# = NULL)��"); 
	root = Create_BiTree();
	
	/*-----------------�������ĵݹ����---------------*/ 
	printf("\n����ݹ�������£�");
	PreOrder(root);
	printf("\n\n����ݹ�������£�");
	InOrder(root);
	printf("\n\n����ݹ�������£�");
	PostOrder(root);
	printf("\n");
	
	/*-----------�������ͳ�ƶ������еĽ����---------*/ 
	PreOrder_CalNode(root);
	printf("\n�������Ľ�����ǣ�%d\n",Count1);
	
	/*-----------������������������Ҷ�ӽ��---------*/ 
	printf("\n��������Ҷ�ӽ���ǣ�");
	InOrder_PrintLeaf(root);
	printf("\n");
	
	/*----------�������ͳ�ƶ�������Ҷ�ӽ����---------*/
	PostOrder_CalLeaf(root);
	printf("\n��������Ҷ�ӽ�����ǣ�%d\n",Count2); 
	
	/*----------��������������ĸ߶�(�����)---------*/
	int h=1; /*hΪroot���ڵĲ��,��ʼֵΪ1*/
	TreeDepth(root,h);
	printf("\n�������ĸ߶��ǣ�%d\n",depth);
	
	/*-----------------��ĳ����˫��----------------*/
	
	
	/*-----------------����״��ӡ������--------------*/
	h = 1;
	printf("\n����������״��ӡ���£�\n\n");
	PrintTree(root,h);
	
	return 0;
}
 
BiTNode *Create_BiTree()		/*������������*/
{
	DataType ch;
    BiTree root;
    scanf("%c",&ch);
    if(ch=='#')		root=NULL;
    else{
        root = (BiTree)malloc(sizeof(BiTNode));
        root->data = ch;
        root->Lchild = Create_BiTree();
        root->Rchild = Create_BiTree();
    }
    return root;
}
 
void  PreOrder(BiTree root)	/*�������������*/
{
	if(root){
		printf("%c",root->data);	/*���ʸ��ڵ�����*/ 
		PreOrder(root->Lchild);		/*�������������*/ 
		PreOrder(root->Rchild);		/*�������������*/ 
	}
}
 
void InOrder(BiTree root) /*�������������*/
{
	if(root){
		InOrder(root->Lchild);		/*�������������*/ 
		printf("%c",root->data);	/*���ʸ��ڵ�����*/ 
		InOrder(root->Rchild);		/*�������������*/ 
	}
}
 
void PostOrder(BiTree root) /*�������������*/
{
	if(root){
		PostOrder(root->Lchild);		/*�������������*/  
		PostOrder(root->Rchild);		/*�������������*/
		printf("%c",root->data);	/*���ʸ��ڵ�����*/
	}
}
 
void PreOrder_CalNode(BiTree root)		/*ͳ�ƶ������Ľ��*/
{
	if(root)
	{
		Count1++;
		PreOrder_CalNode(root->Lchild);
		PreOrder_CalNode(root->Rchild);
	}
}
 
void InOrder_PrintLeaf(BiTree root) 	/*�����������Ҷ�ӽ��*/
{
	if(root){
		InOrder_PrintLeaf(root->Lchild);
		if(root->Lchild == NULL  &&  root->Rchild == NULL){
			printf("%c ",root->data);		/*���Ҷ�ӽ��*/ 
		}
		InOrder_PrintLeaf(root->Rchild);
	}
}
 
void PostOrder_CalLeaf(BiTree root)		/*����1-ͳ��Ҷ�ӽ�����Ŀ*/ 
{
	if(root){
		PostOrder_CalLeaf(root->Lchild);
		PostOrder_CalLeaf(root->Rchild);
		if(root->Lchild == NULL  &&  root->Rchild == NULL){
			Count2++;		/*ͳ��Ҷ�ӽ��*/ 
		}
	}
}
 
int CalLeaf(BiTree root)	/*����2-ͳ��Ҷ�ӽ�����Ŀ*/
{
	int nl,nr;		/*nl,nr�ֱ�ͳ������������Ҷ�ӽ����Ŀ*/ 
	if(root==NULL) return 0;
	if(root->Lchild==NULL && root->Rchild==NULL) return 1;
	nl = CalLeaf(root->Lchild);		/*�ݹ�����������Ҷ����*/
	nr = CalLeaf(root->Rchild); 	/*�ݹ�����������Ҷ����*/ 
}
 
void TreeDepth(BiTree root,int h)	/*����1-��������ĸ߶�*/
{
	if(root){
		if(h>depth) depth = h;		/*��ǰ����δ���depth,����*/
		TreeDepth(root->Lchild,h+1);	/*���������������������Ϊh+1*/ 
		TreeDepth(root->Rchild,h+1);	/*���������������������Ϊh+1*/ 
	}
}
 
int PostOrder_TreeDepth(BiTree root)	/*����2-��������ĸ߶�*/
{
	int hl,hr,h;
	if(root==NULL) return 0;
	else {
		hl = PostOrder_TreeDepth(root->Lchild); /*�ݹ����������ĸ߶�*/ 
		hr = PostOrder_TreeDepth(root->Rchild);	/*�ݹ����������ĸ߶�*/
		h = (hl > hr ? hl : hr) + 1;  /*�������ĸ߶�*/
		return h; 
	}
}
 
BiTree Parent(BiTree root,BiTree current)	/*���������ĳ������˫��*/
{
	BiTree p;
	if(root==NULL) return NULL;
	if(root->Lchild==current || root->Rchild==current)
	return root;						/*  *root��Ϊcurrent��˫��*/
	p=Parent(root->Lchild,current);		/*�ݹ����������в���*/
	if(p!=NULL) return p;
	else return(Parent(root->Rchild,current));	/*�ݹ����������в���*/ 
	
} 
 
void PrintTree(BiTree root,int h)		/*����״��ӡ������*/
{
	if(root==NULL) return;
	PrintTree(root->Rchild,h+1);	/*�����ӡ������*/
	for(int i=0;i<h;i++)  printf("  ");
	printf("%c\n",root->data);		/*������*/
	PrintTree(root->Lchild,h+1);	/*�����ӡ������*/ 
}		

