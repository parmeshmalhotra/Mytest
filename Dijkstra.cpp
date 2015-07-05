#include <stdio.h>
#include <limits.h>
#include <string>
#include <fstream> 
#include <sstream> 
#include <iostream>
// Number of vertices in the graph
//#define V 9
using namespace std;
int V,E;
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(float dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed distance array
void printSolution(float dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < n; i++)
      printf("%d \t\t %f\n", i, dist[i]);
}
 
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(float graph[8][8], int src)
{
     float dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
 
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
 
     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
 
       // Mark the picked vertex as processed
       sptSet[u] = true;
 
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
 
     // print the constructed distance array
     printSolution(dist, V);
}

// driver program to test above function
int main(int argc, char **argv)
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
    int v1;
    int v2;
    float w;
    getline(f,line);
    istringstream iss1(line);
    iss1>>V;
    getline(f,line);
    istringstream iss2(line);
    float graph[8][8];
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





   /* Let us create the example graph discussed above */
/*   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
*/ 
    dijkstra(graph, 0);
 
    return 0;
}
 
