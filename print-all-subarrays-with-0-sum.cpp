#include <bits/stdc++.h>
using namespace std;

void PrintSub0Sum(int arr[],int size)
{
	int sum=0;
	// Pick starting point
    for (int i=0; i<size; i++)
    {
        // Pick ending point
        for (int j=i; j<size; j++)
        {
        	//find sum between starting and ending point
        	sum=sum+arr[j];
        	
            // Print subarray between current starting and ending points if sum is 0
            //NOTE: Print kiya nhi bcoz TC O(n^3) jo jaata
            if(sum==0)
            {
            	cout<<"\n There exists subarray between sum 0 from index "<<i<<" to index "<<j;
			}
        }
        sum=0;
    }
}

int main()
{
	//static inputs
	int size=11;
	int arr[size] = {6, 3, -1, -3, 4, -2, 2,4, 6, -12, -7};
	
	cout<<"\n";
	PrintSub0Sum(arr,size);
	
	return 0;
}
