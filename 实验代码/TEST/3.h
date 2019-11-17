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
	//�γ�num-cpot���
	int col=0,t=0;
	int num[MAXSIZE],cpot[MAXSIZE];
	for(col=1;col<=trip.nu;col++) num[col]=0;
	for(t=1;t<=trip.tu;t++) num[trip.data[t].j]++;
	cpot[1]=1;
	for(col=2;col<=trip.nu;col++) cpot[col]=cpot[col-1]+num[col-1];//ע��col��2��ʼ
	//ʵʩת��
	int p;
	for(t=1;t<=trip.tu;t++)
	{
		col=trip.data[t].j;//��һ����ȡԭ����洢ÿһ������Ԫ����
		p=cpot[col];//�ڶ������������õ���Ԫ����ת�þ���洢�еĴ��λ��
		//���������������
		trip1.data[p].i=trip.data[t].j;
		trip1.data[p].j=trip.data[t].i;
		trip1.data[p].e=trip.data[t].e;
		//���Ĳ�������ÿһ����һ������Ԫ��ת�þ���洢�Ĵ��λ��
		cpot[col]++;
	}
	return OK;
}
