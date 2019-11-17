/*1.h(Header File)*/ 
#include<stdio.h>
#include<iostream.h>
#include<iomanip.h>
#include<string.h>
#include<malloc.h>
#include<process.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW  -1
typedef int Status;
/*2.h (Header File)*/ 
typedef int ElemType;
typedef ElemType *Triplet;
/*3.h(Header File)*/ 
#include"1.h"
#include"2.h"
#include"3.h"
void main()
{
	Triplet T;
	ElemType e,v1,v2,v3;
	int select,i;
	cout<<endl<<"初始化一个三元组，输入三个分量的值:\n";
	cin>>v1>>v2>>v3;
	if(InitTriplet(T,v1,v2,v3)==OVERFLOW)
	{
		cout<<endl<<"分配失败，即将退出程序！";
		return ;
	}
	else cout<<"创建成功！"<<endl;
	//否则显示操作菜单
	cout<<"\n\n1:取三元组第i个元素\n";
	cout<<"2:修改三元组第i个元素\n";
	cout<<"3:判断三元组元素是否递增\n";
	cout<<"4:判读三元组元素是否递减\n";
	cout<<"5:取三元组的最大元素\n";
	cout<<"6:取三元组的最小元素\n";
	cout<<"0:结束\n\n";
	//以下输入操作选项，直到结束
	do{
		cout<<endl<<"请输入你的选项：";
		cin>>select;
		switch(select{
			case 1:cout<<"input i= ";
					cin>>i;
					if(Get(T,i,e)==ERROR) cout<<"i的值不合法\n";
					else cout>>"三元组第"<<i<<"个元的值为"<<e;
					break;
			case 2:cout<<"input i= ";
					cin>>i;
					cout<<"input e= ";
					cin>>e;
					if(Put(T,i,e)==ERROR) cout<<"i的值不合法\n";
					else cout<<"修改后的三元组值为"<<T[0]<<"  ";
					break; 
			case 3:if(IsAscending(T)==TRUE)
						cout<<"三元组递增有序"
						else cout<<"三元组非递增有序";
						break;
			case 4:if(IsDescending(T))
						cout>>"三元组递减有序";
						else cout>>"三元组非递减有序";
						break;
			case 5:Max(T,e)
				cout<<"三元组的最大元为" <<e;
				break;
			case 6:Min(T,e);
				cout<<"三元组的最小元为"<<e;
				break;
			case 0:cout<<"操作结束";
				break;
		    default:cout<<"输入选项出错！";
		}//switch
		cout<<endl<<endl;
	} while (select!=0);
	InitTriplet(T,v1,v2,v3);//构造三元组 
	DestroyTriplet(T);//销毁三元组 
	Get(T,i,e);//用e返回T的第i元的值
	Put(T,i,e);//置T的第i个元素为e
	IsAscending(T);//升序排序
	IsDesending(T);//降序排序
	Max(T,e);//最大元素
	Min(T,e);//最小元素 
}//main 
/*Source File(基本操作的实现)*/ 
Status InitTriplet(Triplet& T,ElemType v1,ElemType v2,ElemType v3){
	//构造三元组T，依次置T的3个元素初值为v1，v2,v3.
	T=(ElemType *)malloc(3*sizeof(ElemType));//分配三个元素的储存空间
	if(!T)exit(OVERFLOW);//分配储存空间失败
	T[0]=v1;
	T[1]=v2;
	T[2]=v3;
	return OK; 
}//InitTriplet
Status DestroyTriplet(Triplet &T){
	//销毁三元组
	free(T);
	T=NULL;
	return OK; 
}DestroyTriplet
Status Get(Triplet& T,int i,ElemType e){
	//1<=i<=3,置T的第i元的值为e
	if(i<1 || i>3)return ERROR;
	T[i-1]=e;
	return OK; 
}//Put
Status IsAscending(Triplet& T)
{
	//如果T的3个元素按升序排序，则返回1，否则返回0
	return (T[0]<=T[1])&&(T[1]<=T[2]); 
 } //IsAscending
 Status IsDescending(Triplet& T)
 {
 	//如果T的3个元素按升序排序，则返回1，否则返回0
 	return (T[0]>=T[1])&&(T[1]>=T[2]); 
 }//IsDescending
 Status Max(Triplet T,ElemType &e){
 	//用e返回指向T的最大元素的值 
 	e=(T[0]>=T[1])?((T[0]>=T[2])?T[0]:T[2]):((T[1]>=T[2])?T[1]:T[2]);
 	return OK;
 }//Max
 Status Min(Triplet T,ElemType &e){
 	//用e返回指向T的最小元素的值 
 	e=(T[0]<=T[1])?((T[0]<=T[2])?T[0]:T[2]):((T[1]<=T[2])?T[1]:T[2]);
 	return OK;
 }//Min
 
