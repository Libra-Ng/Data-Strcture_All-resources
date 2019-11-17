Status Create(CrossList &T)
{
	if(!(T.rhead=(OLink *)malloc(sizeof(OLink)*(T.mu+1)))) exit(OVERFLOW);
	if(!(T.chead=(OLink *)malloc(sizeof(OLink)*(T.nu+1)))) exit(OVERFLOW);
	for(int i=1;i<=T.mu;i++)  T.rhead[i]=NULL;
	for(int j=1;j<=T.nu;j++)  T.chead[j]=NULL;
	ElemType e;
	for(scanf("%d%d%d",&i,&j,&e);i!=0;scanf("%d%d%d",&i,&j,&e))
	{
		OLNode *p,*q;
		if(!(p=(OLNode *)malloc(sizeof(OLNode)))) exit(OVERFLOW);
		p->i=i;p->j=j;p->e=e;
		if(T.rhead[i]==NULL||T.rhead[i]->j>j)
		{
			p->right=T.rhead[i];
			T.rhead[i]=p;
		}
		else
		{
			for(q=T.rhead[i];(q->right)&&q->right->j<j;q=q->right)
			{
			p->right=q->right;
			q->right=p;
			}
		}
		if(T.chead[j]==NULL||T.chead[j]->i>i)
		{
			p->down=T.chead[j];
			T.chead[j]=p;
		}
		else
		{
			for(q=T.chead[j];(q->down)&&q->down->i<i;q=q->down)
			{
				p->down=q->down;
				q->down=p;
			}
		}
	}
		return OK;
}//Create

void Show(CrossList T)
{
	int t=T.tu;
	OLNode *p;
	for(int i=1;i<=T.mu;i++)
	{
		p=T.rhead[i];
		for(int j=1;j<=T.nu;j++)
		{
			if(t==0)
			{
				cout<<"0 ";
				continue;
			}
			else if(p!=NULL&&p->i==i&&p->j==j)
			{
				t--;
				cout<<p->e<<" ";
				p=p->right;
			}
			else cout<<"0 ";
		}
		cout<<endl;
	}
	cout<<endl;
}//Show

void Add(CrossList &A,CrossList &B)
{
	////pre,hl[]为行、列前驱，hl[]特殊（对于每一列的第一个非零元，没有列前驱，即此时的hl[]就是这些非零元，对于同列的其他非零元，hl[]是前驱）
	OLNode *pa,*pb,*pre;
	OLink *hl;
	if(!(hl=(OLink *)malloc(sizeof(OLink)*(A.nu+1)))) exit(OVERFLOW);
	for(int i=1;i<=A.nu;i++) hl[i]=A.chead[i];
	for(i=1;i<A.mu;i++)
	{
		pa=A.rhead[i];
		pb=B.rhead[i];
		pre=NULL;
		while(pb)
		{
			if(pa==NULL || pa->j>pb->j)
			{
				A.tu++;
				OLNode *p;
				if(!(p=(OLNode *)malloc(sizeof(OLNode))))  exit(OVERFLOW);
				   p->i=pb->i;p->j=pb->j;p->e=pb->e;
				if(pre==NULL) A.rhead[p->i]=p;
				else pre->right=p;
				p->right=pa;
				pre=p;//为了使下一次处理该情况时，元素有行前驱，所以让pre指向p（if和else的共同步骤）
				if(A.chead[p->j]==NULL||A.chead[p->j]->i>p->i)
					{
					p->down=A.chead[p->j];
					A.chead[p->j]=p;
				}
				else
				{
					p->down=hl[p->j]->down;
					hl[p->j]->down=p;
				}
				hl[p->j]=p;//为了使下一次处理该情况时，元素有列前驱，所以让hl[]指向p（if和else的共同步骤）
				pb=pb->right;//第一种情况和第三种情况处理完后，pb都应改变
			}
			else if(pa!=NULL&&pa->j<pb->j)
			{
				pre=pa;
				pa=pa->right;//在第二种和第三种情况下改变
			}
			else if(pa->j==pb->j)
			{
				pa->e+=pb->e;
				if(pa->e==0)
				{
					A.tu--;
					OLNode *p;
					p=pa;
					pa=pa->right;
					if(A.rhead[p->i]==p)
					{
						A.rhead[p->i]=p->right;
					}//此时，原本的pre==NULL，所以不用变化
					else
					{
						pre->right=p->right;
					}//因为p->right是下次处理的元素，此时pre已经成为它的前驱， 所以不让pre=p->right
					if(A.chead[p->j]==p)
					{
						A.chead[p->j]=hl[p->j]=p->down;
					}//hl[]指向了p->down,即指向free(p)后，该列第一个新的非零元（与第一次对hl[]初始化的方法一样）
					else
					{
						hl[p->j]->down=p->down;
					}
					free(p);
					pb=pb->right;
				}
				else
				{
					pa=pa->right;pb=pb->right;
				}
			}
		}
	}
}//Add