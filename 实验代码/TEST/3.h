Status Init(TSMatrix &trip)
{
	cout<<"Enter the elements of the matrix:"<<endl;
	ElemType e;
	trip.tu=0;
	for(int i=1;i<=trip.mu;i++)
	{
		for(int j=1;j<=trip.nu;j++)
		{
			cin>>e;
			if(e!=0)
			{
				trip.tu++;
				trip.data[trip.tu].i=i;
				trip.data[trip.tu].j=j;
				trip.data[trip.tu].e=e;
			}
		}
	}
	return OK;
}//Init

int Visit(TSMatrix trip)
{
	int n=1;
	ElemType e;
	for(int i=1;i<=trip.mu;i++)
	{
		for(int j=1;j<=trip.nu;j++)
		{
			if(trip.data[n].i==i && trip.data[n].j==j && n<=trip.tu)
			{
				cout<<trip.data[n].e<<" ";
				n++;
			}
			else cout<<"0 ";
		}
		cout<<endl;
	}
	cout<<endl;
	return OK;
}//visit

int Transpose(TSMatrix trip,TSMatrix &trip1)
{
	int i=1,j=1;
	ElemType e;
	trip1.nu=trip.mu;
	trip1.mu=trip.nu;
	trip1.tu=trip.tu;
	//形成num-cpot表格
	int col=0,t=0;
	int num[MAXSIZE],cpot[MAXSIZE];
	for(col=1;col<=trip.nu;col++) num[col]=0;
	for(t=1;t<=trip.tu;t++) num[trip.data[t].j]++;
	cpot[1]=1;
	for(col=2;col<=trip.nu;col++) cpot[col]=cpot[col-1]+num[col-1];//注意col从2开始
	//实施转置
	int p;
	for(t=1;t<=trip.tu;t++)
	{
		col=trip.data[t].j;//第一步：取原矩阵存储每一个非零元列数
		p=cpot[col];//第二步：由列数得到该元素在转置矩阵存储中的存放位置
		//第三步：存放数据
		trip1.data[p].i=trip.data[t].j;
		trip1.data[p].j=trip.data[t].i;
		trip1.data[p].e=trip.data[t].e;
		//第四步：更新每一列下一个非零元在转置矩阵存储的存放位置
		cpot[col]++;
	}
	return OK;
}
