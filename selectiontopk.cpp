#include<iostream>
#include<vector>
using namespace std;

void swap( int &a,int &b)
{
int c=a;
a=b;
b=c;
}

void selection(vector<int> &a,int k)
{
 int min;
 for (int i=0;i<k;i++)
  {
    min=i;
   for (int j=i+1;j<a.size();j++)
    {
       if (a[min]>a[j])
         {
             min=j;
         }
     }
   swap(a[i],a[min]);
  }    
for (int i=0;i<k;i++)
{
  cout<<a[i]<<"\n";
}
}

void display(vector<int> a,int k)
{
for (int i=0;i<a.size();i++)
{
  cout<<a[i]<<"\n";
}
}


int main()
{

vector<int> a={4,5,6,3,1,2,8};
int k=3;
selection(a,k);
//display(a,k);
}

