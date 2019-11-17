
#define INIFINITY 1000   			// 最大值
#define MAX_VERTEX_NUM 20    			//最大顶点数
typedef enum{DG,DN,UDG,UDN} GraphKind; 	//图的四种类型
typedef char VertexType;
typedef int  InfoType;
typedef  struct ArcNode{
     int adjvex;
     InfoType weight;
     struct ArcNode *nextarc;
}ArcNode;

typedef struct Vnode{
      VertexType  data;
      ArcNode      *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM ]; 

typedef struct {
       AdjList   vertices;
       int  vexnum,arcnum;
       GraphKind kind;
}ALGraph;
