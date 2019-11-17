typedef struct{
	int i,j;
	ElemType e;
}Triple;

typedef struct{
	Triple data[MAXSIZE];
	int mu,nu,tu;
}TSMatrix;

Status Init(TSMatrix &trip);
Status Visit(TSMatrix trip);
Status Transpose(TSMatrix trip,TSMatrix &trip1);
