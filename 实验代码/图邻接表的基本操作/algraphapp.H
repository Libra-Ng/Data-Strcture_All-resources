int LovateVex(ALGraph G,VertexType v){
   for (int i=0;i<G.vexnum && G.vertices[i].data!=v;i++);
   if (i<G.vexnum) return i;
   else return -1;
}


Status CreateUDG(ALGraph &G){//建立无向图的邻接表
	int i,j,k;
    	VertexType v1,v2;
	ArcNode *p,*q;
	cout<<endl<<"输入图的顶点数和边数：";
    	cin>>G.vexnum>>G.arcnum;
    	cout<<endl<<"输入图的顶点信息：";
    	for (i=0;i<G.vexnum;i++) {
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}

    	cout<<endl<<"输入边的信息v1,v2"<<endl;
    	for (k=0;k<G.arcnum;k++) {
        	 cin>>v1;
		 cin>>v2;
		 i=LovateVex(G,v1);  
		 j=LovateVex(G,v2); 
		 p=(ArcNode *)malloc (sizeof(ArcNode ));
		 p->adjvex=j;
		 p->nextarc=G.vertices[i].firstarc;
             	 G.vertices[i].firstarc=p;

                 q=(ArcNode *)malloc (sizeof(ArcNode ));
		 q->adjvex=i;
	         q->nextarc=G.vertices[j].firstarc;
             	 G.vertices[j].firstarc=q;
			
	}//for k
   return OK;
 }//CreateUDG



/*  请同学们根据上述给的创建无向图的邻接矩阵的函数，写出其他类型图的邻接表的建立函数*/
Status CreateDG(ALGraph &G){//建立有向图的邻接表
		int i,j,k;
    	VertexType v1,v2;
	ArcNode *p;
	cout<<endl<<"输入图的顶点数和边数：";
    	cin>>G.vexnum>>G.arcnum;
    	cout<<endl<<"输入图的顶点信息：";
    	for (i=0;i<G.vexnum;i++) {
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}

    	cout<<endl<<"输入边的信息v1,v2"<<endl;
    	for (k=0;k<G.arcnum;k++) {
        	 cin>>v1;
		 cin>>v2;
		 i=LovateVex(G,v1);  
		 j=LovateVex(G,v2); 
		 p=(ArcNode *)malloc (sizeof(ArcNode ));
		 p->adjvex=j;
		 p->nextarc=G.vertices[i].firstarc;
             	 G.vertices[i].firstarc=p;
	}//for k
   return OK;
 }//CreateDG

Status CreateDN(ALGraph &G){//建立有向网的邻接表
	int i,j,k;
	VertexType v1,v2;
	InfoType w;
	ArcNode *p;
	cout<<endl<<"输入图的顶点数和边数:";
	cin>>G.vexnum>>G.arcnum;
	cout<<endl<<"输入图的顶点信息:";
	for(i=0;i<G.vexnum;i++){
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}
	cout<<endl<<"输入边的信息v1,v2,weight"<<endl;
	for(k=0;k<G.arcnum;k++){
		cin>>v1;
		cin>>v2;
		cin>>w;
		i=LovateVex(G,v1);
		j=LovateVex(G,v2);
		p=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->weight=w;
		p->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p;
	}//for k
	return OK;
 }//CreateDN
Status CreateUDN(ALGraph &G){//建立无向向网的邻接表
	int i,j,k;
	VertexType v1,v2;
	InfoType w;
	ArcNode *p,*q;
	cout<<endl<<"输入图的顶点数和边数:";
	cin>>G.vexnum>>G.arcnum;
	cout<<endl<<"输入图的顶点信息:";
	for(i=0;i<G.vexnum;i++){
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}
	cout<<endl<<"输入边的信息v1,v2,weight"<<endl;
	for(k=0;k<G.arcnum;k++){
		cin>>v1;
		cin>>v2;
		cin>>w;
		i=LovateVex(G,v1);
		j=LovateVex(G,v2);
		p=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=j;
		p->weight=w;
		p->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p;
		q=(ArcNode *)maoolc(sizeof(ArcNode));
		q->adjvex=i;
		q->nextarc=G.vertices[j].firstarc;
		G.vertices[i].firstarc=q;
	}//for k
	return OK;
 }//CreateUDN


Status CreateGraph(ALGraph &G){
   int kind;
   cout<<endl<<"输入图的类型：0-DG,1-DN,2-UDG,3-UDN:"<<endl;
   cin>>kind;
   G.kind=(GraphKind)kind;
   switch (G.kind){
       //case  DG	:return CreateDG(G);
       //case  DN	:return CreateDN(G);
       	case  UDG	:return CreateUDG(G);
       //case  UDN	:return CreateUDN(G);
       	default 	:return ERROR;
   }
}//CreateGraph



void PrintGraph(ALGraph G){
    int i,j;
    ArcNode *p;
    cout<<endl<<"图的顶点数和边数：";
    cout<<setw(3)<<G.vexnum<<setw(3)<<G.arcnum;
    cout<<endl<<"图的顶点信息："<<endl;
    for (i=0;i<G.vexnum;i++) cout<<setw(3)<<G.vertices[i].data;
    cout<<endl<<"图的邻接表："<<endl;
    for (i=0;i<G.vexnum;i++){
		cout<<setw(3)<<G.vertices[i].data<<"的邻接点：";
		p=G.vertices[i].firstarc;
		while (p){
		   j=p->adjvex;
		   cout<<G.vertices[j].data;
		   p=p->nextarc;		
		}//while
		cout<<endl;
	}//for

	cout<<endl;
}
