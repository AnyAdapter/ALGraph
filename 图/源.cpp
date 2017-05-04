//期待你的加入 
#include<iostream>
#include<queue>
#include<stack>
#include<cstdlib>
#define maxn 30	//图中最大顶点数 
#define False 0
#define True  1
int visited[maxn];
using namespace std;
//此程序面对的为有向图 

//自定义顶点信息 （顶点） 
typedef char VertexType;
//自定义边上信息（权值）
typedef int InfoType;

//自定义边表类型 
typedef struct node {
	int adjvertex;	//邻接点域，对应存放对应顶点的序号或者下标
	InfoType info;	//权值
	struct node *next;//指针域 
}EdgeNode;

//自定义顶点结点类型 
typedef struct vnode {
	VertexType vertex;	//顶点域
	EdgeNode *firstedge;	//边表指针域 
}VertexNode;

//自定义邻接表类型
typedef struct {
	VertexNode adjlist[maxn];//邻接表 
	int vertexNum, edgeNum;	//顶点数和边数 
}ALGraph;


//声明函数
void CreateALGraph(ALGraph *G);	//创建邻接表存储的图算法 
void DestoryALGraph(ALGraph **G);//销毁图算法 
void DFStraverse(ALGraph G);
void DFS(ALGraph G, int v);	//图的深度遍历递归算法
void BFStraverse(ALGraph G);
void BFS(ALGraph G, int v);	//图的广度遍历算法
void Visit(int v);//图结点的访问算法 

int main()
{

	return 0;
}

void CreateALGraph(ALGraph *G)	//创建邻接表存储的图算法 
{
	/*建立有向图的邻接表存储算法*/
	int i, j, k;
	EdgeNode *p;
	scanf_s("%d%d", &G->vertexNum, &G->edgeNum);	//输入图中有多少结点和多少条边
	for (i = 0; i < G->vertexNum; i++)
	{
		scanf_s("%c", &(G->adjlist[i].vertex));//输入所有顶点并且存储
		G->adjlist[i].firstedge = NULL;
	}
	for (k = 0; k < G->edgeNum; k++)	//建立边表 
	{
		scanf_s("%d%d", &i, &j);	//读入边<Vi,Vj>定点对应的序号
		p = (EdgeNode *)malloc(sizeof(EdgeNode));//生成新的边表结点 
		p->adjvertex = j;		//邻接点序号为 j 
		p->next = G->adjlist[i].firstedge;	//将新边表结点 p 插入到顶点 Vi 的链表头部
		G->adjlist[i].firstedge = p;
	}
}
void DestoryALGraph(ALGraph *G)//销毁图算法 
{
	EdgeNode *p, *q;
	for (int i = 0; i < G->vertexNum; i++)
	{
		p = G->adjlist[i].firstedge;
		while (p != NULL)
		{
			q = p;
			p = p->next;
			free(q);
		}
		G->adjlist[i].firstedge = NULL;
	}
}
void DFStraverse(ALGraph G)
{
	int v;
	for (v = 0; v < G.vertexNum; v++)
		visited[v] = False;
	for (v = 0; v < G.vertexNum; v++)
		if (!visited[v])DFS(G, v);
}
void DFS(ALGraph G, int v)	//图的深度遍历递归算法
{
	EdgeNode *p;
	int w;
	Visit(v);
	visited[v] = True;
	for (p = G.adjlist[v].firstedge; p != NULL; p = p->next)
	{
		w = p->adjvertex;
		if (!visited[w])DFS(G, w);
	}
}
void BFStraverse(ALGraph G)
{
	int v;
	for (v = 0; v < G.vertexNum; v++)
		visited[v] = False;
	for (v = 0; v < G.vertexNum; v++)
		if (!visited[v])BFS(G, v);
}
void BFS(ALGraph G, int v)	//图的广度遍历算法
{
	EdgeNode *p;
	int u, w;
	queue<int> Q;
	Visit(v);
	visited[v] = True;
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for (p = G.adjlist[u].firstedge; p != NULL; p = p->next)
		{
			w = p->adjvertex;
			if (!visited[w])
			{
				Visit(w);
				visited[w] = True;
				Q.push(w);
			}
		}
	}
}
void Visit(int v)//图结点的访问算法 
{
	printf("%5d", v);
}