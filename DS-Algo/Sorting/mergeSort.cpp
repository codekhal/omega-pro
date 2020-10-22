/*
Merge Sort:
Using the Divide and Conquer technique, we divide a problem into subproblems. 
When the solution to each subproblem is ready, we 'combine' the results from the subproblems to solve the main problem.
*/

#include <bits/stdc++.h>
using namespace std;


void merge2sorted(int arr[], int start, int mid, int end)
{
 // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = mid - start + 1;
  int n2 = end - mid;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[start + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[mid + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = start;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }

}

void mergeSort(int arr[], int start, int end)
{
    if(start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge2sorted(arr, start, mid, end);
    }
}

int main()
{
    int arr[] = {5,2,9,1,3};

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}