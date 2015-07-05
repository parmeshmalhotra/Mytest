#include <stdio.h>
#include <limits.h>
#include <fstream>
#include <iostream>
#include <time.h>
#include <sstream>
using namespace std;
//Function to find minimum key
int minKey(int key[], bool mstSet[],int V)
{
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 //Function to print Minimum Spanning tree
int printMST(int parent[], int n, float graph[250][250])
{
   cout << "Edge Weight\n";
   for (int i = 1; i < n; i++)
      cout << parent[i] << " - " << i << "   " << graph[i][parent[i]] << endl;
   
   return 0;
}
 //Function for Prim algorithm
void primMST(float graph[250][250], int V)
{
     int parent[V];
     int key[V];
     bool mstSet[V];
 
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     key[0] = 0;
     parent[0] = -1;
 
     for (int count = 0; count < V-1; count++)
     {
        int u = minKey(key, mstSet,V);
 
        mstSet[u] = true;
 
        for (int v = 0; v < V; v++)
           if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
               parent[v]  = u, key[v] = graph[u][v];
     }
     
//     printMST(parent, V, graph);
} 
 
int main(int argc,char **argv)
{
    if (argc<2)
    {
	    cout<<"Enter file to check  as argv1\n";
	    exit(0);
    }
    string filename= argv[1];
    ifstream f;
    f.open(filename.c_str());

    string line;
    int v1,E,V;
    int v2;
    float w;
    getline(f,line);
    istringstream iss1(line);
    iss1>>V;
    getline(f,line);
    istringstream iss2(line);
    float graph[250][250];
    iss2>>E; 
//    std::cout << "V is " <<V<<" E is "<<E<<endl; 
    while (getline(f,line))
    {
	    istringstream iss(line);
	    iss>>v1;
	    iss>>v2;
	    iss>>w;
	    // std::cout<<"Vertex1  "<<v1<<" Vertex2  "<<v2<<endl;
            graph[v1][v2] = graph[v2][v1] = w;
    }
    f.close();

    clock_t tStart = clock();
   primMST(graph,V);
   cout << (double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;
 
    return 0;
}



