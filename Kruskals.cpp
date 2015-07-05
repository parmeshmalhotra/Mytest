#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream> 
using namespace std;
//Structure of Edge

struct Edge
{
    int src, dest;
    float weight;
};
//Structure of graph
struct Graph
{
    int V, E;
    struct Edge* edge;
};
 //Creating graph
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
struct subset
{
    int parent;
    int rank;
};
 //Function to find
int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 //Function for Union
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
 //Kruskal main Function
void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
 
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );
 
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    while (e < V - 1)
    {
        struct Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
 
/*    
    cout << "Following are the edges in the constructed MST\n";
    for (i = 0; i < e; ++i)
     cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
*/
    return;
}
 
int main(int argc, char **argv)
{
    
    int v1, v2;
    float w,V,E;
    if (argc<2)
    {
	    cout<<"Enter file to check  as argv1\n";
	    exit(0);
    }
    string filename= argv[1];
    ifstream f;
    f.open(filename.c_str());
    string line;
    int i=0;
    getline(f,line);
    istringstream iss1(line);
    iss1>>V;
    getline(f,line);
    istringstream iss2(line);
    iss2>>E; 
    struct Graph* graph = createGraph(V, E);
//    std::cout << "V is " <<V<<" E is "<<E<<endl; 
    while (getline(f,line))
    {
	    istringstream iss(line);
	    iss>>v1;
	    iss>>v2;
	    iss>>w;
	    graph->edge[i].src = v1;
	    graph->edge[i].dest = v2;
	    graph->edge[i].weight = w;
	    i++;
    }
    f.close();
    clock_t tStart = clock();
    KruskalMST(graph);
    cout << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
    return 0;
}
