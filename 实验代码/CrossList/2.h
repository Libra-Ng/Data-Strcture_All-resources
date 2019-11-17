typedef struct OLNode
{
	int i,j;
	ElemType e;
	struct OLNode *right,*down;
}OLNode,*OLink;

typedef struct
{
	int mu,nu,tu;
	OLink *rhead,*chead;
}CrossList;

Status Create(CrossList &T);
void Show(CrossList T);
void Add(CrossList &A,CrossList &B);