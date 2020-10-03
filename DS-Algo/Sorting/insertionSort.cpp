/*
Insertion Sort: 
Even though insertion sort is efficient, still, if we provide an already sorted array to the insertion sort algorithm, it will still execute the outer for loop, 
thereby requiring n steps to sort an already sorted array of n elements, 
which makes its best case time complexity a linear function of n.
The analogy can be understood from the style we arrange a deck of cards. 
This sort works on the principle of inserting an element at a particular position, 
hence the name Insertion Sort

Sorting In Place: Yes

Stable: Yes

Worst Time: O(n^2)
Best Time: O(n)
*/


#include <bits/stdc++.h>
using namespace std;

void swapp(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertion_sort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j = i-1;j>=0;j--) // First i elements are already sorted therefore, 'i+1'.
        {
            if(arr[j+1] < arr[j])
                swapp(&arr[j], & arr[j+1]);
            else
            {
                break;
            }
            
        }
    }
}

int main()
{
    int arr[] = {9,4,2,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);

    // Print
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}