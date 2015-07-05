#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include <ctime>
#include<string>
using namespace std;

template <class Item>
//To Swap a and b
void exch( Item &a, Item &b)
{
Item temp = a;
a=b;
b=temp;
}

//Algorithms in C++, Robert Sedgewick
template <class Item>
void fixDown(Item a[], size_t k, size_t N)
{
	while(2*k<=N)
	{
		size_t j = 2*k;
		if (j<N && (a[j]<a[j+1]))
		{
				j++;
		}
		if (!(a[k]<a[j])) break;
		exch(a[k],a[j]);
		k=j;
	}
}


template <class Item>
void heapsort ( Item a[], size_t l, size_t r)
{
        size_t k,N;
	N=r-l+1;
	Item *pq=a+l-1;
	
	double elapsed_secs;
	//Construction Phase
	std::clock_t begin = clock();
	for (k=N/2;k>=1;k--)
	{
		fixDown(pq,k,N);
	}
	std::clock_t end = clock();
	elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
        cout<<"Construction Time: "<<elapsed_secs;
	cout<<endl;

	while (N>1)
	{
		exch(pq[1],pq[N]);
		fixDown(pq,1,--N);
	}
}





int main ( int argc, char* argv[])
{
	if (argc<2)
	{
	// Taking the shuffled inputs from random sample heap.*
		cout<<"Enter files heap.* as argv1\n";
		exit(0);
	}
	string data1 = argv[1];
	size_t p = data1.find(".");
	string sub = data1.substr(p+1);
	size_t N;
	istringstream iss1(sub);
	iss1>>N;
	double elapsed_secs;
        ifstream fin1;	
	fin1.open(data1.c_str());
	size_t a[N];
	if (fin1.is_open())
	{
		string line;
		size_t value;
		size_t i=0;
		while (getline(fin1,line))
		{
			istringstream iss(line);
			iss>>value;
			a[i]=value;
			i++;
		}
		fin1.close();
	}

	
	
	std::clock_t begin = clock();
	heapsort(a,0,N-1);
	std::clock_t end = clock();
	string sortedfile="sorteddata"+sub;
	ofstream fout1;
	fout1.open(sortedfile.c_str());
	if (fout1.is_open())
	{
		for (size_t i=0;i<N;i++)
		{
			fout1<<a[i]<<endl;
		}
		fout1.close();
	}
	elapsed_secs = double(end - begin)/ CLOCKS_PER_SEC;
        cout<<"Sorting Time: "<<elapsed_secs;
	cout<<endl;
	return 0;
}
