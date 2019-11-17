#include"stdio.h"
#include"stdlib.h"
#include"iostream.h"
#include"1.h"
#include"2.h"
#include"3.h"
int main()
{
	char c;//用于读取换行符，便于StrAssign函数中gets读取串的操作
	HString S,T;
	cout<<"Enter the length of the first string:"<<endl;
	cin>>S.length;
	c=getchar();
	StrAssign(S);//初始化S的ch部分
	cout<<"Enter the length of the second string:"<<endl;
	cin>>T.length;
	c=getchar();
	StrAssign(T);//初始化T的ch部分
	cout<<"The result is:"<<endl;
	int a;
	a=StrCompare(S,T);
	if(a==-2) cout<<"The first string is smaller than the second one."<<endl;
	if(a==0) cout<<"The first string is equal to the second one."<<endl;
	if(a==1) cout<<"The first sting is bigger than the second one."<<endl;
	else {
		cout<<"ERROR!"<<endl;
		return ERROR;
	}
	return OK;
}