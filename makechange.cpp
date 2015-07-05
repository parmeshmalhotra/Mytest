/*
Given infinite number of 25 cents, 10 cents , 5 cents and 1 cents .Calculate number of ways to represent n cents.
*/

#include<iostream>
#include<vector>
using namespace std;


int makechange(int amount, vector<int> denoms, int index)
{
if (index >= (denoms.size() -1)) return 1; // last denom
int denomsAmount = denoms[index];
int ways=0;
for (int i=0;i*denomsAmount<=amount;i++)
{
 int amountRemaining = amount -i * denomsAmount;
 ways+= makechange(amountRemaining, denoms,index+1);
}
return ways;
}

int main()
{
vector<int> denoms = {25,10,5,1};
int n=25;
cout<<makechange(n,denoms,0)<<endl;
}
