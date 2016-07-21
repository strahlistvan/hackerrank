#include <iostream>
#include <fstream>
#include <cstdlib>
#include <deque>
using namespace std;

int N, M; //N = vertices, M = edges
int ** graph; //adjacency matrix
bool * done;  //true if the algorithm visited the vertex
int * path_length; //length of the shortest path to each vertex (from a given start)
deque<int> my_queue; //queue for the vertices

void shortest_path(int starter)
{

	done[starter] = true;
	my_queue.push_back(starter);  //index of vertex
	my_queue.push_back(0);       //'level' of vertex

	path_length[starter] = 0; //shortest starter->starter path = 0
	
	while (!my_queue.empty())
	{	
		int next = my_queue.front();  //next = first element in the queue
		my_queue.pop_front(); //delete first element
		int next_level = my_queue.front();
		my_queue.pop_front();
		
		for (int i=0; i<N; ++i)
		{
			if (graph[next][i]!=0 && !done[i])
			{
				path_length[i]+=6*(next_level+1);  //every edge distance is 6
				done[i] = true;
				my_queue.push_back(i);
				my_queue.push_back(next_level+1);
			}
		}
	}
	
	//if unreachable, -1 (instead of 0)
	for (int i=0; i<N; ++i)
	{
		if (path_length[i]==0 && i!=starter)
			path_length[i] = -1;
	}
}


int main(int argc, char ** argv)
{
	if (argc!=2)
	{
		cerr<<"Missing input argument"<<endl;
		return -1;
	}
	
	ifstream fin(argv[1]);
	
	int test_cases;
	fin >> test_cases;
	
	for (int cases=1; cases<=test_cases; ++cases)
	{
		fin >> N;
		fin >> M;
		graph = (int **) calloc(N, sizeof(int *));
		done = (bool *) calloc(N, sizeof(bool));
		path_length = (int *) calloc(N, sizeof(int));
		
		for (int i=0; i<N; ++i)
			graph[i] = (int *) calloc(N, sizeof(int));
		
		//read edges 
		for (int i=0; i<M; ++i)
		{
			int v1, v2;
			fin >> v1;
			fin >> v2;
			
			graph[v1-1][v2-1] = 1;
		}
		
		int starter;
		fin >> starter;
	//	cout<< starter <<endl;
		
	/*	for (int i=0; i<N; ++i)
		{
			for (int j=0; j<N; ++j)
			{
				cout<<graph[i][j]<<" ";
			}
			cout<<endl;
		}
	*/	
	//	cout<<"the starter: "<<starter<<endl;
		shortest_path(starter-1);
		for (int i=0; i<N; ++i)
		{
			if (i!=starter)
				cout<<path_length[i]<<" ";
		}
		cout<<endl;
		
		free(graph);
		free(done);
		free(path_length);
	}
	
	fin.close();
}
