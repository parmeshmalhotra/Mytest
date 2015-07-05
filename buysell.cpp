#include<iostream>
using namespace std;

void maxDrawdown(int s[],int sz,int &peak,int &trough)
{
	int max=0;
	int maxDiff=0;
	peak=trough=0;

	for (int i=0;i<sz;i++)
	{
		if (s[max]< s[i])
		{
			max=i;
		}// Recording the high marks
		int diff = s[max]-s[i];
		if (diff>maxDiff)
		{
			peak=max;
			trough=i;
			maxDiff=diff;
		}

	}
}





void Best(int s[],int sz, int &buy,int &sell)
{
	int min=0;
	int maxDiff=0;
	buy=sell=0;

	for (int i=0;i<sz;i++)
	{

		if (s[i]<s[min])
		{
			min=i;
		}
		int diff = s[i]-s[min];
		if (diff>maxDiff)
		{
			buy=min;
			sell=i;
			maxDiff=diff;
		}
	}

}

int main()
{
 int buy,sell,peak,trough;
 int a[10]= {40,32,43,43,56,45,61,45,42,53};
 Best(a,10,buy,sell);
 maxDrawdown(a,10,peak,trough);
 cout<<"Buy at"<<a[buy]<<"\n";
 cout<<"Sell at"<<a[sell]<<"\n";
 cout<<"Peak at"<<a[peak]<<"\n";
 cout<<"Trough at"<<a[trough]<<"\n";
}
