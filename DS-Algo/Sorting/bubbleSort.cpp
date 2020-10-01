/*
Bubble Sort: 
Here we compare each element with an element next to it, if prev element is samller we swap both of them. 
Thus by doing this we make largest element to sit at the end of the loop in the first iteration 
and similarly in 'n-1' iteration every element is at its correct position.

Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

Sorting In Place: Yes

Stable: Yes

Time: O(n^2)
*/


#include <bits/stdc++.h>
using namespace std;

void swapp(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void bubble_sort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n-1-i;j++) // last i elements are already sorted therefore, '-i'.
        {
            if(arr[j] > arr[j+1])
                swapp(arr[j], arr[j+1]);
        }
    }
}

int main()
{
    int arr[] = {9,4,2,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);

    // Print
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}