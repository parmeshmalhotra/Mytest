#include<iostream>
#include<vector>
using namespace std;

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
/*
a=a+b; 6 4
b=a-b;
a=a-b;
*/

void bubblesort(vector<int>& a) //O(n^2) stable
{
 for (int i=0;i<a.size();i++)
  {
   for (int j=0;j<a.size()-1;j++)
    {
         if (a[j] > a[j+1])
          {
             swap(a[j],a[j+1]); // scanning through the array and swapping the larger element to the end.
          }
     }
  }
}

void selectionsort(vector<int>& a) //O(n^2) slightly faster than bubble though
{
 for (int i=0;i<(a.size()-1);i++)
  {
     int min=i;
   for (int j=i+1;j<a.size();j++)
     { 
       if( a[i]>a[j]) //compare each element with every other proceeding element
        { 
         min=j;
        }
     }
     swap(a[i],a[min]);
  }

}

void insertionsort(vector<int>& a)
{

 for (int i=1;i<a.size();i++)
  { 
   int  j=i; //insert a[i] into correct location
    while(j>0 && ( a[j]<a[j-1]))
      {
        swap(a[j],a[j-1]);
        j--;
      } 
  }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


// The partition function
int partition(int* input, int p, int r)
{
    int pivot = input[r];

    while ( p < r )
    {
        while ( input[p] < pivot )
            p++;

        while ( input[r] > pivot )
            r--;

        if ( input[p] == input[r] )
            p++;
        else if ( p < r )
        {
            int tmp = input[p];
            input[p] = input[r];
            input[r] = tmp;
        }
    }

    return r;
}

// The quicksort recursive function
void quicksort(int* input, int p, int r)
{
    if ( p < r )
    {
        int j = partition(input, p, r);        
        quicksort(input, p, j-1);
        quicksort(input, j+1, r);
    }
}

void printing( vector<int>& a)
{

 for (int i=0;i<a.size();i++)
  {
   cout<<a[i]<<endl;
  }
}

int main()
{

vector<int> a = {1,2,4,3,5,9,7};
insertionsort(a);
printing(a);
}
