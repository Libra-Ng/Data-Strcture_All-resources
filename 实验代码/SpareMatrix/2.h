typedef struct{
	int i,j;
	ElemType e;
}Triple;

typedef struct{
	Triple data[MAXSIZE];
	int mu,nu,tu;
}TSMatrix;

Status Init(TSMatrix &trip);
void visit(TSMatrix trip);
void Tranpose(TSMatrix trip,TSMatrix &trip1);