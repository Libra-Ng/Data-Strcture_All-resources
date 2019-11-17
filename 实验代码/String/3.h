Status StrAssign(HString &S)
{
	S.ch=(char *)malloc(sizeof(char)*(S.length+1));
	if(!S.ch) exit(OVERFLOW);
	cout<<"Enter the regular string:"<<endl;
	gets(S.ch);
	return OK;
}//StrAssign

Status StrCompare(HString S,HString T)
{
	int i=0;
	while(i<=S.length && i<=T.length)
	{
		if(S.ch[i]<T.ch[i])
		{
			return xiaoyu;
		}
		if(S.ch[i]==T.ch[i])
		{
			i++;
		}
		if(S.ch[i]>T.ch[i])
		{
			return dayu;
		}
	}
	if(S.length==T.length)
	{
		return dengyu;
	}
	if(S.length>T.length)
	{
		return dayu;
	}
	if(S.length<T.length)
	{
		return xiaoyu;
	}
	return OK;
}//StrCompare
