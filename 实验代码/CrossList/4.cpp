#include"1.h"
#include"2.h"
#include"3.h"
int main()
{
	CrossList A,B;
	cout<<"���������A������������������Ԫ�������ո�񿪣�"<<endl;
	cin>>A.mu>>A.nu>>A.tu;
	cout<<"���������A�ķ���Ԫ��Ӧ������������������Ԫ������ֵ(�ո�񿪣�����0 0 0��ʾ����Ԫ�������)"<<endl;
	Create(A);
	cout<<"���������B������������������Ԫ�������ո�񿪣�"<<endl;
	cin>>B.mu>>B.nu>>B.tu;
	cout<<"���������B�ķ���Ԫ��Ӧ������������������Ԫ������ֵ(�ո�񿪣�����0 0 0��ʾ����Ԫ�������)"<<endl;
	Create(B);
	cout<<"-------------------"<<endl;
	cout<<"ԭ����AΪ:"<<endl;
	Show(A);
	cout<<"ԭ����BΪ:"<<endl;
	Show(B);
	cout<<"-------------------"<<endl;
	cout<<"����A������BΪ:"<<endl;
	if(A.mu==B.mu&&A.nu==B.nu)
	{
		Add(A,B);
		Show(A);
	}
	else
	{
		cout<<"�������ģ��ͬ�����ܽ��мӷ�"<<endl;
	}
	return 0;
}