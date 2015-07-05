#include<iostream>
#include<fstream>
#include<sstream>
#include<unordered_set>
#include<map>
#include<stack>
#include<queue>
#include <ctime>

using namespace std;


typedef std::multimap<int,int> Graph;


void BFS(Graph g,int node)
{
	unordered_set<int> visited;
	queue<int> q;
	q.push(node);
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		unordered_set<int>::const_iterator got= visited.find(curr);
		if (got == visited.end())
		{
			//Visit the node	 
			visited.insert(curr);
		//	cout<<"=>"<<curr;// To create a Spanning Tree
		}
		pair<Graph::iterator,Graph::iterator> ret;
		ret = g.equal_range(curr);
		Graph::iterator it;
		for (it=ret.first;it!=ret.second;++it)
		{        
			if (visited.find(it->second) == visited.end())
			{
				q.push(it->second);
			}
		}
	}
        //To check whether graph is connected or not
	cout<<endl;
	Graph::iterator it1;
	for (it1=g.begin();it1!=g.end();it1=g.upper_bound(it1->first))
	{
		if (visited.find(it1->first) == visited.end())
		{
			cout<< "Graph is not Connected\n";
			break;
		}
	}
        cout<<endl;
}
 
void DFS(Graph g,int node)
{
	unordered_set<int> visited;
	stack<int> stk;
	stk.push(node);
	while(!stk.empty())
	{
		int curr = stk.top();
		stk.pop();
		unordered_set<int>::const_iterator got= visited.find(curr);
		if (got == visited.end())
		{
			//Visit the node	 
			visited.insert(curr);
		//	cout<<"=>"<<curr;//Print a Spanning Tree
		}
		pair<Graph::iterator,Graph::iterator> ret;
		ret = g.equal_range(curr);
		Graph::iterator it;
		for (it=ret.first;it!=ret.second;++it)
		{        
			if (visited.find(it->second) == visited.end())
			{
				stk.push(it->second);
			}
		}
	}
        //To check whether graph is connected or not
	cout<<endl;
	Graph::iterator it1;
	for (it1=g.begin();it1!=g.end();it1=g.upper_bound(it1->first))
	{
		if (visited.find(it1->first) == visited.end())
		{
			cout<< "Graph is not Connected\n";
			break;
		}
	}
        cout<<endl;
}
 





void creategraph(char* filename)
{
	Graph g;
	ifstream fin;
	string line;
	string delimiter = " ";
	fin.open(filename);
	if (fin.is_open())
	{ 
	  getline(fin,line); // Don't need vertices count
          getline(fin,line);// Don't need edges count
		while( getline(fin,line))
		{
			istringstream iss(line);
			int key,value,weight;
			iss>>key;
			iss>>value;
                        iss>>weight;
			g.insert( pair<int ,int>(key,value));
		}
		fin.close();
	}
	Graph::iterator it1;
	it1=g.begin();
	cout<<"Enter DFS or BFS to see the traversal: ";
	string input;
	cin>>input;
	double elapsed_secs;
	if (input =="BFS")
	{
		std::clock_t begin = clock();
		BFS(g,it1->first);
		std::clock_t end = clock();
		elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
	}
	else if (input == "DFS")
	{
		std::clock_t begin = clock();
		DFS(g,it1->first);
		std::clock_t end = clock();
		elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
	}
	else 
	{
		cout<<"Please enter BFS or DFS only";
		exit(0);
	}
	cout<<endl<<"Elapsed Seconds"<<elapsed_secs<<endl;	
/* To view the graph in adjacency list format
	Graph::iterator it2;
        pair <Graph::iterator, Graph::iterator> ret;
 
        cout<<endl<<endl;
	cout<<"Adjacency list";
	cout<<endl;
	for(it1=g.begin();it1!=g.end();it1=g.upper_bound(it1->first))
	{
		cout << it1->first << "=>";
		ret = g.equal_range(it1->first);
                for (it2=ret.first;it2!=ret.second;++it2)
		{
			cout<<it2->second<<",";
		}
		cout<<endl;
	}	
 */
}


int main ( int argc, char* argv[])
{
	if (argc<2)
	{
		cout<<"Enter file to generate graph in commandline\n";
	}
	char * filename = argv[1];
	creategraph(filename);
	return 0;
}
