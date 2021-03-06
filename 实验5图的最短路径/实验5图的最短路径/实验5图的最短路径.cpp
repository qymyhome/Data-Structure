#include "pch.h"
#include "stdio.h"
#include "malloc.h"

#define MAXNUM 100
#define INFINITY 100

char path[MAXNUM][MAXNUM];
int dest[MAXNUM];

typedef struct graph
{
	int VertexNum;
	char Vertex[MAXNUM];
	int Matrix[MAXNUM][MAXNUM];
}Graph;

void CreatGraph(Graph *graph);
void Shortest(Graph *graph, char Startnode);
void ShowPath(Graph *graph);

int main(int argc[], char *argv[])
{
	Graph ngraph;
	char Startvex;
	CreatGraph(&ngraph);
	fflush(stdin);
	if (getchar() == '\n') /*将缓冲区里的回车符号给去掉*/
		scanf_s("%c", &Startvex, 2);
	Shortest(&ngraph, Startvex);
	ShowPath(&ngraph);
	return 0;
}

/*创建邻接矩阵*/
void CreatGraph(Graph *graph)
{
	scanf_s("%d", &graph->VertexNum);
	/*int turn;*/
	/*for (turn = 1; turn <= graph->VertexNum; turn++)
	{
		scanf_s("%c", &graph->Vertex[turn], MAXNUM);
	}*/
	scanf_s("%s", &graph->Vertex, MAXNUM);
	int turn_x, turn_y;
	for (turn_y = 1; turn_y <= graph->VertexNum; turn_y++)
	{
		for (turn_x = 1; turn_x <= graph->VertexNum; turn_x++)
		{
			scanf_s("%d", &graph->Matrix[turn_y][turn_x]);
			if (graph->Matrix[turn_y][turn_x] == -1)
				graph->Matrix[turn_y][turn_x] = INFINITY;
		}
	}
}

/*得出图的最短路径的函数*/
void Shortest(Graph *graph, char StartNode)
{
	int turn_x, turn_y, StartVex, CurrentVex, MinDest, Final[MAXNUM];
	StartVex = 0;
	CurrentVex = 0;
	for (turn_y = 0; turn_y <= graph->VertexNum; turn_y++)
	{
		if (graph->Vertex[turn_y] == StartNode)
		{
			StartVex = turn_y + 1;
			break;
		}
	}
	for (turn_y = 1; turn_y <= graph->VertexNum; turn_y++)
	{
		path[turn_y][0] = 0;
		dest[turn_y] = INFINITY;
		if (graph->Matrix[StartVex][turn_y] < 100)
		{
			dest[turn_y] = graph->Matrix[StartVex][turn_y];
			path[turn_y][1] = graph->Vertex[StartVex - 1];
			path[turn_y][2] = graph->Vertex[turn_y - 1];
			path[turn_y][0] = 2;
		}
		Final[turn_y] = 0;
	}
	dest[StartVex] = 0;
	Final[StartVex] = 1;
	for (turn_y = 1; turn_y <= graph->VertexNum; turn_y++)
	{
		MinDest = INFINITY;
		for (turn_x = 1; turn_x <= graph->VertexNum; turn_x++)
		{
			if (Final[turn_x] == 0)
			{
				if (dest[turn_x] < MinDest)
				{
					CurrentVex = turn_x;
					MinDest = dest[turn_x];
				}
			}
		}
		Final[CurrentVex] = 1;
		for (turn_x = 1; turn_x <= graph->VertexNum; turn_x++)
		{
			if ((Final[turn_x] == 0) && (MinDest + graph->Matrix[CurrentVex][turn_x] < dest[turn_x]))
			{
				dest[turn_x] = MinDest + graph->Matrix[CurrentVex][turn_x];
				for (int m = 0; m <= path[CurrentVex][0]; m++)
					path[turn_x][m] = path[CurrentVex][m];
				path[turn_x][0]++;
				path[turn_x][path[turn_x][0]] = graph->Vertex[turn_x-1];
			}
		}
	}
}

/*显示最短路径*/
void ShowPath(Graph *graph)
{
	int x, y;
	for (y = 1; y <= graph->VertexNum; y++)
	{
		printf("%c(%d)", graph->Vertex[y-1], dest[y]);
		if (path[y][0] > 0)
		{
			for (x = 1; x <= path[y][0]; x++)
				printf(" %c", path[y][x]);
			printf(" %c", path[y][x]);
			
		}
		printf("\n");
	}
}