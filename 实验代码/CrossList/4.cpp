#include"1.h"
#include"2.h"
#include"3.h"
int main()
{
	CrossList A,B;
	cout<<"请输入矩阵A的行数、列数、非零元个数（空格格开）"<<endl;
	cin>>A.mu>>A.nu>>A.tu;
	cout<<"请输入矩阵A的非零元对应的行数、列数及非零元本身数值(空格格开，输入0 0 0表示非零元输入结束)"<<endl;
	Create(A);
	cout<<"请输入矩阵B的行数、列数、非零元个数（空格格开）"<<endl;
	cin>>B.mu>>B.nu>>B.tu;
	cout<<"请输入矩阵B的非零元对应的行数、列数及非零元本身数值(空格格开，输入0 0 0表示非零元输入结束)"<<endl;
	Create(B);
	cout<<"-------------------"<<endl;
	cout<<"原矩阵A为:"<<endl;
	Show(A);
	cout<<"原矩阵B为:"<<endl;
	Show(B);
	cout<<"-------------------"<<endl;
	cout<<"矩阵A＋矩阵B为:"<<endl;
	if(A.mu==B.mu&&A.nu==B.nu)
	{
		Add(A,B);
		Show(A);
	}
	else
	{
		cout<<"两矩阵规模不同，不能进行加法"<<endl;
	}
	return 0;
}