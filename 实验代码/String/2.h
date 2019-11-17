typedef struct{
	char *ch;
	int length;
}HString;

Status StrAssign(HString &S);
Status StrCompare(HString S,HString T);