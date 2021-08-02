/*
Approach: The idea is to store the sum of elements of every prefix of the array in a hashmap, i.e, every 
index stores the sum of elements up to that index hashmap. So to check if there is a subarray with a sum equal to s, 
check for every index i, and sum up to that index as x. 
If there is a prefix with a sum equal to x – s, then the subarray with the given sum is found. 

Algo

Create a Hashmap (hm) to store a key-value pair, i.e, key = prefix sum and value = its index, and a variable to store 
the current sum (sum = 0) and the sum of the subarray as s

Traverse through the array from start to end.

For every element update the sum, i.e sum = sum + array[i]

If the sum is equal to s then print that the subarray with the given sum is from 0 to i

If there is any key in the HashMap which is equal to sum – s then print that the subarray with the given sum is 
from hm[sum – s] to i

Put the sum and index in the hashmap as a key-value pair.

*/


#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to print subarray with sum as given sum
void subArraySum(int arr[], int n, int sum)
{
    // create an empty map
    unordered_map<int, int> map;
 
    // Maintains sum of elements so far
    int curr_sum = 0;
 
    for (int i = 0; i < n; i++)
    {
        // add current element to curr_sum
        curr_sum = curr_sum + arr[i];
 
        // if curr_sum is equal to target sum
        // we found a subarray starting from index 0
        // and ending at index i
        if (curr_sum == sum)
        {
            cout << "Sum found between indexes "
                 << 0 << " to " << i << endl;
            return;
        }
 
        // If curr_sum - sum already exists in map
        // we have found a subarray with target sum
        if (map.find(curr_sum - sum) != map.end())
        {
            cout << "Sum found between indexes "
                 << map[curr_sum - sum] + 1
                 << " to " << i << endl;
            return;
        }
 
        map[curr_sum] = i;
    }
 
    // If we reach here, then no subarray exists
    cout << "No subarray with given sum exists";
}
int main()
{
    int arr[] = {10, 2, -2, -20, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = -10;
 
    subArraySum(arr, n, sum);
 
    return 0;
}
