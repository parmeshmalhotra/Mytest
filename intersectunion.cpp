/* Write a program to find intersection of 2 arrays and union of two arrays
a= (1,2,3,4,5,6)
b=(4,5,3,8,9)

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

template<typename T>
vector<T> intersect (vector<T>& a, vector<T>& b)
{
	T i=0;
	T j=0;
	T k=0;
	vector<T> c;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	while ((i< a.size()) and (j<b.size()))
	{
		if (a[i]<b[j])
		{
			i++;
		}
		if (b[j]<a[i])
		{
			j++;
		}
		if(a[i]==b[j])
		{
			c.push_back(a[i]);
			i++;
			j++;
		}
	}
 return c;
}

template<typename T>
vector<T> dounion(vector<T> a,vector<T> b)
{
 T i=0;
 T j=0;
 T k=0;
	vector<T> c;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	while ((i< a.size()) and (j<b.size()))
	{
          	
		if (a[i]<b[j])
		{
			c.push_back(a[i]);
			i++;
		}
		if (b[j]<a[i])
		{
			c.push_back(b[j]);
			j++;
		}
		if(a[i]==b[j])
		{
			c.push_back(a[i]);
			i++;
			j++;
		}
	}
 return c;
}
 




int main()
{

vector<int> a = {1,2,3,4,5,6};
vector<int> b = {4,5,3,8,9};
vector<int> c;
vector<int> d;
c= intersect(a,b);
d= dounion(a,b);
for (int i=0;i<d.size();i++)
{
cout<<d[i]<<endl;
}

//d= dounion(a,b);

}
