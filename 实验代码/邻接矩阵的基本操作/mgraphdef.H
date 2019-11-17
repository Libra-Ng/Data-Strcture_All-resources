
#define INIFINITY 1000   			// 最大值
#define MAX_VERTEX_NUM 20    		//最大顶点数
typedef enum{DG,DN,UDG,UDN} GraphKind; 	//图的四种类型
typedef char VertexType;			//顶点类型
typedef  struct {
   VertexType vexs[MAX_VERTEX_NUM]; 	//顶点向量
   int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵
   int vexnum,arcnum;			//顶点数和弧的数目
   GraphKind kind;				//图的种类
}MGraph;