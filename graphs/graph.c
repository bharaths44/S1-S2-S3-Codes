#include<stdio.h>
#define n 6
int graph[n][n];
int visit[n],q[100],r=-1,f=0;

void init(int arr[][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			arr[i][j]=0;
	}
}

void addEdge(int arr[][n],int s,int d)
{
	arr[s][d]=1;
	arr[d][s]=1;
}

void printGraph(int arr[][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf(" %d ",arr[i][j]);
		printf("\n");
	}
}

void dfs(int i)
{
	int j;
	printf("%d ",i);
	visit[i]=1;
	for(j=0;j<n;j++)
	{
		if(!visit[j] && graph[i][j]==1)
			dfs(j);
	}
}

void bfs(int i)
{
	
	int j;
	if(!visit[i])
		printf("%d ",i);
	visit[i]=1;
	for(j=0;j<n;j++)
	{
		if(!visit[j] && graph[i][j]==1)
			q[++r]=j;
	}
	if(f<=r)
	{
		bfs(q[f++]);
		
	}
}
void main()
{
	init(graph);
	for(int i=0;i<n;i++)
		visit[i]=0;
	
	addEdge(graph,0,1);
	addEdge(graph,0,3);
	addEdge(graph,0,4);
	addEdge(graph,1,2);
	addEdge(graph,2,5);
	addEdge(graph,4,5);
	addEdge(graph,3,4);
	printf("The graph represented by adjacent matrix :\n");
	printGraph(graph);
	printf("\n");
	printf("The Breadth-First Traversal of the graph is :\n");
	bfs(0);
	printf("\n");
	for(int i=0;i<n;i++)
		visit[i]=0;
	printf("The Depth-First Traversal of the graph is :\n");
	dfs(0);
	printf("\n");
}
