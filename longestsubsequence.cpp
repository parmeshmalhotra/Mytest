#include<iostream>
#include<vector>

using namespace std;

int max (int a ,int b)
{
if (a>b)
 return a;
else
 return b;
}

int main()
{
	vector<int> a={ 1, 3, 2, 4, 3, 5, 4, 6 }; 
//	vector<int> a = { 10, 22, 9, 18, 21, 50, 41, 60, 80 } ;
        int large=0;
        vector<int> l;
        for (int k=0;k<a.size();k++)
         {
          l.push_back(1);
         }
 
	for (int i=1;i<a.size();i++)
	{
	 for (int j=0;j<i;j++)
          {
               if (a[j]<a[i]) 
                  {
                   l[i] = max(l[i],l[j]+1);
                  }
          }   
	}
      
       for (int k=0;k<a.size();k++)
         {
          if (large<l[k])
              {large = l[k];}
         }
        cout <<"Longest subsequence length" <<large<<"\n";
}
