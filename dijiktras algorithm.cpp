#include<iostream>
#include<vector>
#include<limits>
#include<iomanip>

using namespace std; 

int graph[100][100];

void init()
{
	int graph_size = 100;
	for(int i=0;i<graph_size;i++)
	{
		for(int j=0;j<graph_size;j++)
		{
			graph[i][j]=0;
		}
	}
}

int find_min_dest(int dest[], bool visited[], int total_node){
	int min_dest = 9999;
	int min_index = -1;
	for(int m=0;m<total_node;m++)
	{
		if(!visited[m] && dest[m] < min_dest)
		{
			min_dest = dest[m];
			min_index = m;
		}
	}
	return min_index;
}

//void output(int dest[],int total_nodes)
//{
//	cout<<"\n\n";
//	cout<<"----------------------------------------------------"<<endl<<endl;
//	cout<<setw(10)<<"vertex"<<"\t\t"<<"distance from source"<<endl;
//	for(int i=0;i<total_nodes;i++)
//	{
//		cout<<setw(10)<<i<<setw(20)<<dest[i]<<endl;
//	}
//}

void dijkstras(int start, int total_nodes){
	int dest[total_nodes]={9999};
	bool visited[total_nodes] = {false};
	dest[start] = 0;
	
	for(int count =0; count<total_nodes-1;count++){
		int min = find_min_dest(dest, visited, total_nodes);
		visited[min] = true;
		
		for(int k=0;k< total_nodes -1;k++)
		{
			if(!visited[k] && graph[min][k] && dest[min] != 9999 && dest[min] + graph[min][k] < dest[k])
			{
				dest[k] = dest[min] + graph[min][k];
			}
		}
	//	output(dest,total_nodes);
	cout<<"\n\n";
	cout<<"----------------------------------------------------"<<endl<<endl;
	cout<<setw(10)<<"vertex"<<"\t\t"<<"distance from source"<<endl;
	for(int i=0;i<total_nodes;i++)
	{
		cout<<setw(10)<<i<<setw(20)<<dest[i]<<endl;
	}
	}
}

int main(){
	int n,src,dest,cost,start;
	cout<<"Enter total number of nodes: ";
	cin>>n;
	if(n>100){
		cout<<" [WARNING] NUMBER OF NODES CAN'T BE MORE THAN 100!!! "<<endl;
		cout<<" total number of nodes are automatically set to 100."<<endl;
		n=100;
	}
	cout<<endl<<"------------------------------"<<endl<<endl;
	cout<<endl<<endl<<"ENTER SOURCE AND DESTINATION:: "<<endl<<endl;
	int edge =0 ;
	init();
	int i=0;
	while(1)
	{
		cout<<"FOR EDGE "<<edge+1<<":"<<endl;
		cout<<setw(15)<<"src: ";
		cin>>src;
		if(src<0) break;
		cout<<setw(15)<<"dest. ";
		cin>>dest;
		if(dest<0)
		{
			break;
		 } 
		cout<<setw(15)<<"cost: ";
		cin>>cost;
		if(cost<0) 
		{
			break;
		}
		
		if(src == dest) {
			cout<<"self loop is not allowed."<<endl;
		}
		graph[src][dest]=cost;
		graph[dest][src]=cost;
		edge++;
		
	}
	cout<<"ENTER STARTING NODE: ";
	cin>>start;
	
	dijkstras(start,n);
	
}
