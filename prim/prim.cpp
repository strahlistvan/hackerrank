#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int indexOf(vector<int> my_vector, int value)
{
	for (int i=0; i<my_vector.size(); ++i)
	{
		if (my_vector[i] == value)
		{
			cout<<"talalat: "<<value<<" az "<<i<<". helyen.";
			return i;
		}
	}
   return -1;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int G[5][5] = {{0, 3, 4, 0, 0},
               {0, 0, 5, 0, 0},
               {0, 0, 0, 0, 7},
               {0, 6, 0, 0, 0},
               {0, 2, 0, 0, 0} };
	
	int starter = 0;

    vector<int> vertices, tree_vert;
	vector< pair<int, int> > edges, tree_edges;
	
	//initialize vertex and egde lists
	for (int row=0; row<5; ++row)
	{
		vertices.push_back(row);
		for (int col=0; col<5; ++col)
		{
	
			if (G[row][col]!=0)
			{
				edges.push_back(pair<int,int>(row, col));
			}
		}
	} 
	
	//test
	for (int i=0; i<edges.size(); ++i)
		cout<<"{"<<edges[i].first+1<<","<<edges[i].second+1<<"}"<<endl;
   
   
   /* TODO: continue algorithm */
   tree_vert.push_back(starter);

   int min = 0;
   
   while (vertices != tree_vert)
   {
	 
	   for (int i=0; i<5; ++i)
	   {
		   for (int j=0; j<5; ++j)
		   {   
			   if (G[i][j]!=0)
				{
					if (G[i][j] <= min)
					{
							 cout<<"dasdf"<<endl;
						if ((indexOf(tree_vert, i)==-1 && indexOf(tree_vert, j)!=-1))
						{
							min = G[i][j];
							pair<int, int> min_edge(i, j);
							tree_edges.push_back(min_edge);
							tree_vert.push_back(i);
						}
						else if ((indexOf(tree_vert, j)==-1 && indexOf(tree_vert, i)!=-1))
						{
							min = G[i][j];
							pair<int, int> min_edge(i, j);
							tree_edges.push_back(min_edge);
							tree_vert.push_back(j);
						}
					}
				}
		   }
	   }
   }
   
    return 0;
}

