
int LovateVex(MGraph G,VertexType v){
   for (int i=0;i<G.vexnum && G.vexs[i]!=v;i++);
   if (i<G.vexnum)  return i;
   else  return -1;
}

Status CreateUDN(MGraph &G){
	int i,j,k;
    VertexType v1,v2;
	int w;
	cout<<endl<<"输入图的顶点数和边数：";
    	cin>>G.vexnum>>G.arcnum;
    	cout<<endl<<"输入图的顶点信息：";
    	for (i=0;i<G.vexnum;i++) cin>>G.vexs[i];
    	for (i=0;i<G.vexnum;i++) 
		for (j=0;j<G.vexnum;j++) G.arcs[i][j]=INIFINITY;
    	cout<<endl<<"输入边的信息 v1,v2,w"<<endl;
    	for (k=0;k<G.arcnum;k++) {
        	 	cin>>v1;
		cin>>v2;
		cin>>w;
        	 	i=LovateVex(G,v1);  
		j=LovateVex(G,v2);  
		G.arcs[i][j]=w;
         	 	G.arcs[j][i]=G.arcs[i][j];
	}//for k
   	return OK;
 }//CreateUDN

/* 
请同学们自己完善以下关于有向网DN，无向图UDG，有向图DG的建立函数*/
Status CreateDN(MGraph &G){
	int i,j,k;
    VertexType v1,v2;
	int w;
	cout<<endl<<"输入图的顶点数和边数：";
    	cin>>G.vexnum>>G.arcnum;
    	cout<<endl<<"输入图的顶点信息：";
    	for (i=0;i<G.vexnum;i++) cin>>G.vexs[i];
    	for (i=0;i<G.vexnum;i++) 
		for (j=0;j<G.vexnum;j++) G.arcs[i][j]=INIFINITY;
    	cout<<endl<<"输入边的信息 v1,v2,w"<<endl;
    	for (k=0;k<G.arcnum;k++) {
        	 	cin>>v1;
		cin>>v2;
		cin>>w;
        	 	i=LovateVex(G,v1);  
		j=LovateVex(G,v2);  
		G.arcs[i][j]=w;
	}//for k
   	return OK;
 }//CreateDN

Status CreateUDG(MGraph &G){
	int i,j,k;
    VertexType v1,v2;
	int w;
	cout<<endl<<"输入图的顶点数和边数：";
    	cin>>G.vexnum>>G.arcnum;
    	cout<<endl<<"输入图的顶点信息：";
    	for (i=0;i<G.vexnum;i++) cin>>G.vexs[i];
    	for (i=0;i<G.vexnum;i++) 
		for (j=0;j<G.vexnum;j++) G.arcs[i][j]=0;
    	cout<<endl<<"输入边的信息 v1,v2"<<endl;
    	for (k=0;k<G.arcnum;k++) {
        	 	cin>>v1;
				cin>>v2;
        	 	i=LovateVex(G,v1);  
		j=LovateVex(G,v2);  
		G.arcs[i][j]=1;
         	 	G.arcs[j][i]=G.arcs[i][j];
	}//for k
   	return OK;
 }//CreateUDG

Status CreateDG(MGraph &G){
	int i,j,k;
    VertexType v1,v2;
	int w;
	cout<<endl<<"输入图的顶点数和边数：";
    	cin>>G.vexnum>>G.arcnum;
    	cout<<endl<<"输入图的顶点信息：";
    	for (i=0;i<G.vexnum;i++) cin>>G.vexs[i];
    	for (i=0;i<G.vexnum;i++) 
		for (j=0;j<G.vexnum;j++) G.arcs[i][j]=0;
    	cout<<endl<<"输入边的信息 v1,v2"<<endl;
    	for (k=0;k<G.arcnum;k++) {
        	 	cin>>v1;
				cin>>v2;
        	 	i=LovateVex(G,v1);  
		j=LovateVex(G,v2);  
		G.arcs[i][j]=1;
	}//for k
   	return OK;
 }//CreateDG



Status CreateGraph(MGraph &G){	//建立图G的邻接矩阵
   int kind;
   cout<<endl<<"输入图的类型：0-DG,1-DN,2-UDG,3-UDN:"<<endl;
   cin>>kind;
   G.kind=(GraphKind)kind;
   switch (G.kind){
       	case  DG	:return CreateDG(G);
       	case  DN	:return CreateDN(G);
       	case  UDG	:return CreateUDG(G);
       	case  UDN	:return CreateUDN(G);
       	default 	:return ERROR;
   }
}//CreateGraph

void PrintGraph(MGraph G){		//输出图G
    int i,j;
    cout<<endl<<"图的顶点数和边数：";
    cout<<setw(3)<<G.vexnum<<setw(3)<<G.arcnum;
    cout<<endl<<"图的顶点信息："<<endl;
    for (i=0;i<G.vexnum;i++) cout<<setw(3)<<G.vexs[i];
    cout<<endl<<"图的邻接矩阵："<<endl;
    for (i=0;i<G.vexnum;i++){
	cout<<endl;
	for (j=0;j<G.vexnum;j++)
	      if (G.arcs[i][j]==INIFINITY)cout<<setw(5)<<"∞";
	     else cout<<setw(5)<<G.arcs[i][j];
	}//for i
     cout<<endl;
}

void GraphDegree(MGraph G){
	int
	indegree[MAX_VERTEX_NUM]={0},outdegree[MAX_VERTEX_NUM]={0};
	int i;
	switch(G.kind){
		case DN:
		case DG:FindIndegree(G,Indegree);
			for(i=0;i<G.vexnum;i++)
				cout<<endl<<G.vexs[i]<<"的入度为:"<<indegree[i];
				cout<<endl;
		FindOutDegree(G,outdegree);
			for(i=0;i<G.vexnum;i++)
				cout<<endl<<G.vexs[i]<<"的出度为:"<<outdegree[i];
				break;
		case UDN:
		case UDG:FindOutDegree(G,outdegree);
			for(i=0;i<G.vexnum;i++)
				cout<<endl<<G.vexs[i]<<"的度为:"<<outdegree[i];
			break;	
	}
	cout<<endl;
}
