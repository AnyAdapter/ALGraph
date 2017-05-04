//�ڴ���ļ��� 
#include<iostream>
#include<queue>
#include<stack>
#include<cstdlib>
#define maxn 30	//ͼ����󶥵��� 
#define False 0
#define True  1
int visited[maxn];
using namespace std;
//�˳�����Ե�Ϊ����ͼ 

//�Զ��嶥����Ϣ �����㣩 
typedef char VertexType;
//�Զ��������Ϣ��Ȩֵ��
typedef int InfoType;

//�Զ���߱����� 
typedef struct node {
	int adjvertex;	//�ڽӵ��򣬶�Ӧ��Ŷ�Ӧ�������Ż����±�
	InfoType info;	//Ȩֵ
	struct node *next;//ָ���� 
}EdgeNode;

//�Զ��嶥�������� 
typedef struct vnode {
	VertexType vertex;	//������
	EdgeNode *firstedge;	//�߱�ָ���� 
}VertexNode;

//�Զ����ڽӱ�����
typedef struct {
	VertexNode adjlist[maxn];//�ڽӱ� 
	int vertexNum, edgeNum;	//�������ͱ��� 
}ALGraph;


//��������
void CreateALGraph(ALGraph *G);	//�����ڽӱ�洢��ͼ�㷨 
void DestoryALGraph(ALGraph **G);//����ͼ�㷨 
void DFStraverse(ALGraph G);
void DFS(ALGraph G, int v);	//ͼ����ȱ����ݹ��㷨
void BFStraverse(ALGraph G);
void BFS(ALGraph G, int v);	//ͼ�Ĺ�ȱ����㷨
void Visit(int v);//ͼ���ķ����㷨 

int main()
{

	return 0;
}

void CreateALGraph(ALGraph *G)	//�����ڽӱ�洢��ͼ�㷨 
{
	/*��������ͼ���ڽӱ�洢�㷨*/
	int i, j, k;
	EdgeNode *p;
	scanf_s("%d%d", &G->vertexNum, &G->edgeNum);	//����ͼ���ж��ٽ��Ͷ�������
	for (i = 0; i < G->vertexNum; i++)
	{
		scanf_s("%c", &(G->adjlist[i].vertex));//�������ж��㲢�Ҵ洢
		G->adjlist[i].firstedge = NULL;
	}
	for (k = 0; k < G->edgeNum; k++)	//�����߱� 
	{
		scanf_s("%d%d", &i, &j);	//�����<Vi,Vj>�����Ӧ�����
		p = (EdgeNode *)malloc(sizeof(EdgeNode));//�����µı߱��� 
		p->adjvertex = j;		//�ڽӵ����Ϊ j 
		p->next = G->adjlist[i].firstedge;	//���±߱��� p ���뵽���� Vi ������ͷ��
		G->adjlist[i].firstedge = p;
	}
}
void DestoryALGraph(ALGraph *G)//����ͼ�㷨 
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
void DFS(ALGraph G, int v)	//ͼ����ȱ����ݹ��㷨
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
void BFS(ALGraph G, int v)	//ͼ�Ĺ�ȱ����㷨
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
void Visit(int v)//ͼ���ķ����㷨 
{
	printf("%5d", v);
}