// Given n boards of length {A1, A2, .. An} k painters available and each takes 1 unit time to paint 1 unit of board. 
// The problem is to find the minimum time to get this job done under the constraints that 
// any painter will only paint continuous sections of boards
// Using Binary Search which is more efficient as compared with other solution like DP.

int getMax(int arr[], int n) 
{ 
    int max = INT_MIN; 
    for (int i = 0; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
} 
  
int getSum(int arr[], int n) 
{ 
    int total = 0; 
    for (int i = 0; i < n; i++) 
        total += arr[i]; 
    return total; 
} 
  
int numberOfPainters(int arr[], int n, int maxLen) 
{ 
    int total = 0, numPainters = 1; 
  
    for (int i = 0; i < n; i++) { 
        total += arr[i]; 
  
        if (total > maxLen) { 
  
            total = arr[i]; 
            numPainters++; 
        } 
    } 
  
    return numPainters; 
} 
  
int partition(int arr[], int n, int k) 
{ 
    int lo = getMax(arr, n); 
    int hi = getSum(arr, n); 
  
    while (lo < hi) { 
        int mid = lo + (hi - lo) / 2; 
        int requiredPainters = numberOfPainters(arr, n, mid); 
  
        if (requiredPainters <= k) 
            hi = mid; 

        else
            lo = mid + 1; 
    } 
  
    return lo; 
} 