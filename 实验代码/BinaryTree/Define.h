#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef char TElemType;

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status CreateBiTree(BiTree &T);
Status PreOrderTraverse(BiTree T,Status (*visit)(TElemType e));
Status InOrderTraverse(BiTree T,Status (*visit)(TElemType e));
Status PostOrderTraverse(BiTree T,Status (*visit)(TElemType e));
//Status LevelOrderTraverse(BiTree T,Status (*visit)(TElemType e));
Status PrintTElement(TElemType e);
Status Count(BiTree T);
Status Countleaf(BiTree T);
Status Counttwo(BiTree T);
Status Countone(BiTree T);
Status Depth(BiTree T);

