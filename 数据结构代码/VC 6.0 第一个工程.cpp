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
	cout<<endl<<"��ʼ��һ����Ԫ�飬��������������ֵ:\n";
	cin>>v1>>v2>>v3;
	if(InitTriplet(T,v1,v2,v3)==OVERFLOW)
	{
		cout<<endl<<"����ʧ�ܣ������˳�����";
		return ;
	}
	else cout<<"�����ɹ���"<<endl;
	//������ʾ�����˵�
	cout<<"\n\n1:ȡ��Ԫ���i��Ԫ��\n";
	cout<<"2:�޸���Ԫ���i��Ԫ��\n";
	cout<<"3:�ж���Ԫ��Ԫ���Ƿ����\n";
	cout<<"4:�ж���Ԫ��Ԫ���Ƿ�ݼ�\n";
	cout<<"5:ȡ��Ԫ������Ԫ��\n";
	cout<<"6:ȡ��Ԫ�����СԪ��\n";
	cout<<"0:����\n\n";
	//�����������ѡ�ֱ������
	do{
		cout<<endl<<"���������ѡ�";
		cin>>select;
		switch(select{
			case 1:cout<<"input i= ";
					cin>>i;
					if(Get(T,i,e)==ERROR) cout<<"i��ֵ���Ϸ�\n";
					else cout>>"��Ԫ���"<<i<<"��Ԫ��ֵΪ"<<e;
					break;
			case 2:cout<<"input i= ";
					cin>>i;
					cout<<"input e= ";
					cin>>e;
					if(Put(T,i,e)==ERROR) cout<<"i��ֵ���Ϸ�\n";
					else cout<<"�޸ĺ����Ԫ��ֵΪ"<<T[0]<<"  ";
					break; 
			case 3:if(IsAscending(T)==TRUE)
						cout<<"��Ԫ���������"
						else cout<<"��Ԫ��ǵ�������";
						break;
			case 4:if(IsDescending(T))
						cout>>"��Ԫ��ݼ�����";
						else cout>>"��Ԫ��ǵݼ�����";
						break;
			case 5:Max(T,e)
				cout<<"��Ԫ������ԪΪ" <<e;
				break;
			case 6:Min(T,e);
				cout<<"��Ԫ�����СԪΪ"<<e;
				break;
			case 0:cout<<"��������";
				break;
		    default:cout<<"����ѡ�����";
		}//switch
		cout<<endl<<endl;
	} while (select!=0);
	InitTriplet(T,v1,v2,v3);//������Ԫ�� 
	DestroyTriplet(T);//������Ԫ�� 
	Get(T,i,e);//��e����T�ĵ�iԪ��ֵ
	Put(T,i,e);//��T�ĵ�i��Ԫ��Ϊe
	IsAscending(T);//��������
	IsDesending(T);//��������
	Max(T,e);//���Ԫ��
	Min(T,e);//��СԪ�� 
}//main 
/*Source File(����������ʵ��)*/ 
Status InitTriplet(Triplet& T,ElemType v1,ElemType v2,ElemType v3){
	//������Ԫ��T��������T��3��Ԫ�س�ֵΪv1��v2,v3.
	T=(ElemType *)malloc(3*sizeof(ElemType));//��������Ԫ�صĴ���ռ�
	if(!T)exit(OVERFLOW);//���䴢��ռ�ʧ��
	T[0]=v1;
	T[1]=v2;
	T[2]=v3;
	return OK; 
}//InitTriplet
Status DestroyTriplet(Triplet &T){
	//������Ԫ��
	free(T);
	T=NULL;
	return OK; 
}DestroyTriplet
Status Get(Triplet& T,int i,ElemType e){
	//1<=i<=3,��T�ĵ�iԪ��ֵΪe
	if(i<1 || i>3)return ERROR;
	T[i-1]=e;
	return OK; 
}//Put
Status IsAscending(Triplet& T)
{
	//���T��3��Ԫ�ذ����������򷵻�1�����򷵻�0
	return (T[0]<=T[1])&&(T[1]<=T[2]); 
 } //IsAscending
 Status IsDescending(Triplet& T)
 {
 	//���T��3��Ԫ�ذ����������򷵻�1�����򷵻�0
 	return (T[0]>=T[1])&&(T[1]>=T[2]); 
 }//IsDescending
 Status Max(Triplet T,ElemType &e){
 	//��e����ָ��T�����Ԫ�ص�ֵ 
 	e=(T[0]>=T[1])?((T[0]>=T[2])?T[0]:T[2]):((T[1]>=T[2])?T[1]:T[2]);
 	return OK;
 }//Max
 Status Min(Triplet T,ElemType &e){
 	//��e����ָ��T����СԪ�ص�ֵ 
 	e=(T[0]<=T[1])?((T[0]<=T[2])?T[0]:T[2]):((T[1]<=T[2])?T[1]:T[2]);
 	return OK;
 }//Min
 
