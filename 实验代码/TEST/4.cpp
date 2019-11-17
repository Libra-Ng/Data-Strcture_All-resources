#include"1.h"
#include"2.h"
#include"3.h"
int main()
{
	TSMatrix trip;
	cout<<"Enter the col and row of the matrix:"<<endl;
	cin>>trip.mu>>trip.nu;
	Init(trip);
	cout<<"---------------------"<<endl;
	cout<<"The original matrix is:"<<endl;
	Visit(trip);
	TSMatrix trip1;
	Transpose(trip,trip1);
	cout<<"The tranposed matrix is:"<<endl;
	Visit(trip1);
	return 0;
}