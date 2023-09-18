#include<iostream>
#include<climits>

using namespace std;
#define MAX 100
int graph[MAX][MAX];

void takeInput(int vex){
	int src,dest,wht;
	cout<<"Input (src dest wht) : enter -ve value to exit from loop:"<<endl;
	while(true)
	{
		cin>>src;
		if(src<0)
		{
			break;
		}
		cin>>dest>>wht;
		if(wht<0)
		{
			cout<<"dijksta's algorithm may not work for -ve weight."<<endl;
			continue;
		}
		graph[src][dest]=wht;
		
	}
	system("cls");
	cout<<"graph with "<<vex<<" created successfully. "<<endl;
	
}

int minDistance(int dest[],bool visited[],int vex)
{
	int min= INT_MAX,minIndex;
	for(int v=0;v<vex;v++)
	{
		if(!visited[v] && dest[v]<min)
		{
			min = dest[v];
			minIndex  = v;
		}
	}
	return minIndex;
}

void dijkstras(int start,int vex){
	int dist[vex];
	bool visited[vex];
	
	for(int i=0;i<vex;i++)
	{
		dist[i]= INT_MAX;
		visited[i]=false;	
	}
	dist[start]=0;
	for(int count =0;count< vex-1;count++)
	{
		int next = minDistance(dist,visited,vex);
		visited[next]=true;
		
		for(int v=0;v<vex;v++)
		{
			if(!visited[v] && graph[next][v] && dist[next]!= INT_MAX && dist[next]+graph[next][v]<dist[v])
			{
				dist[v]=dist[next]+graph[next][v];
			}
		}
		
	}
	cout<<"vertex \tdistance from source"<<endl;
	for(int i=0;i<vex;i++){
		cout<<i<<"\t"<<dist[i]<<endl;
	}
}

int main(){
	int vex,start;
	
	cout<<"Input total numbers in node in graph: ";
	cin>>vex;
	takeInput(vex);
	cout<<"Enter starting node: ";
	cin>>start;
	dijkstras(start,vex);
	return 0;
}
