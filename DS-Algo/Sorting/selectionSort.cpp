/*
Selection Sort: 
Here we are at ith position and consider it as minimum found till now. Now we run a loop j from i+1 and check if jth element is less than ith one. 
If this is so, then we update min to jth element. Finally we swap smallest element with ith element and we move forward. So the smallest elment comes to the first place always. Similar to bubble sorting which largest element came to the last position after 1st iteration.

Sorting In Place: Yes

Stable: No

Time: O(n^2)
*/


#include <bits/stdc++.h>
using namespace std;

void swapp(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int arr[], int n)
{
    int min_idx;
    for(int i=0;i<n-1;i++)
    {
        min_idx = i; // min_idx is pointing to ith position
        for(int j = i+1;j<n;j++) // First i elements are already sorted therefore, 'i+1'.
        {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        
        swapp(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int arr[] = {9,4,2,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,n);

    // Print
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}