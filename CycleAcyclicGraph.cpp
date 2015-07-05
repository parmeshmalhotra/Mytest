#include <cstdlib>
#include <iostream>
#include <fstream>
#include <list>
#include <time.h>
#include <string> 
#include <sstream>
using namespace std;
 

int V, E;
list<int> *adj = new list<int>[250];
bool *visited = new bool[250];


void newEdge(int v1, int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}
 
bool DFS(int v, bool visited[], int parent)
{
    visited[v] = true;
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[*i])
        {
           if (DFS(*i, visited, v))
              return true;
        }
 
        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (*i != parent)
        {
           return true;
        }
    }
    return false;
}


bool isAcyclic()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    for (int u = 0; u < V; u++)
// Call the recursive helper function to detect cycle in different DFS trees
        if (!visited[u] && DFS(u, visited, -1))
            return true;
 
    return false;
} 

int main(int argc, char **argv)
{
    int v1, v2;
    float w;
    if (argc<2)
    {
	    cout<<"Enter file to check  as argv1\n";
	    exit(0);
    }
    string filename= argv[1];
    ifstream f;
    f.open(filename.c_str());
	if (f.is_open())
	{
		string line;
		int v1;
		int v2;
                float w;
                getline(f,line);
                istringstream iss1(line);
                iss1>>V;
                getline(f,line);
                istringstream iss2(line);
                iss2>>E; 
             //   std::cout << "V is " <<V<<" E is "<<E<<endl; 
		while (getline(f,line))
		{
			istringstream iss(line);
			iss>>v1;
			iss>>v2;
			iss>>w;
                       // std::cout<<"Vertex1  "<<v1<<" Vertex2  "<<v2<<endl;
                        newEdge(v1, v2);
		}
		f.close();
	}
        
   
    if(isAcyclic())
        cout << "\nGraph contains a cycle\n";
    else
        cout << "\nGraph doesn't contain a cycle\n";
    
    return 0;
}




